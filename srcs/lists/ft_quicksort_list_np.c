/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_list_np.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:00:19 by tharchen          #+#    #+#             */
/*   Updated: 2021/03/26 16:13:46 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <double_linked.h>
#include <color_shell.h>
#include <libc.h>

char		*g_color[8] =
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

/*
** void		ft_quicksort_list_np_sub(t_pnp **list, int deep, double path)
** {
** 	t_list_int	*tmp;
** 	t_list_int	*tmp2;
** 	int			pivot;
** 	t_pnp		*list_min;
** 	t_pnp		*list_egale;
** 	t_pnp		*list_max;
**
** 	// ********************************************************************** //
** 	printf("%*c%sDeep %d | %.0f | PIVOT [%d] | ", deep * 4, ' ', g_color[deep % 8], deep, path, *(t_list_int **)list ? (*(t_list_int **)list)->value : 0);
** 	t_list_int	*tmp_print;
**
** 	tmp_print = *(t_list_int **)list;
** 	while (tmp_print)
** 	{
** 		printf("[%d]", tmp_print->value);
** 		tmp_print = tmp_print->next;
** 	}
** 	printf(C_RES);
** 	// ********************************************************************** //
** 	if (!list || !(*list) || !(*list)->next)
** 	{
** 		printf("\n");
** 		return ;
** 	}
** 	tmp = *(t_list_int **)list;
** 	pivot = tmp->value;
** 	if (!tmp->next->next)
** 	{
** 		if (tmp->value > tmp->next->value)
** 			ft_swap_node_np(list, (t_pnp *)tmp, (t_pnp *)tmp->next);
** 		return ;
** 	}
** 	list_min = NULL;
** 	list_egale = NULL;
** 	list_max = NULL;
** 	tmp2 = NULL;
** 	while (tmp)
** 	{
** 		tmp2 = tmp->next;
** 		ft_grab_node_np(list, (t_pnp *)tmp);
** 		if (tmp->value < pivot)
** 			ft_add_node_end_np(&list_min, (t_pnp *)tmp);
** 		else if (tmp->value > pivot)
** 			ft_add_node_end_np(&list_max, (t_pnp *)tmp);
** 		else
** 			ft_add_node_end_np(&list_egale, (t_pnp *)tmp);
** 		tmp = tmp2;
** 	}
**
** 	printf(" | list_min: ");
** 	tmp_print = (t_list_int *)list_min;
** 	while (tmp_print)
** 	{
** 		printf("[%d]", tmp_print->value);
** 		tmp_print = tmp_print->next;
** 	}
** 	printf(" | list_egale: ");
** 	tmp_print = (t_list_int *)list_egale;
** 	while (tmp_print)
** 	{
** 		printf("[%d]", tmp_print->value);
** 		tmp_print = tmp_print->next;
** 	}
** 	printf(" | list_max: ");
** 	tmp_print = (t_list_int *)list_max;
** 	while (tmp_print)
** 	{
** 		printf("[%d]", tmp_print->value);
** 		tmp_print = tmp_print->next;
** 	}
** 	printf(""C_RES"\n");
** 	if (list_min)
** 		ft_quicksort_list_np_sub(&list_min, deep + 1, (path * 10) + 0); // handles small values
** 	if (list_max)
** 		ft_quicksort_list_np_sub(&list_max, deep + 1, (path * 10) + 1); // handles high values
** 	list_min = ft_listjoin_np(list_min, list_egale);
** 	*list = ft_listjoin_np(list_min, list_max);
** 	printf("%*clist: ", deep * 4, ' ');
** 	tmp_print = *(t_list_int **)list;
** 	while (tmp_print)
** 	{
** 		printf("[%d]", tmp_print->value);
** 		tmp_print = tmp_print->next;
** 	}
** 	printf(""C_RES"\n");
** }
**
** void		ft_quicksort_list_np(t_pnp **list)
** {
** 	ft_quicksort_list_np_sub(list, 0, 1);
** }
*/

void		partition(
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
void		ft_quicksort_list_np(t_pnp **list)
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
		ft_quicksort_list_np(&list_min); // handles small values
	if (list_max)
		ft_quicksort_list_np(&list_max); // handles high values
	list_min = ft_listjoin_np(list_min, list_egale);
	*list = ft_listjoin_np(list_min, list_max);
}
