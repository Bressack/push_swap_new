/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:55:39 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/05 03:06:25 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <commons.h>
typedef enum		e_caseno
{
	CASE_A,
	CASE_B,
	CASE_C,
	CASE_D
}					t_caseno;
typedef struct		s_case
{
	int				value;
	int				caseno;
	int				nb_op;
	int				i;
	int				j;
	int				size_a;
	int				size_b;
	int				half_a;
	int				half_b;
}					t_case;
typedef struct		s_marks_ret
{
	t_stack			*s;
	int				n;
}					t_marks_ret;
#endif
