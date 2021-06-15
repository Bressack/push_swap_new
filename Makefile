# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 23:43:12 by tharchen          #+#    #+#              #
#    Updated: 2021/06/15 13:13:29 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#    Makefile project push_swap by tharchen                                    #
#                                                                              #
#    rules:                                                                    #
#                                                                              #
#    make           : make the project                                         #
#    make all       : make the project                                         #
#    make push_swap   : make the project                                       #
#    make norm      : run the norminette of srcs and headers                   #
#    make clean     : clean object files (.o)                                  #
#    make fclean    : clean object files (.o) and remove push_swap bin         #
#    make re        : run rules fclean then all                                #
#    make run       : run re then run ./$(NAME)                                #
#                                                                              #
# *** NAME - CC - FLAGS ****************************************************** #

UNAME_S					=	$(shell uname -s)

NAME_PUSH_SWAP			=	push_swap

ifeq ($(UNAME_S),Linux)
	CC					=	clang-9
else
	CC					=	clang
endif

FLAGS					=	-Wall -Wextra -Werror -O3
# FLAGS					=	-Wall -Wextra -Werror -g3 -fsanitize=address

BONUS_FLAG				=	0

# *** PROJECT HEADER ********************************************************* #

HDIR					=	$(addprefix -I, $(HEADER_DIR))

HEAD					=	$(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR				=	\
							./includes/

HEADER					=	\
							commons.h \
							color_shell.h \
							mmalloc.h \
							double_linked.h \
							utils.h \
							get_next_line.h \

# *** SRCS ******************************************************************* #

SRCS_DIR				=	./srcs/

SRCS_LIBLIST			=	\
							lists/ft_add_node_end_np.c \
							lists/ft_add_node_f_nextto_np.c \
							lists/ft_add_node_f_prevto_np.c \
							lists/ft_add_node_nextto_np.c \
							lists/ft_add_node_prevto_np.c \
							lists/ft_add_node_start_np.c \
							lists/ft_del_list_np.c \
							lists/ft_del_node_end_np.c \
							lists/ft_del_node_np.c \
							lists/ft_del_node_start_np.c \
							lists/ft_foreach_node_f_np.c \
							lists/ft_new_node.c \
							lists/ft_swap_node_np.c \
							lists/ft_transfere_node_np.c \
							lists/ft_quicksort_list_np.c \
							lists/ft_listjoin_np.c \
							lists/ft_grab_node_np.c \

SRCS_UTILS				=	\
							utils/ft_atol.c \
							utils/ft_itoa.c \
							utils/ft_strcpy.c \
							utils/ft_strfind.c \
							utils/ft_strlen.c \
							utils/ft_strncpy.c \
							utils/ft_strsplit.c \
							utils/ft_strsub.c \
							utils/isnumber.c \
							utils/try_malloc.c \
							utils/ft_strjoin.c \
							utils/ft_strcmp.c \
							utils/ft_strdel.c \
							utils/ft_strdup.c \
							utils/ft_memcpy.c \
							utils/nbrlen.c \
							utils/get_next_line.c \
							utils/quicksort.c \
							utils/get_min_max.c \
							utils/ft_putstr_fd.c \
							utils/ft_putnbr.c \

SRCS_OPS				=	\
							ops/rotate.c \
							ops/push.c \
							ops/rrotate.c \
							ops/swap.c \

SRCS_LIST_COMMONS		=	\
							$(SRCS_LIBLIST) \
							$(SRCS_UTILS) \
							$(SRCS_OPS) \
							error.c \
							get_stack.c \
							get_size_stack.c \

SRCS_DIR_PUSH_SWAP		=	push_swap/

SRCS_LIST_PUSH_SWAP_BRUT	=	\
								get_stack_limits.c \
								main.c \
								marks_handle.c \
								process_alpha.c \
								process_beta.c \

SRCS_LIST_PUSH_SWAP_P	=	$(addprefix $(SRCS_DIR_PUSH_SWAP), $(SRCS_LIST_PUSH_SWAP_BRUT))

SRCS_LIST_PUSH_SWAP		=	\
							$(SRCS_LIST_COMMONS) \
							$(SRCS_LIST_PUSH_SWAP_P) \

SRCS_PUSH_SWAP			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST_PUSH_SWAP))

# *** OBJS ******************************************************************* #

OBJS_DIR				=	./objs/

OBJS_DIR_PUSH_SWAP		=	$(addprefix $(OBJS_DIR), push_swap/)

OBJS_LIST_PUSH_SWAP		=	$(patsubst %.c, %.o, $(SRCS_LIST_PUSH_SWAP))

OBJS_PUSH_SWAP			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST_PUSH_SWAP))

# *** RULES ****************************************************************** #

.PHONY: clean fclean all re norm fclean_push_swap re_push_swap

all:
	@ make $(NAME_PUSH_SWAP) -j

$(NAME_PUSH_SWAP): $(SRCS_PUSH_SWAP)
	@ $(CC) $(FLAGS) $(HDIR) $(SRCS_PUSH_SWAP) -o $@
	@ printf "\033[31m Program \033[32m$(NAME_PUSH_SWAP) : \033[34mCompilation succeed\033[0m                           \n"; \

bonus:
	@make fclean
	@make -j BONUS_FLAG=1

norm:
	@ norminette $(HEADER_DIR) $(SRCS_PUSH_SWAP)

clean:
	@ rm -rf $(OBJS_DIR)

fclean: clean
	@ rm -f $(NAME_PUSH_SWAP)
	@ rm -rf $(NAME_PUSH_SWAP).dSYM

fclean_push_swap: clean
	@ rm -f $(NAME_PUSH_SWAP)

re: fclean
	@ make -j

re_push_swap: fclean_push_swap
	@ make $(NAME_PUSH_SWAP) -j

# **************************************************************************** #
