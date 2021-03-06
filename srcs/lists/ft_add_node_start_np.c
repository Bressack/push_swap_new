/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_start_np.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:03:52 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:00:45 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

void	ft_add_node_start_np(t_pnp **begin_list, t_pnp *new)
{
	new->next = *begin_list;
	new->prev = NULL;
	if (*begin_list)
		(*begin_list)->prev = new;
	*begin_list = new;
}
