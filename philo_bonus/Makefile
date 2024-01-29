# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 15:52:10 by jverdu-r          #+#    #+#              #
#    Updated: 2024/01/25 17:29:07 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = philo.c \
		utils.c \
		init.c \
		main.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3
#FLAGS = -Wall -Wextra -Werror -pthread
#FLAGS = -Wall -Wextra -Werror -g -fsanitize=thread 
#FLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	die_after_fork=0 $(CC) $(FLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%.o : %.c
	die_after_fork=0 $(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
