/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node_np.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:33:35 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:00:56 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>

#include <commons.h>

void	ft_del_node_np(t_pnp **begin_list, t_pnp *del,
	void (*f)(t_pnp *curr))
{
	t_pnp	*tmp;

	tmp = *begin_list;
	if (tmp == del)
	{
		*begin_list = (*begin_list)->next;
		if (*begin_list)
			(*begin_list)->prev = NULL;
	}
	else
	{
		while (tmp && tmp->next != del)
			tmp = tmp->next;
		if (tmp == NULL)
			return ;
		tmp->next = del->next;
		if (del->next)
			del->next->prev = tmp;
	}
	if (f)
		f(del);
	try_free((void **)&del);
}
