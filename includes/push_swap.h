/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:55:39 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/14 14:56:12 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <commons.h>
typedef enum e_caseno
{
	CASE_A,
	CASE_B,
	CASE_C,
	CASE_D
}					t_caseno;
typedef struct s_case
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
typedef struct s_marks_ret
{
	t_stack			*s;
	int				n;
}					t_marks_ret;
t_stack		*get_stack_min(t_stack *s);
t_stack		*get_stack_max(t_stack *s);
void		apply_marks(t_stack *s);
void		swap_if_better(t_all *all, t_stack **s);
void		process_alpha(t_all *all);
int			get_index(t_stack *s, int value);
int			get_next_index(t_stack *s, int value);
void		align_a(t_all *all);
void		handle_5(t_all *all);
void		init_case(t_all *all, int value, t_case *c);
int			fill_case(t_all *all, int value, t_case *c);
void		get_best_case(t_all *all, t_case *c);
void		apply_best_case(t_all *all, t_case *c);
void		process_beta(t_all *all);
int			only_marks(t_stack *s);
int			get_best_mark_count(t_stack *s);
t_stack		*get_best_mark_start(t_stack *s);
t_marks_ret	get_best_mark(t_stack *s);
#endif
