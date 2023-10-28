
NAME	=	philo

CC		=	gcc
INCLUDE	= 	inc
CFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDE) -fsanitize=thread -g3
RM		=	rm -f

LIB	=	-lpthread
SRCS	=	src/ft_atoi.c \
		src/main.c \
		src/philosophers.c \
		src/routine.c \
		src/time.c \
		src/utils.c 

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
			@echo "Linked into executable \033[0;32mphilo\033[0m."

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(OBJS)
			@echo "Removed object files."

fclean:		clean
			@$(RM) $(NAME)
			@echo "Removed excutable."

re:			fclean all

.PHONY:		all clean fclean re
