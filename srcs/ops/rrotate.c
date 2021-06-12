/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:03:17 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/05 03:03:56 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	rrotate(struct s_stack **stack)
{
	struct s_stack	*tmp;

	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack);
	(*stack)->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack) = tmp;
}

int		rra(t_all *all, int count)
{
	while (count)
	{
		if (all && all->a && all->a->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			rrotate(&all->a);
		}
		count--;
	}
	return (0);
}

int		rrb(t_all *all, int count)
{
	while (count)
	{
		if (all && all->b && all->b->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			rrotate(&all->b);
		}
		count--;
	}
	return (0);
}

int		rrr(t_all *all, int count)
{
	while (count)
	{
		if ((all && all->a && all->a->next) || (all && all->b && all->b->next))
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
		if (all && all->a && all->a->next)
			rrotate(&all->a);
		if (all && all->b && all->b->next)
			rrotate(&all->b);
		count--;
	}
	return (0);
}
