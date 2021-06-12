/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:56:56 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/05 02:29:05 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}