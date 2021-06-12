/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:23:10 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 15:45:20 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
