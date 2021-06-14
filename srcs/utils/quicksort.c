/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:53:27 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 13:59:53 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	quicksort(double *tab, size_t size, int rev)
{
	size_t	i;
	size_t	wall;
	double	pivot;
	double	tmp;

	if (size < 2)
		return ;
	pivot = tab[size - 1];
	wall = 0;
	i = -1;
	while (++i < size)
	{
		if (tab[i] <= pivot)
		{
			if (wall != i)
			{
				tmp = tab[i];
				tab[i] = tab[wall];
				tab[wall] = tmp;
			}
			wall++;
		}
	}
	quicksort(tab, wall - 1, rev);
	quicksort(tab + wall - 1, size - wall + 1, rev);
}
