# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 18:21:08 by jeongrol          #+#    #+#              #
#    Updated: 2023/03/25 22:49:32 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER	=	push_swap.h

SRCS	=	push_swap.c list.c command.c sort.c

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re