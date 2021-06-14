/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab_node_np.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:59:56 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:01:14 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

t_pnp	*ft_grab_node_np(t_pnp **list_src, t_pnp *target)
{
	t_pnp	*tmp;

	if (!list_src || !target)
		return (target);
	tmp = *list_src;
	if (tmp == target)
	{
		*list_src = (*list_src)->next;
		if (*list_src)
			(*list_src)->prev = NULL;
	}
	else
	{
		while (tmp && tmp->next != target)
			tmp = tmp->next;
		if (tmp == NULL)
			return (target);
		tmp->next = target->next;
		if (target->next)
			target->next->prev = tmp;
		target->next = NULL;
		target->prev = NULL;
	}
	return (target);
}
