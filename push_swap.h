/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:00:24 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/21 21:45:16 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define FAIL 0
# define SUCCESS 1

typedef struct s_stack
{
	int					value;
	int					order;
	int					section;
	struct s_stack		*next;
}	t_stack;

typedef struct s_info
{
	int		length;
	int		section_all;
	int		section_divide;
	int		section_remainder;
	int		order_start;
	int		order_end;
	int		play_section;
	int		play_cnt;
}	t_info;

// list
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);

// command
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// sort
void	send_a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info);
int		find_least_command(t_stack **stack_a, t_info *info);
void	run_command(int flag, t_stack **stack_a, t_stack **stack_b, t_info *info);
void	send_b_to_a(t_stack **stack_a, t_stack **stack_b, t_info *info);
int		find_least_com(int find_order, t_stack **stack_b, t_info *info);
void	run_com(int flag, int find_order, t_stack **stack_a, t_stack **stack_b, t_info *info);

#endif
