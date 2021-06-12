/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:13:16 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/05 03:39:47 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

void	print_stacks(t_all *all)
{
	static char	*pattern = NULL;
	static char	*pattern_stru = NULL;
	t_stack		*tmp_a;
	t_stack		*tmp_b;


	if (!pattern)
	{
		pattern = try_malloc(sizeof(char) * 201);
		ft_memset(pattern, '#', 200);
	}
	if (!pattern_stru)
	{
		pattern_stru = try_malloc(sizeof(char) * 301);
		ft_memset(pattern_stru, '-', 300);
	}
	tmp_a = all->a;
	tmp_b = all->b;
	dprintf(2, " %.*s stack A | B stack %.*s\n", 99, pattern_stru, 99, pattern_stru);
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			dprintf(2, "| %*.*s %5d ",
				100,
				((tmp_a->index * 100 / all->stacklen) + 1) > 100 ? 100 : ((tmp_a->index * 100 / all->stacklen) + 1),
				pattern,
				tmp_a->value
			);
			tmp_a = tmp_a->next;
		}
		else
			dprintf(2, "|%*c", 108, ' ');
		dprintf(2, "|");
		if (tmp_b)
		{
			dprintf(2, " %-5d %-*.*s |",
				tmp_b->value,
				100,
				((tmp_b->index * 100 / all->stacklen) + 1) > 100 ? 100 : ((tmp_b->index * 100 / all->stacklen) + 1),
				pattern
			);
			tmp_b = tmp_b->next;
		}
		else
			dprintf(2, "%-*c|", 108, ' ');
		dprintf(2, "\n");
	}
	dprintf(2, " %.*s \n", 217, pattern_stru);
}
