/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_limits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:24:39 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 14:24:50 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

t_stack	*get_stack_min(t_stack *s)
{
	t_stack		*ret;
	int			min;

	ret = s;
	if (s)
		min = s->value;
	while (s)
	{
		if (s->value < min)
		{
			ret = s;
			min = s->value;
		}
		s = s->next;
	}
	return (ret);
}

t_stack	*get_stack_max(t_stack *s)
{
	t_stack		*ret;
	int			max;

	ret = s;
	if (s)
		max = s->value;
	while (s)
	{
		if (s->value > max)
		{
			ret = s;
			max = s->value;
		}
		s = s->next;
	}
	return (ret);
}
