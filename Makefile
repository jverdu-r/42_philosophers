# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 16:10:33 by jverdu-r          #+#    #+#              #
#    Updated: 2023/04/03 16:32:41 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc
INCLUDE	= 	includes
CFLAGS	=	-Wall -Werror -Wextra -I$(INCLUDE)
RM		=	rm -f

SRCS	=	src/load.c \
				src/philo_skills.c \
				src/philo.c \
				src/utils.c \
				src/threads.c

OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
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
