/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:03:17 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/05 02:54:25 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	swap(struct s_stack **stack)
{
	ft_swap_node_np((t_pnp **)stack, (t_pnp *)(*stack), (t_pnp *)(*stack)->next);
}

int		sa(t_all *all, int count)
{
	while (count)
	{
		if (all && all->a && all->a->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			swap(&all->a);
		}
		count--;
	}
	return (0);
}

int		sb(t_all *all, int count)
{
	while (count)
	{
		if (all && all->b && all->b->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			swap(&all->b);
		}
		count--;
	}
	return (0);
}

int		ss(t_all *all, int count)
{
	while (count)
	{
		if ((all && all->a && all->a->next) || (all && all->b && all->b->next))
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
		if (all && all->a && all->a->next)
			swap(&all->a);
		if (all && all->b && all->b->next)
			swap(&all->b);
		count--;
	}
	return (0);
}
