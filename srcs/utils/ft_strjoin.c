/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:19:43 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/10 14:52:06 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static void	*join(char **ret, char *arg, int *retsize)
{
	char	*tmp;
	int		size;

	size = ft_strlen(arg);
	tmp = try_malloc(sizeof(char) * (*retsize + size + 1));
	ft_memcpy(tmp, *ret, *retsize);
	ft_memcpy(tmp + *retsize, arg, size);
	*retsize += size;
	tmp[*retsize] = '\0';
	free(*ret);
	*ret = tmp;
	return (tmp);
}

char	*tho(char *arg, char **ret, int *size)
{
	*ret = ft_strdup(arg);
	if (!(*ret))
		return (NULL);
	*size = ft_strlen(*ret);
	return (arg);
}

char	*ft_strjoin(int nb_str, ...)
{
	char	*arg;
	char	*ret;
	va_list	ap;
	int		size;

	ret = NULL;
	size = 0;
	va_start(ap, nb_str);
	while (nb_str--)
	{
		arg = va_arg(ap, char *);
		if (!arg)
			continue ;
		if (!ret)
		{
			if (tho(arg, &ret, &size) == NULL)
				return (NULL);
		}
		else
			if (join(&ret, arg, &size) == NULL)
				return (NULL);
	}
	va_end(ap);
	return (ret);
}
