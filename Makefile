# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 18:21:08 by jeongrol          #+#    #+#              #
#    Updated: 2023/03/26 11:49:58 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER	=	push_swap.h

SRCS	=	push_swap.c \
			push_swap_util.c \
			check_ac_av.c \
			list_add.c \
			list_malloc.c \
			init_info_order.c \
			sort.c \
			sort_a_to_b.c \
			sort_b_to_a.c \
			sort_mini.c \
			command_p_s.c \
			command_r.c \
			command_rr.c \

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