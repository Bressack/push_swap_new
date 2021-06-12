/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:34:17 by frlindh           #+#    #+#             */
/*   Updated: 2021/05/05 13:26:45 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mmalloc.h>
#include <commons.h>

size_t g_total_malloc = 0;
size_t g_total_size = 0;
size_t g_total_sizefull = 0;

void	print_all_malloc(void)
{
	t_list_malloc	*tmp;
	int				total_malloc;
	int				total_size;
	int				total_sizefull;
	int				total_inuse;

	total_malloc = 0;
	total_size = 0;
	total_sizefull = 0;
	total_inuse = 0;
	tmp = all_malloc(GET, NULL);
	if (tmp)
	{
		if (0)
		{
			printf("\n   %6s   | %20s | %5s | %5s | %8s | %15s | %15s |\n", "STATUS", "function", "line", "size", "sizefull", "data address", "next address");
			printf("---------------------------------------------------------------------------------------------------\n");
		}
		while (tmp)
		{
			if (0)
			{
				printf(" [ %6s ] | %20s | %5d | %5ld | %8ld | %15p | %15p |\n",
					tmp->isfree ? C_G_GREEN"FREE"C_RES : C_G_RED"IN USE"C_RES,
					tmp->f,
					tmp->l,
					tmp->size,
					tmp->sizefull,
					tmp->data,
					tmp->next
				);
			}
			total_malloc++;
			total_size += tmp->size;
			total_sizefull += tmp->sizefull;
			total_inuse += tmp->isfree ? 0 : 1;
			tmp = tmp->next;
		}
	}
	printf("[ LOCAL  ] inuse: [ %d / %d ] | total size: %d | total sizefull: %d | \n", total_inuse, total_malloc, total_size, total_sizefull);
	printf("[ GLOBAL ] total_alloc: %zu | total size: %zu | total sizefull: %zu | \n", g_total_malloc, g_total_size, g_total_sizefull);
}

void	*all_malloc(int opt, t_list_malloc *node)
{
	static t_list_malloc	*all_malloc = NULL;
	// t_list_malloc			*prev;
	t_list_malloc			*tmp;

	if (opt == GET)
		return (all_malloc);
	if (opt == GETADDR)
		return (&all_malloc);
	else if (opt == SET)
		all_malloc = node;
	else if (opt == FREEALL)
	{
		tmp = all_malloc;
		while (tmp)
		{
			if (!tmp->isfree)
				free(tmp->data);
			tmp = tmp->next;
		}
		return (0);
		// while (all_malloc)
		// {
		// 	free(all_malloc->data);
		// 	prev = all_malloc;
		// 	all_malloc = all_malloc->next;
		// 	free(prev);
		// }
		// return (0);
	}
	return (0);
}

void	clean_overload(void)
{
	t_list_malloc	*next;
	t_list_malloc	*tmp;
	int				i;

	tmp = all_malloc(GET, NULL);
	i = 0;
	while (tmp)
	{
		if (tmp->isfree)
			i++;
		tmp = tmp->next;
	}
	if (i > 1000)
	{
		tmp = all_malloc(GET, NULL);
		while (tmp)
		{
			next = tmp->next;
			if (tmp->isfree)
				ft_del_node_np((t_pnp **)all_malloc(GETADDR, NULL), (t_pnp *)tmp, NULL);
			tmp = next;
		}
	}
}

void	*try_malloc(unsigned int size, char *f, int l)
{
	void			*new;
	t_list_malloc	*newnode;

	clean_overload();
	if (!(new = malloc(size + 1)))
	{
		free_all_malloc();
		error("malloc", FATALERR, MALLOC_ALLOCATION, NULL);
		exit(1);
	}
	if (!(newnode = malloc(sizeof(t_list_malloc))))
	{
		free_all_malloc();
		error("malloc", FATALERR, MALLOC_ALLOCATION, NULL);
		exit(1);
	}
	bzero(new, size);
	newnode->data = new;
	newnode->f = f;
	newnode->l = l;
	newnode->size = ((size / 16) + (((float)size / (float)16) - (size / 16)) > 0.5 ? 1 : 0) * 16;
	newnode->sizefull = newnode->size + (((sizeof(t_list_malloc) / 16) + (((float)sizeof(t_list_malloc) / (float)16) - (sizeof(t_list_malloc) / 16)) > 0.5 ? 1 : 0) * 16);
	newnode->isfree = 0;
	g_total_malloc += 1;
	g_total_size += newnode->size;
	g_total_sizefull += newnode->sizefull;
	ft_add_node_end_np((t_pnp **)all_malloc(GETADDR, NULL), (t_pnp *)newnode);
	return (new);
}

int	free_all_malloc(void)
{
	all_malloc(FREEALL, NULL);
	return (0);
}

int	try_free(void **to_free)
{
	// t_list_malloc **indir;
	// t_list_malloc *f;
	t_list_malloc *tmp;

	if (!*to_free)
		return (0);
	tmp = all_malloc(GET, NULL);
	while (tmp && tmp->data != *to_free)
		tmp = tmp->next;
	if (!tmp)
		return (-1);
	else
	{
		free(tmp->data);
		tmp->isfree = 1;
		*to_free = NULL;
	}
	// indir = (t_list_malloc **)all_malloc(GETADDR, NULL);
	// while (*indir && (*indir)->data != *to_free)
	// 	indir = &((*indir)->next);
	// f = *indir;
	// if (f)
	// {
	// 	*indir = (*indir)->next;
	// 	free(f->data);
	// }
	// free(f);
	// *to_free = NULL;
	return (0);
}
