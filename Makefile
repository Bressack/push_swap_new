# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 23:43:12 by tharchen          #+#    #+#              #
#    Updated: 2021/06/14 14:54:30 by tharchen         ###   ########.fr        #
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

NAME_CHECKER			=	checker

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
							checker.h \
							commons.h \
							color_shell.h \
							mmalloc.h \
							double_linked.h \
							utils.h \
							get_next_line.h \

# *** SRCS ******************************************************************* #

SRCS_DIR				=	./srcs/

SRCS_DIR_PERF			=	./srcs/
# SRCS_DIR_PERF			=	./srcs_perfanalyser/

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
							print_stacks.c \

SRCS_DIR_CHECKER		=	checker/

SRCS_DIR_PUSH_SWAP		=	push_swap/

SRCS_LIST_CHECKER_BRUT	=	\
							main.c \

SRCS_LIST_PUSH_SWAP_BRUT	=	\
								get_stack_limits.c \
								main.c \
								marks_handle.c \
								process_alpha.c \
								process_beta.c \

SRCS_LIST_CHECKER_P		=	$(addprefix $(SRCS_DIR_CHECKER), $(SRCS_LIST_CHECKER_BRUT))

SRCS_LIST_PUSH_SWAP_P	=	$(addprefix $(SRCS_DIR_PUSH_SWAP), $(SRCS_LIST_PUSH_SWAP_BRUT))

SRCS_LIST_CHECKER		=	\
							$(SRCS_LIST_COMMONS) \
							$(SRCS_LIST_CHECKER_P) \

SRCS_LIST_PUSH_SWAP		=	\
							$(SRCS_LIST_COMMONS) \
							$(SRCS_LIST_PUSH_SWAP_P) \

SRCS_CHECKER			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST_CHECKER))

SRCS_PUSH_SWAP			=	$(addprefix $(SRCS_DIR_PERF), $(SRCS_LIST_PUSH_SWAP))

# *** OBJS ******************************************************************* #

OBJS_DIR				=	./objs/

OBJS_DIR_CHECKER		=	$(addprefix $(OBJS_DIR), checker/)

OBJS_DIR_PUSH_SWAP		=	$(addprefix $(OBJS_DIR), push_swap/)

OBJS_LIST_CHECKER		=	$(patsubst %.c, %.o, $(SRCS_LIST_CHECKER))

OBJS_LIST_PUSH_SWAP		=	$(patsubst %.c, %.o, $(SRCS_LIST_PUSH_SWAP))

OBJS_CHECKER			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST_CHECKER))

OBJS_PUSH_SWAP			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST_PUSH_SWAP))

# *** RULES ****************************************************************** #

.PHONY: clean fclean all re norm fclean_checker fclean_push_swap re_checker re_push_swap

all:
	@ make $(NAME_CHECKER) -j
	@ make $(NAME_PUSH_SWAP) -j

$(NAME_CHECKER): $(SRCS_CHECKER)
	@ $(CC) $(FLAGS) $(HDIR) $(SRCS_CHECKER) -o $@
	@ printf "\033[31m Program \033[32m$(NAME_CHECKER) : \033[34mCompilation succeed\033[0m                           \n"; \

$(NAME_PUSH_SWAP): $(SRCS_PUSH_SWAP)
	@ $(CC) $(FLAGS) $(HDIR) $(SRCS_PUSH_SWAP) -o $@
	@ printf "\033[31m Program \033[32m$(NAME_PUSH_SWAP) : \033[34mCompilation succeed\033[0m                           \n"; \

# $(NAME_CHECKER): $(SRCS_CHECKER)
# 	@ mkdir -p $(OBJS_DIR)
# 	@ mkdir -p $(OBJS_DIR_CHECKER)
# 	@ for src in $(SRCS_LIST_CHECKER) ; do \
# 		mkdir -p `echo "$(addprefix $(OBJS_DIR), $$src)" | sed -e 's/[a-zA-Z0-9\_\-]*\.c//'`; \
# 		$(CC) $(FLAGS) $(HDIR) -D BONUS=$(BONUS_FLAG) -c -o `echo $(addprefix $(OBJS_DIR), $$src) | sed -e 's/\.c/\.o/'` $(addprefix $(SRCS_DIR), $$src); \
# 		printf "\033[31m Program \033[32m$(NAME_CHECKER) : \033[34mCompilation of \033[36m%-40s\033[0m\r" $(notdir $$src); \
# 	done
# 	@ $(CC) $(FLAGS) $(HDIR) $(OBJS_CHECKER) -o $@
# 	@ printf "\033[31m Program \033[32m$(NAME_CHECKER) : \033[34mCompilation succeed\033[0m                           \n"; \
#
# $(NAME_PUSH_SWAP): $(SRCS_PUSH_SWAP)
# 	@ mkdir -p $(OBJS_DIR)
# 	@ mkdir -p $(OBJS_DIR_PUSH_SWAP)
# 	@ for src in $(SRCS_LIST_PUSH_SWAP) ; do \
# 		mkdir -p `echo "$(addprefix $(OBJS_DIR), $$src)" | sed -e 's/[a-zA-Z0-9\_\-]*\.c//'`; \
# 		$(CC) $(FLAGS) $(HDIR) -D BONUS=$(BONUS_FLAG) -c -o `echo $(addprefix $(OBJS_DIR), $$src) | sed -e 's/\.c/\.o/'` $(addprefix $(SRCS_DIR), $$src); \
# 		printf "\033[31m Program \033[32m$(NAME_PUSH_SWAP) : \033[34mCompilation of \033[36m%-40s\033[0m\r" $(notdir $$src); \
# 	done
# 	@ $(CC) $(FLAGS) $(HDIR) $(OBJS_PUSH_SWAP) -o $@
# 	@ printf "\033[31m Program \033[32m$(NAME_PUSH_SWAP) : \033[34mCompilation succeed\033[0m                           \n"; \

bonus:
	@make fclean
	@make -j BONUS_FLAG=1

norm:
	@ norminette $(HEADER_DIR)



clean:
	@ rm -rf $(OBJS_DIR)

fclean: clean
	@ rm -f $(NAME_CHECKER)
	@ rm -f $(NAME_PUSH_SWAP)

fclean_checker: clean
	@ rm -f $(NAME_CHECKER)

fclean_push_swap: clean
	@ rm -f $(NAME_PUSH_SWAP)



re: fclean
	@ make -j

re_checker: fclean_checker
	@ make $(NAME_CHECKER) -j

re_push_swap: fclean_push_swap
	@ make $(NAME_PUSH_SWAP) -j

# **************************************************************************** #
