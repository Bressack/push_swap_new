/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:55:39 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/10 14:41:35 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H
#include <libc.h>
#include <color_shell.h>
#include <mmalloc.h>
#include <double_linked.h>
#include <utils.h>
#include <get_next_line.h>
# define INVALID_NUMBER "invalid number"
# define INVALID_OP "invalid opperation"
# define MALLOC_ALLOCATION "malloc cannot allocate region"
# define NUMBER_OUT_OF_INTEGER_RANGE "number out of the range of an integer"
# define NUMBER_ALREADY_IN_STACK "number already in stack"
typedef enum		e_perfopt
{
	START,
	END,
	PRINT
}					t_perfopt;
typedef struct		s_perf
{
	char			*funname;
	int				call;
	long long		time;
	struct timeval	start;
	struct timeval	end;
}					t_perf;
typedef struct		s_truple
{
	long long		h;
	long long		m;
	long long		s;
	long long		ms;
}					t_truple;
extern t_perf		perf[1000];
typedef enum		e_errortype
{
	NONE,
	ERR,
	FATALERR,
	WARN,
	INFO,
	COUNT,
	CHECK,
	RESET
}					t_errortype;
typedef enum		e_lever
{
	OFF,
	ON
}					t_lever;

typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				value;
	int				mark;
	int				index;
}					t_stack;
typedef struct		s_prog
{
	struct s_prog	*next;
	struct s_prog	*prev;
	char			*op;
}					t_prog;
typedef struct		s_all
{
	char			*bin;
	int				fd;
	int				min;
	int				max;
	int				stacklen;
	int				proglen;
	t_stack			*a;
	t_stack			*b;
	t_prog			*prog;
}					t_all;
typedef struct		s_stat_prog
{
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_stat_prog;
t_truple				truple(long long ms);
void					perfanalyser(char *funname, int opt);
int		get_size_stack(t_stack *s);
double	*get_sorted_tab(t_stack *s);
void	print_stacks(t_all *all);
void	get_stack(t_all *all, int ac, char **av);
int		error(char *bin, enum e_errortype type, char *msg, char *arg); // TOOLONG
void	swap(struct s_stack **stack);
int		pa(t_all *all, int count);
int		pb(t_all *all, int count);
int		ra(t_all *all, int count);
int		rb(t_all *all, int count);
int		rr(t_all *all, int count);
int		rra(t_all *all, int count);
int		rrb(t_all *all, int count);
int		rrr(t_all *all, int count);
int		sa(t_all *all, int count);
int		sb(t_all *all, int count);
int		ss(t_all *all, int count);
#endif
