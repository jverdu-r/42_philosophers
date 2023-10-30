# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 15:50:02 by jverdu-r          #+#    #+#              #
#    Updated: 2023/10/30 15:50:04 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c \
		utils.c \
		init.c \
		philo.c \
		free.c \

CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
#FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
