/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:28:18 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 16:49:25 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 가장 작은 value값에 해당 order를 넣는 함수
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

// value값에 따라서 order순서 매기는 함수 
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

// info 구조체 값 초기화 하는 함수
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
