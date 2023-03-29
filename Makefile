# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 18:21:08 by jeongrol          #+#    #+#              #
#    Updated: 2023/03/29 22:42:23 by jeongrol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEADER	=	mandatory/push_swap.h
BONUS_HEADER = bonus/bonus_checker.h

SRCS	=	mandatory/push_swap.c \
			mandatory/utils/push_swap_util.c \
			mandatory/utils/check_ac_av.c \
			mandatory/utils/init_info_order.c \
			mandatory/linked_list/list_add.c \
			mandatory/linked_list/list_malloc.c \
			mandatory/sort/sort.c \
			mandatory/sort/sort_a_to_b.c \
			mandatory/sort/sort_b_to_a.c \
			mandatory/sort/sort_mini.c \
			mandatory/command/command_p_s.c \
			mandatory/command/command_r.c \
			mandatory/command/command_rr.c \
			
BONUS_SRCS = 	bonus/bonus_checker.c \
				bonus/bonus_gnl.c \
				bonus/bonus_gnl_util.c \
				mandatory/utils/push_swap_util.c \
				mandatory/utils/check_ac_av.c \
				mandatory/utils/init_info_order.c \
				mandatory/linked_list/list_add.c \
				mandatory/linked_list/list_malloc.c \
				mandatory/command/command_p_s.c \
				mandatory/command/command_r.c \
				mandatory/command/command_rr.c \

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
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(BONUS_OBJS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

.PHONY:	all clean fclean re bonus