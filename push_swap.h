/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:00:24 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/28 20:12:59 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define FAIL 0
# define SUCCESS 1

typedef struct s_stack
{
	int					value;
	int					order;
	struct s_stack		*next;
}	t_stack;

typedef struct s_info
{
	int		fish;
	int		area;
	int		duty;
	int		extra;
	int		nth_area;
	int		nth_required;
	int		finished;
	int		chunk;
}	t_info;

// push_swap_util.c
int			ft_strlen(char *s);
long long	ft_atoi(char *s);
int			error_msg(void);

// check_ac_av.c
int			check_same_num(long long num, t_stack **a);
int			check_input_num(char *s, t_stack **a);
int			check_num(char *s, int start, int end, t_stack **a);
int			check_av(char *s, t_stack **a, int i, int start);
int			check_ac_av(int ac, char **av, t_stack **a);

// list_*.c
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstnew(int value);
void		ft_lstclear(t_stack **lst);

// init_info_order.c
void		init_order(t_stack **a, t_info *info);
void		init_info(t_stack **a, t_info *info);

// sort_*.c
int			check_sorted(t_stack **a);
void		sort_stack(t_stack **a, t_stack **b, t_info *info);
void		run_command(t_stack **a, t_stack **b, t_info *info, int dir);
int			choose_direction(t_stack **a, t_info *info);
void		send_a_to_b(t_stack **a, t_stack **b, t_info *info);
int			find_least_command(int find_order, t_stack **b);
void		run_com(int direction, int find_order, t_stack **a, t_stack **b);
void		send_b_to_a(t_stack **a, t_stack **b, t_info *info);
void		mini_sort_command(t_stack **a, int *arr);
void		mini_check_command(t_stack **a);
void		mini_a_to_b(t_stack **a, t_stack **b, int fish);
void		mini_b_to_a(t_stack **a, t_stack **b, int fish);
void		mini_sort(t_stack **a, t_stack **b, t_info *info);

// command_*.c
void		sa(t_stack **a, int flag);
void		sb(t_stack **b, int flag);
void		ss(t_stack **a, t_stack **b, int flag);
void		pa(t_stack **a, t_stack **b, int flag);
void		pb(t_stack **a, t_stack **b, int flag);
void		ra(t_stack **a, int flag);
void		rb(t_stack **b, int flag);
void		rr(t_stack **a, t_stack **b, int flag);
void		rra(t_stack **a, int flag);
void		rrb(t_stack **b, int flag);
void		rrr(t_stack **a, t_stack **b, int flag);

#endif
