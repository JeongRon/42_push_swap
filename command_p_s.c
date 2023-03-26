/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:50:50 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 10:55:46 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	int		up[2];
	int		down[2];
	t_stack	*tmp;

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
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	int		up[2];
	int		down[2];
	t_stack	*tmp;

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
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, flag);
	sb(b, flag);
	if (flag == 1)
		write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	if (!tmp)
		return ;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	if (!tmp)
		return ;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
	write(1, "pb\n", 3);
}
