# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 19:45:16 by yujelee           #+#    #+#              #
#    Updated: 2022/08/19 19:45:18 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c			\
	   utils.c				\
	   manage_stack.c		\
	   control_error.c		\
	   actions_1.c			\
	   actions_2.c			\
	   indexing_node.c		\
	   classify_stack.c		\
	   moving.c				\
	   sorting.c			\
	   sorting_utils.c		\
	   action_in_stack.c

BONUS_SRC = push_swap_bonus.c	\
			b_checker_utils.c	\
			utils.c				\
			manage_stack.c		\
			control_error.c		\
			actions_1.c			\
			actions_2.c			\
			indexing_node.c		\
			classify_stack.c	\
			moving.c			\
			sorting.c			\
			sorting_utils.c		\
			action_in_stack.c

NAME = push_swap

BONUS_NAME = checker

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

RM = rm -rf

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean
	make all

.PHONY: all clean fclean re bonus
