CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c			\
	   utils.c				\
	   manage_stack.c		\
	   control_error.c		\
	   actions_1.c			\
	   action_in_stack.c

NAME = push_swap

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
