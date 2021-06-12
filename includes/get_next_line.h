/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:07:42 by tharchen          #+#    #+#             */
/*   Updated: 2021/03/13 23:43:08 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define RET 0
# define LEN 1
# define CURR 0
# define SAVE 1
# define BUFFER_SIZE 64
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define FREE(X) free(X), X = NULL

int		get_next_line(const int fd, char **line);
#endif
