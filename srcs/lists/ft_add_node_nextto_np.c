/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_nextto_np.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:40:32 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:00:39 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

void	ft_add_node_nextto_np(t_pnp *prev, t_pnp *new)
{
	new->next = prev->next;
	new->prev = prev;
	if (prev->next)
		prev->next->prev = new;
	prev->next = new;
}
