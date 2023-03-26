/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:28:18 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 11:30:07 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_order_one(t_stack **a, int order)
{
	long long	small;
	t_stack		*tmp;

	small = 2147483650;
	tmp = *a;
	while (tmp)
	{
		if (small > tmp->value && tmp->order == 0)
			small = tmp->value;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp)
	{
		if (tmp->value == small)
		{
			tmp->order = order;
			break ;
		}
		tmp = tmp->next;
	}
}

void	init_order(t_stack **a, t_info *info)
{
	int		order;

	order = 1;
	while (order <= info->fish)
	{
		init_order_one(a, order);
		order++;
	}
}

void	init_info(t_stack **a, t_info *info)
{
	info->fish = ft_lstsize(*a);
	info->area = 4;
	info->duty = info->fish / info->area;
	info->extra = info->fish % info->area;
	if (info->extra != 0)
	{
		info->nth_required = info->duty + 1;
		info->extra--;
	}
	else
		info->nth_required = info->duty;
	info->nth_area = 1;
	info->finished = 0;
	if (info->fish <= 100)
		info->chunk = 15;
	else if (info->fish <= 300)
		info->chunk = 20;
	else
		info->chunk = 30;
}
