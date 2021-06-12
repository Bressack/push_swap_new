/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfere_node_np.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:06:37 by tharchen          #+#    #+#             */
/*   Updated: 2021/03/25 13:59:44 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

void		ft_transfere_node_np(t_pnp **list_src, t_pnp **list_dest,
	t_pnp *target, t_pnp *neighbour, int prevornext)
{
	target = ft_grab_node_np(list_src, target);
	if (!*list_dest || !neighbour)
		ft_add_node_end_np(list_dest, target);
	else if (prevornext == NEXT)
		ft_add_node_nextto_np(neighbour, target);
	else
		ft_add_node_prevto_np(list_dest, neighbour, target);
}
