/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:50:50 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 16:54:04 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// a스택 첫 두 요소 교환
void	sa(t_stack **a, int flag)
{
	int		up[2];
	int		down[2];
	t_stack	*tmp;

	if (flag == 0)
		write(1, "sa\n", 3);
	tmp = *a;
	if (!tmp || !tmp->next)
		return ;
	up[0] = tmp->value;
	up[1] = tmp->order;
	tmp = tmp->next;
	down[0] = tmp->value;
	down[1] = tmp->order;
	tmp->value = up[0];
	tmp->order = up[1];
	(*a)->value = down[0];
	(*a)->order = down[1];
}

// b스택 첫 두 요소 교환
void	sb(t_stack **b, int flag)
{
	int		up[2];
	int		down[2];
	t_stack	*tmp;

	if (flag == 0)
		write(1, "sb\n", 3);
	tmp = *b;
	if (!tmp || !tmp->next)
		return ;
	up[0] = tmp->value;
	up[1] = tmp->order;
	tmp = tmp->next;
	down[0] = tmp->value;
	down[1] = tmp->order;
	tmp->value = up[0];
	tmp->order = up[1];
	(*b)->value = down[0];
	(*b)->order = down[1];
}

// sa, sb 동시 실행
void	ss(t_stack **a, t_stack **b, int flag)
{
	if (flag == 1)
		write(1, "ss\n", 3);
	sa(a, flag);
	sb(b, flag);
}

// b스택 첫 요소 a스택 맨 위에 넣기
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	write(1, "pa\n", 3);
	tmp = *b;
	if (!tmp)
		return ;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
}

// a스택 첫 요소 b스택 맨 위에 넣기
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	write(1, "pb\n", 3);
	tmp = *a;
	if (!tmp)
		return ;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
}
