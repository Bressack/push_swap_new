/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:34:44 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 16:36:25 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

int	get_size_stack(t_stack *s)
{
	int			i;

	i = 0;
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}
