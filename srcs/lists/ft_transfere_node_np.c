/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfere_node_np.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:06:37 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:04:10 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

void	ft_transfere_node_prev_np(t_pnp **list_src, t_pnp **list_dest,
	t_pnp *target, t_pnp *neighbour)
{
	target = ft_grab_node_np(list_src, target);
	if (!*list_dest || !neighbour)
		ft_add_node_end_np(list_dest, target);
	else
		ft_add_node_prevto_np(list_dest, neighbour, target);
}

void	ft_transfere_node_next_np(t_pnp **list_src, t_pnp **list_dest,
	t_pnp *target, t_pnp *neighbour)
{
	target = ft_grab_node_np(list_src, target);
	if (!*list_dest || !neighbour)
		ft_add_node_end_np(list_dest, target);
	else
		ft_add_node_nextto_np(neighbour, target);
}
