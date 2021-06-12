/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:16:58 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/12 17:34:35 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

int				get_size_stack(t_stack *s)
{
	int			i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

double	*get_sorted_tab(t_stack *s)
{
	double		*tab;
	t_stack		*tmp;
	int			i;
	int			len;

	len = get_size_stack(s);
	if (!len)
		return (NULL);
	tab = try_malloc(sizeof(double) * len);
	tmp = s;
	i = 0;
	while (tmp && i < len)
	{
		tab[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	quicksort(tab, len, 0);
	return (tab);
}

void	apply_index(t_all *all)
{
	double		*tab;
	t_stack		*tmp;
	int			i;

	tab = get_sorted_tab(all->a);
	i = 0;
	while (i < all->stacklen)
	{
		tmp = all->a;
		while (tmp)
		{
			if (tmp->value == tab[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	try_free((void **)&tab);
}

int		handle_one_str(t_all *all, char *s)
{
	long	n;
	t_stack	*new;

	if (!strlen(s) || strlen(s) > 11 || isnumber(s) == FAILURE)
		return (error(all->bin, ERR, INVALID_NUMBER, s));
	n = ft_atol(s);
	if (n > INT_MAX || n < INT_MIN)
		return (error(all->bin, ERR, NUMBER_OUT_OF_INTEGER_RANGE, s));
	new = try_malloc(sizeof(t_stack));
	new->value = (int)n;
	ft_add_node_end_np((t_pnp **)&all->a, (t_pnp *)new);
	all->stacklen++;
	if (all->min > n)
		all->min = n;
	if (all->max < n)
		all->max = n;
	return (SUCCESS);
}

int		search_doublons(t_all *all)
{
	struct s_stack	*tmp;
	struct s_stack	*tmp2;
	char			*n;

	tmp = all->a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
			{
				n = ft_itoa(tmp->value);
				error(all->bin, ERR, NUMBER_ALREADY_IN_STACK, n);
				try_free((void **)&n);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

void	get_stack(t_all *all, int ac, char **av)
{
	int		i;
	int		j;
	char	**split;

	all->min = INT_MAX;
	all->max = INT_MIN;
	i = 1;
	while (i < ac)
	{
		split = ft_strsplit(av[i], ' ');
		j = 0;
		while (split[j])
		{
			handle_one_str(all, split[j]);
			try_free((void **)&split[j]);
			j++;
		}
		try_free((void **)&split);
		i++;
	}
	search_doublons(all);
	apply_index(all);
}