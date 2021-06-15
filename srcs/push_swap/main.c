/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:55:15 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/15 12:55:56 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

void	align_a(t_all *all)
{
	int	min;
	int	index;

	min = get_stack_min(all->a)->value;
	index = get_index(all->a, min);
	if (index < all->stacklen)
		ra(all, index);
	else
		rra(all, all->stacklen - index);
}

void	handle_5(t_all *all)
{
	int	a;
	int	b;
	int	c;

	pb(all, all->stacklen - 3);
	a = all->a->value;
	b = all->a->next->value;
	c = all->a->next->next->value;
	if (a < b && a < c && b > c)
	{
		sa(all, 1);
		ra(all, 1);
	}
	if (a > b && a < c && b < c)
		sa(all, 1);
	if (a < b && a > c && b > c)
		rra(all, 1);
	if (a > b && a > c && b < c)
		ra(all, 1);
	if (a > b && a > c && b > c)
	{
		sa(all, 1);
		rra(all, 1);
	}
}

int	main(int ac, char **av)
{
	t_all	all;

	bzero(&all, sizeof(t_all));
	all.fd = 1;
	all.bin = av[0];
	if (ac > 1)
		get_stack(&all, ac, av);
	error(all.bin, COUNT, NULL, NULL);
	if (error(all.bin, CHECK, NULL, NULL) == FAILURE)
	{
		ft_del_list_np((t_pnp **)&all.a);
		ft_del_list_np((t_pnp **)&all.b);
		return (-1);
	}
	if (all.a && all.a->next)
	{
		if (all.stacklen <= 5 && all.stacklen >= 3)
			handle_5(&all);
		else
			process_alpha(&all);
		process_beta(&all);
	}
	ft_del_list_np((t_pnp **)&all.a);
	ft_del_list_np((t_pnp **)&all.b);
	return (0);
}
