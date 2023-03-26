/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:50:53 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 11:44:52 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*tmp;

	tmp = *a;
	if (!tmp || !tmp->next)
		return ;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int flag)
{
	t_stack	*tmp;

	tmp = *b;
	if (!tmp || !tmp->next)
		return ;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, flag);
	rb(b, flag);
	if (flag == 1)
		write(1, "rr\n", 3);
}
