/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_prevto_np.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:42:34 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:00:41 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>
#include <color_shell.h>
#include <commons.h>

void	ft_add_node_prevto_np(t_pnp **start, t_pnp *next, t_pnp *new)
{
	if (!new && !next && !(*start))
		return ;
	if (*start == next)
		ft_add_node_start_np(start, new);
	else
	{
		new->next = next;
		new->prev = next->prev;
		if (next->prev)
			next->prev->next = new;
		next->prev = new;
	}
}
