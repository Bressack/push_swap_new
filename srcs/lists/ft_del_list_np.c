/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_list_np.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:36:42 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:00:49 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

void	ft_del_list_np(t_pnp **begin_list)
{
	t_pnp	*tmp;
	t_pnp	*tmp2;

	tmp = *begin_list;
	while (tmp)
	{
		tmp2 = tmp->next;
		try_free((void **)&tmp);
		tmp = tmp2;
	}
	*begin_list = NULL;
}
