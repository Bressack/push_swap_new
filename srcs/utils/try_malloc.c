/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:15:38 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 13:59:26 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < len)
	{
		((char *)b)[bytes] = (unsigned char)c;
		bytes++;
	}
	return (b);
}

void	try_free(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

void	*try_malloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
	{
		write(2, MALLOC_ALLOCATION, ft_strlen(MALLOC_ALLOCATION));
		exit(-1);
	}
	ft_memset(new, 0, size);
	return (new);
}
