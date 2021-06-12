/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:55:15 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/12 17:07:10 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

// is the stack contain only marked values
int				only_marks(t_stack *s)
{
	while (s)
	{
		if (s->mark == OFF)
			return (FAILURE);
		s = s->next;
	}
	return (SUCCESS);
}

t_marks_ret		get_best_mark(t_stack *s)
{
	t_marks_ret	ret;
	t_stack *tmp;
	t_stack	*best;
	int		kbest;
	int		k;
	int		last;

	kbest = 0;
	while (s)
	{
		tmp = s->next;
		k = 1;
		last = s->value;
		while (tmp)
		{
			if (tmp->value > last)
			{
				k++;
				last = tmp->value;
			}
			else
			tmp = tmp->next;
		}
		if (k > kbest)
		{
			best = s;
			kbest = k;
		}
		s = s->next;
	}
	ret.s = best;
	ret.n = kbest;
	return (ret);
}

// return the number of mark in the best configuration
int				get_best_mark_count(t_stack *s)
{
	t_marks_ret ret;
	ret = get_best_mark(s);
	return (ret.n);
}

// return first stack node with a mark in the best configuration
t_stack			*get_best_mark_start(t_stack *s)
{
	t_marks_ret ret;
	ret = get_best_mark(s);
	return (ret.s);
}

// apply marks on the given stack
void			apply_marks(t_stack *s)
{
	t_stack	*tmp;
	int		last;

	tmp = s;
	while (tmp)
	{
		tmp->mark = OFF;
		tmp = tmp->next;
	}
	tmp = get_best_mark_start(s);
	last = tmp->value;
	tmp->mark = ON;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > last)
		{
			last = tmp->value;
			tmp->mark = ON;
		}
		else
			tmp->mark = OFF;
		tmp = tmp->next;
	}
}

void			swap_if_better(t_all *all, t_stack **s)
{
	int			mark1;
	int			mark2;

	mark1 = get_best_mark_count(*s);
	if (*s && (*s)->next)
		swap(s);
	mark2 = get_best_mark_count(*s);
	if (mark2 > mark1)
	{
		if (*s == all->a)
			ft_putstr_fd(1, "sa");
		else
			ft_putstr_fd(1, "sb");
		apply_marks(*s);
	}
	else if (*s && (*s)->next)
		swap(s);
}

int				get_last(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s->value);
}

void			process_alpha(t_all *all)
{
	apply_marks(all->a);
	while (only_marks(all->a) == FAILURE)
	{
		swap_if_better(all, &all->a);
		if (only_marks(all->a) == SUCCESS)
			break ;
		if (all->a->mark == OFF)
			pb(all, 1);
		else
			ra(all, 1);
	}
}

t_stack			*get_stack_min(t_stack *s)
{
	t_stack		*ret;
	int			min;

	ret = s;
	if (s)
		min = s->value;
	while (s)
	{
		if (s->value < min)
		{
			ret = s;
			min = s->value;
		}
		s = s->next;
	}
	return (ret);
}

t_stack			*get_stack_max(t_stack *s)
{
	t_stack		*ret;
	int			max;

	ret = s;
	if (s)
		max = s->value;
	while (s)
	{
		if (s->value > max)
		{
			ret = s;
			max = s->value;
		}
		s = s->next;
	}
	return (ret);
}

int				get_index(t_stack *s, int value)
{
	int			i;

	i = 0;
	while (s)
	{
		if (s->value == value)
			return (i);
		i++;
		s = s->next;
	}
	return (0); // TOCHECK 0 or i (cuz i could be stacklen if no match)
}

int				get_next_index(t_stack *s, int value)
{
	double		*tab;
	int			min;
	int			max;
	int			index;
	int			i;

	min = get_stack_min(s)->value;
	max = get_stack_max(s)->value;
	if (value < min || value > max)
		index = get_index(s, min);
	else
	{
		tab = get_sorted_tab(s);
		i = 0;
		while (value > tab[i])
			i++;
		index = get_index(s, tab[i]);
	}
	try_free((void **)&tab);
	return (index);
}

void			init_case(t_all *all, int value, t_case *c)
{
	c->value = value;
	c->i = get_next_index(all->a, value);
	c->j = get_index(all->b, value);
	c->size_a = get_size_stack(all->a);
	c->size_b = all->stacklen - c->size_a;
	c->half_a = c->size_a / 2 + 1;
	c->half_b = c->size_b / 2 + 1;
}

int				fill_case(t_all *all, int value, t_case *c)
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

void			get_best_case(t_all *all, t_case *c)
{
	t_stack		*tmp;
	int			best;
	int			min;

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

void			apply_best_case(t_all *all, t_case *c)
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
		rra(all, ft_max(0, c->size_a - c->i - ft_min(c->size_a - c->i, c->size_b - c->j)));
		rrb(all, ft_max(0, c->size_b - c->j - ft_min(c->size_a - c->i, c->size_b - c->j)));
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

void			align_a(t_all *all)
{
	int			min;
	int			index;

	min = get_stack_min(all->a)->value;
	index = get_index(all->a, min);
	if (index < all->stacklen)
		ra(all, index);
	else
		rra(all, all->stacklen - index);
}

void			process_beta(t_all *all)
{
	t_case		c;

	while (all->b)
	{
		get_best_case(all, &c);
		apply_best_case(all, &c);
	}
	align_a(all);
}


int				main(int ac, char **av)
{
	t_all	all;

	bzero(&all, sizeof(t_all));
	all.fd = 1;
	all.bin = av[0];
	if (ac > 1)
		get_stack(&all, ac, av); // fill all.a and all.b
	error(all.bin, COUNT, NULL, NULL);
	if (error(all.bin, CHECK, NULL, NULL) == FAILURE)
	{
		free_all_malloc();
		return (-1);
	}
	if (all.a && all.a->next)
	{
		process_alpha(&all);
		process_beta(&all);
	}
	// free_all_malloc();
	return (0);
}
