/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:12:51 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/18 22:22:32 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int		up;
	int		down;
	t_stack	*tmp;

	tmp = *stack_a;
	if (!tmp || !tmp->next)
		return ;
	up = tmp->value;
	tmp = tmp->next;
	down = tmp->value;
	tmp->value = up;
	(*stack_a)->value = down;
}

void	sb(t_stack **stack_b)
{
	int		up;
	int		down;
	t_stack	*tmp;

	tmp = *stack_b;
	if (!tmp || !tmp->next)
		return ;
	up = tmp->value;
	tmp = tmp->next;
	down = tmp->value;
	tmp->value = up;
	(*stack_b)->value = down;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (!tmp)
		return ;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (!tmp)
		return ;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
}

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	// 스택 a에 값이 하나도 없거나, 값이 딱 한개 있을 시 그냥 리턴
	if (!tmp || !tmp->next)
		return ;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (!tmp || !tmp->next)
		return ;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
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
}

void	rrb(t_stack **stack_b)
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
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
