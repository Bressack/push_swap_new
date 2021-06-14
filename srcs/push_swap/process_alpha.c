/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_alpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:33:32 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 14:33:58 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

// apply marks on the given stack
void	apply_marks(t_stack *s)
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

void	swap_if_better(t_all *all, t_stack **s)
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

void	process_alpha(t_all *all)
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

int	get_index(t_stack *s, int value)
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
	return (0);
}

int	get_next_index(t_stack *s, int value)
{
	double	*tab;
	int		min;
	int		max;
	int		index;
	int		i;

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
		try_free((void **)&tab);
	}
	return (index);
}
