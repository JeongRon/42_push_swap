/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:50:55 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 16:21:11 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// a스택 모든 요소 한칸씩 밑으로 이동
void	rra(t_stack **a, int flag)
{
	t_stack	*curr;
	t_stack	*pre;

	curr = *a;
	if (!curr || !curr->next)
		return ;
	while (curr->next)
	{
		pre = curr;
		curr = curr->next;
	}
	pre->next = NULL;
	curr->next = *a;
	*a = curr;
	if (flag == 0)
		write(1, "rra\n", 4);
}

// b스택 모든 요소 한칸씩 밑으로 이동
void	rrb(t_stack **b, int flag)
{
	t_stack	*curr;
	t_stack	*pre;

	curr = *b;
	if (!curr || !curr->next)
		return ;
	while (curr->next)
	{
		pre = curr;
		curr = curr->next;
	}
	pre->next = NULL;
	curr->next = *b;
	*b = curr;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

// rra, rrb 동시 실행
void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, flag);
	rrb(b, flag);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
