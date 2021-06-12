/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmalloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:25:01 by frlindh           #+#    #+#             */
/*   Updated: 2021/04/28 11:37:57 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMALLOC_H
# define MMALLOC_H
# define _FL_ (char *)__FUNCTION__, (int)__LINE__
#include <commons.h>
typedef enum				e_mmalloc
{
	GET,
	GETADDR,
	SET,
	FREEALL
}							t_mmalloc;

typedef struct				s_list_malloc
{
	struct s_list_malloc	*next;
	struct s_list_malloc	*prev;
	char					*f;
	int						l;
	void					*data;
	size_t					size;
	size_t					sizefull;
	int						isfree;
}							t_list_malloc;

void	*all_malloc(int opt, t_list_malloc *node);
// void	*try_malloc(unsigned int size);
void	*try_malloc(unsigned int size, char *f, int l);
int		free_all_malloc(void);
int		try_free(void **to_free);
void	print_all_malloc(void);

#endif
