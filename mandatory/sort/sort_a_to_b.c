/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:21:28 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 22:36:52 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 3가지 조건에 맞게 명령어를 실행하는 함수
void	run_command(t_stack **a, t_stack **b, t_info *info, int dir)
{
	while ((*a)->order > info->finished + info->chunk)
	{
		if (dir == 1)
			ra(a, 0);
		else if (dir == -1)
			rra(a, 0);
	}
	if ((*a)->order < info->finished)
		pb(a, b, 1);
	else
	{
		pb(a, b, 1);
		rb(b, 0);
	}
}

// 만일 뒤쪽 부분에 3분의 2이상 작업물이 존재하면, 컨베이어 방향을 rra로 돌리기 
int	choose_direction(t_stack **a, t_info *info)
{
	t_stack		*tmp;
	int			center;
	int			conveyor;
	int			back_cnt;

	tmp = *a;
	center = ft_lstsize(*a) / 2;
	conveyor = 1;
	back_cnt = 0;
	while (tmp)
	{
		if (center <= conveyor)
			if (info->finished < tmp->order && \
				tmp->order < info->finished + info->nth_required)
				back_cnt++;
		tmp = tmp->next;
		conveyor++;
	}
	if (back_cnt >= (info->nth_required * 2) / 3)
		return (-1);
	return (1);
}

// a->b 스택으로 보내기 
void	send_a_to_b(t_stack **a, t_stack **b, t_info *info)
{
	int	dir;

	dir = 0;
	while (info->area >= info->nth_area)
	{
		dir = choose_direction(a, info);
		while (info->nth_required != 0)
		{
			run_command(a, b, info, dir);
			info->nth_required--;
			info->finished++;
		}
		info->nth_area++;
		if (info->extra != 0)
		{
			info->nth_required = info->duty + 1;
			info->extra--;
		}
		else
			info->nth_required = info->duty;
	}
}
