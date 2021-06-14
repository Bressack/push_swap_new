/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_list_np.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:00:19 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 15:04:04 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>
#include <color_shell.h>
#include <commons.h>

char	*g_color[8] =
{
	C_G_RED,
	C_G_GREEN,
	C_G_YELLOW,
	C_G_BLUE,
	C_G_MAGENTA,
	C_G_CYAN,
	C_G_WHITE,
	C_G_GREY
};

void	partition(
	t_pnp **list, t_pnp **list_min, t_pnp **list_egale, t_pnp **list_max)
{
	t_list_int	*tmp;
	t_list_int	*tmp2;
	int			pivot;

	tmp2 = NULL;
	tmp = *(t_list_int **)list;
	pivot = tmp->value;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_grab_node_np(list, (t_pnp *)tmp);
		if (tmp->value < pivot)
			ft_add_node_end_np(list_min, (t_pnp *)tmp);
		else if (tmp->value > pivot)
			ft_add_node_end_np(list_max, (t_pnp *)tmp);
		else
			ft_add_node_end_np(list_egale, (t_pnp *)tmp);
		tmp = tmp2;
	}
}

void	ft_quicksort_list_np(t_pnp **list)
{
	t_pnp		*list_min;
	t_pnp		*list_egale;
	t_pnp		*list_max;

	if (!list || !(*list) || !(*list)->next)
		return ;
	if (!(*list)->next->next)
	{
		if ((*(t_list_int **)list)->value > (*(t_list_int **)list)->next->value)
			ft_swap_node_np(list, *list, (*list)->next);
		return ;
	}
	list_min = NULL;
	list_egale = NULL;
	list_max = NULL;
	partition(list, &list_min, &list_egale, &list_max);
	if (list_min)
		ft_quicksort_list_np(&list_min);
	if (list_max)
		ft_quicksort_list_np(&list_max);
	list_min = ft_listjoin_np(list_min, list_egale);
	*list = ft_listjoin_np(list_min, list_max);
}
