/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnumber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:24:34 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 13:57:28 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (str[i] == 0)
		return (FAILURE);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
