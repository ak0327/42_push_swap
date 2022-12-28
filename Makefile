# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takira <takira@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 22:06:07 by takira            #+#    #+#              #
#    Updated: 2022/12/14 22:06:07 by takira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP

ifdef WITH_TEST
#	CFLAGS		+= -g -fsanitize=address -fsanitize=undefined
	CFLAGS		+= -D LESKS
endif


# MANDATORY
NAME		= push_swap

VPATH		= $(SRC_DIR)
SRC_DIR		= ./srcs
SRC			= main.c \
			  ft_stack.c \
			  ft_stack_add.c \
			  ft_stack_get.c \
			  operation_cmd.c \
			  operation_controller.c \
			  operation_single.c \
			  operation_double.c \
			  preprocess.c \
			  exec_sort.c \
			  get_cost.c \
			  optimize_cmd.c \
			  print_for_debug.c \
			  utils.c \
			  push_num_x2y.c \
			  push_num_controller.c \
			  get_cost_helper.c \
			  get_idx.c \





SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ_DIR		= ./objs
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
DEPS		= $(OBJS:%.o=%.d) #SRC

INCLUDE_DIR	= ./includes


# BONUS
#BONUS_NAME		= pipex_bonus
B_SRC_DIR		= ./bonus/srcs
B_INCLUDE_DIR	= ./bonus/includes
ifdef WITH_BONUS
#	NAME		= pipex_bonus
	SRC_DIR		= ./bonus/srcs
    SRC			= main_bonus.c \
m.m
    INCLUDE_DIR	= ./bonus/includes
endif


# LIBS
LIB_DIR		= ./lib
LIBFT_DIR	= $(LIB_DIR)/libft
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_DIR)/$(LIBFT_NAME)

LIBGNL_DIR	= $(LIB_DIR)/libgnl
LIBGNL_NAME	= libgnl.a
LIBGNL		= $(LIBGNL_DIR)/$(LIBGNL_NAME)

LIBFTPRINTF_DIR		= $(LIB_DIR)/libftprintf
LIBFTPRINTF_NAME	= libftprintf.a
LIBFTPRINTF			= $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF_NAME)

LIBS_DIR	= $(LIBFT_DIR) $(LIBGNL_DIR) $(LIBFTPRINTF_DIR)
LIBS		= $(LIBFT) $(LIBGNL) $(LIBFTPRINTF)
IFLAGS		= $(addprefix -I, $(INCLUDE_DIR))
LFLAGS		= $(addprefix -L, $(LIBS_DIR))
LDFLAGS		= $(IFLAGS) $(LFLAGS) $(LIBS)


# RULES
$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBGNL_DIR)
	@make -C $(LIBFTPRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBGNL_DIR)
	@make clean -C $(LIBFTPRINTF_DIR)

fclean:	clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(LIBGNL_DIR)
	@make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

bonus:
	@make WITH_BONUS=1

bonus_test:
	@make WITH_BONUS=1 WITH_TEST=1

test:
	@make re all WITH_TEST=1

norm:
	@norminette -v
	norminette $(SRC_DIR) $(B_SRC_DIR) $(INCLUDE_DIR) $(B_INCLUDE_DIR)

norm_lib:
	@norminette -v
	norminette $(LIB_DIR)

.PHONY:	all clean fclean re test norm bonus

-include		$(DEPS)
