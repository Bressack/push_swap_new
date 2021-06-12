/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:07:42 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/12 17:14:39 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <commons.h>
# define NUM			"0123456789"
# define BUFF_SIZE_GNL	8192
typedef struct s_str
{
	char			*str;
	int				fd;
	struct s_str	*next;
}					t_str;
int		get_next_line(const int fd, char **line);
#endif
