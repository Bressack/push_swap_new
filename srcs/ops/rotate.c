/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:03:17 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/05 02:53:06 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	rotate(struct s_stack **stack)
{
	struct s_stack	*tmp;

	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	(*stack)->next->prev = NULL;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = tmp;
}

int		ra(t_all *all, int count)
{
	while (count)
	{
		if (all && all->a && all->a->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			rotate(&all->a);
		}
		count--;
	}
	return (0);
}

int		rb(t_all *all, int count)
{
	while (count)
	{
		if (all && all->b && all->b->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			rotate(&all->b);
		}
		count--;
	}
	return (0);
}

int		rr(t_all *all, int count)
{
	while (count)
	{
		if ((all && all->a && all->a->next) || (all && all->b && all->b->next))
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
		if (all && all->a && all->a->next)
			rotate(&all->a);
		if (all && all->b && all->b->next)
			rotate(&all->b);
		count--;
	}
	return (0);
}
