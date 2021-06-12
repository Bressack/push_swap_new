/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:55:15 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/12 17:27:16 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <checker.h>

void	get_prog(t_all *all)
{
	char	*line;
	t_prog	*new;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!line || !strlen(line))
		{
			if (line)
				try_free((void **)&line);
			continue ;
		}
		if (strcmp("pa", line) && strcmp("pb", line) && strcmp("sa", line) &&
		strcmp("sb", line) && strcmp("ss", line) && strcmp("ra", line) &&
		strcmp("rb", line) && strcmp("rr", line) && strcmp("rra", line) &&
		strcmp("rrb", line) && strcmp("rrr", line))
		{
			error(all->bin, ERR, INVALID_OP, line);
			try_free((void **)&line);
		}
		else
		{
			new = try_malloc(sizeof(t_prog));
			new->op = line;
			ft_add_node_end_np((t_pnp **)&all->prog, (t_pnp *)new);
			all->proglen++;
		}
	}
}

void	checker(t_all *all)
{
	t_prog *tmp;
	t_stack *tmp2;

	tmp = all->prog;
	while (tmp)
	{
		if (!strcmp("pa", tmp->op)) pa(all, 1);
		else if (!strcmp("pb", tmp->op)) pb(all, 1);
		else if (!strcmp("sa", tmp->op)) sa(all, 1);
		else if (!strcmp("sb", tmp->op)) sb(all, 1);
		else if (!strcmp("ss", tmp->op)) ss(all, 1);
		else if (!strcmp("ra", tmp->op)) ra(all, 1);
		else if (!strcmp("rb", tmp->op)) rb(all, 1);
		else if (!strcmp("rr", tmp->op)) rr(all, 1);
		else if (!strcmp("rra", tmp->op)) rra(all, 1);
		else if (!strcmp("rrb", tmp->op)) rrb(all, 1);
		else if (!strcmp("rrr", tmp->op)) rrr(all, 1);
		tmp = tmp->next;
	}
	if (all->b)
	{
		printf("KO\n");
		return ;
	}
	tmp2 = all->a;
	while (tmp2)
	{
		if (tmp2->next && tmp2->value > tmp2->next->value)
		{
			printf("KO\n");
			return ;
		}
		tmp2 = tmp2->next;
	}
	printf("OK\n");
}

int		main(int ac, char **av)
{
	t_all	all;

	bzero(&all, sizeof(t_all));
	all.fd = 3;
	all.bin = av[0];
	get_stack(&all, ac, av); // fill all.a and all.b
	get_prog(&all); // fill all.prog
	error(all.bin, COUNT, NULL, NULL);
	if (error(all.bin, CHECK, NULL, NULL) == FAILURE)
	{
		// // free_all_malloc();
		return (-1);
	}
	checker(&all);
	// // free_all_malloc();
	return (0);
}
