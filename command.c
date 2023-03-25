/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:12:51 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 06:39:28 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int flag)
{
	int		up[2];
	int		down[2];
	t_stack	*tmp;

	tmp = *stack_a;
	if (!tmp || !tmp->next)
		return ;
	up[0] = tmp->value;
	up[1] = tmp->order;
	tmp = tmp->next;
	down[0] = tmp->value;
	down[1] = tmp->order;
	tmp->value = up[0];
	tmp->order = up[1];
	(*stack_a)->value = down[0];
	(*stack_a)->order = down[1];
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int flag)
{
	int		up[2];
	int		down[2];
	t_stack	*tmp;

	tmp = *stack_b;
	if (!tmp || !tmp->next)
		return ;
	up[0] = tmp->value;
	up[1] = tmp->order;
	tmp = tmp->next;
	down[0] = tmp->value;
	down[1] = tmp->order;
	tmp->value = up[0];
	tmp->order = up[1];
	(*stack_b)->value = down[0];
	(*stack_b)->order = down[1];
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	sa(stack_a, flag);
	sb(stack_b, flag);
	if (flag == 1)
		write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (!tmp)
		return ;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (!tmp)
		return ;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	write(1, "pb\n", 3);
}

void	ra(t_stack **stack_a, int flag)
{
	t_stack	*tmp;

	tmp = *stack_a;
	// 스택 a에 값이 하나도 없거나, 값이 딱 한개 있을 시 그냥 리턴
	if (!tmp || !tmp->next)
		return ;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int flag)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (!tmp || !tmp->next)
		return ;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	ra(stack_a, flag);
	rb(stack_b, flag);
	if (flag == 1)
		write(1, "rr\n", 3);
}

void	rra(t_stack **stack_a, int flag)
{
	t_stack	*curr;
	t_stack	*pre;

	curr = *stack_a;
	if (!curr || !curr->next)
		return ;
	while (curr->next)
	{
		pre = curr;
		curr = curr->next;
	}
	pre->next = NULL;
	curr->next = *stack_a;
	*stack_a = curr;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int flag)
{
	t_stack	*curr;
	t_stack	*pre;

	curr = *stack_b;
	if (!curr || !curr->next)
		return ;
	while (curr->next)
	{
		pre = curr;
		curr = curr->next;
	}
	pre->next = NULL;
	curr->next = *stack_b;
	*stack_b = curr;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rra(stack_a, flag);
	rrb(stack_b, flag);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
