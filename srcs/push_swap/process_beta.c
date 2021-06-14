/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_beta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:34:30 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 14:34:42 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

void	init_case(t_all *all, int value, t_case *c)
{
	c->value = value;
	c->i = get_next_index(all->a, value);
	c->j = get_index(all->b, value);
	c->size_a = get_size_stack(all->a);
	c->size_b = all->stacklen - c->size_a;
	c->half_a = c->size_a / 2 + 1;
	c->half_b = c->size_b / 2 + 1;
}

int	fill_case(t_all *all, int value, t_case *c)
{
	init_case(all, value, c);
	if (c->i < c->half_a && c->j < c->half_b)
	{
		c->caseno = CASE_A;
		c->nb_op = ft_max(c->i, c->j);
	}
	else if (c->i >= c->half_a && c->j >= c->half_b)
	{
		c->caseno = CASE_B;
		c->nb_op = ft_max(c->size_a - c->i, c->size_b - c->j);
	}
	else if (c->i < c->half_a && c->j >= c->half_b)
	{
		c->caseno = CASE_C;
		c->nb_op = c->i + c->size_b - c->j;
	}
	else if (c->i >= c->half_a && c->j < c->half_b)
	{
		c->caseno = CASE_D;
		c->nb_op = c->j + c->size_a - c->i;
	}
	return (c->nb_op);
}

void	get_best_case(t_all *all, t_case *c)
{
	t_stack	*tmp;
	int		best;
	int		min;

	tmp = all->b;
	fill_case(all, tmp->value, c);
	best = tmp->value;
	min = c->nb_op;
	while (tmp)
	{
		fill_case(all, tmp->value, c);
		if (c->nb_op < min)
		{
			best = tmp->value;
			min = c->nb_op;
		}
		tmp = tmp->next;
	}
	fill_case(all, best, c);
}

void	apply_best_case(t_all *all, t_case *c)
{
	if (c->caseno == CASE_A)
	{
		rr(all, ft_min(c->i, c->j));
		ra(all, ft_max(0, c->i - ft_min(c->i, c->j)));
		rb(all, ft_max(0, c->j - ft_min(c->i, c->j)));
	}
	else if (c->caseno == CASE_B)
	{
		rrr(all, ft_min(c->size_a - c->i, c->size_b - c->j));
		rra(all, ft_max(0, c->size_a - c->i - ft_min(c->size_a - c->i, c->size_b
					- c->j)));
		rrb(all, ft_max(0, c->size_b - c->j - ft_min(c->size_a - c->i, c->size_b
					- c->j)));
	}
	else if (c->caseno == CASE_C)
	{
		ra(all, c->i);
		rrb(all, c->size_b - c->j);
	}
	else if (c->caseno == CASE_D)
	{
		rra(all, c->size_a - c->i);
		rb(all, c->j);
	}
	pa(all, 1);
}

void	process_beta(t_all *all)
{
	t_case	c;

	while (all->b)
	{
		get_best_case(all, &c);
		apply_best_case(all, &c);
	}
	align_a(all);
}
