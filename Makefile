# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamrad <ahamrad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 04:05:25 by ahamrad           #+#    #+#              #
#    Updated: 2023/10/15 03:54:06 by ahamrad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread
CC = cc
RM = rm -rf
HEADER = philo.h

SRCS = philo.c parsing.c utils.c utils2.c init.c routine.c 
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o:%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re