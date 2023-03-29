# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 18:21:08 by jeongrol          #+#    #+#              #
#    Updated: 2023/03/29 20:03:18 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER	=	push_swap.h
BONUS_HEADER = bonus_checker.h

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
			
BONUS_SRCS = 	bonus_checker.c \
				bonus_gnl.c \
				bonus_gnl_util.c \
				push_swap_util.c \
				check_ac_av.c \
				list_add.c \
				list_malloc.c \
				init_info_order.c \
				command_p_s.c \
				command_r.c \
				command_rr.c \

OBJS	=	$(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	
fclean:	clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re:
	make fclean
	make all

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

.PHONY:	all clean fclean re bonus