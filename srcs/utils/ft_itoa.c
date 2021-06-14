/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:06:36 by tarchen           #+#    #+#             */
/*   Updated: 2021/06/14 13:54:54 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

static int	intlen(int value)
{
	int		len;

	len = 0;
	if (value < 0)
		len++;
	while (value)
	{
		len++;
		value /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*buf;
	int		j;
	long	nbr;

	nbr = n;
	buf = try_malloc(sizeof(char) * ((intlen(nbr) + 1)));
	if (nbr < 0)
	{
		buf[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		*buf = '0';
	j = intlen(nbr) - 1;
	while (nbr > 0)
	{
		buf[j] = '0' + (nbr % 10);
		nbr /= 10;
		j--;
	}
	return (buf);
}
