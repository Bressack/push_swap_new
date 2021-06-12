/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listjoin_np.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:04:36 by tharchen          #+#    #+#             */
/*   Updated: 2021/03/24 16:08:56 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

t_pnp	*ft_listjoin_np(t_pnp *list_a, t_pnp *list_b)
{
	t_pnp	*tmp;

	if (!list_a)
		return (list_b);
	if (!list_b)
		return (list_a);
	if (!list_a && !list_b)
		return (NULL);
	tmp = list_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list_b;
	list_b->prev = tmp;
	return (list_a);
}
