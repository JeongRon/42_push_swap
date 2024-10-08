/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:21:36 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 22:36:49 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 현재 찾고 있는 생선 위치를 파악, 가장 적은 명령어 확인하는 함수 
int	find_least_command(int find_order, t_stack **b)
{
	t_stack	*tmp;
	int		b_length;
	int		cnt;

	tmp = *b;
	b_length = ft_lstsize(*b);
	cnt = 1;
	if (tmp->order == find_order)
		return (0);
	while (tmp)
	{
		if (tmp->order == find_order)
			break ;
		cnt++;
		tmp = tmp->next;
	}
	if (cnt <= b_length / 2 + 1)
		return (-1);
	else
		return (1);
}

// direction값에 따라 연속 rb,rrb 실행하다 찾고 있는 생선이 나오면 pa 하는 함수
void	run_com(int direction, int find_order, t_stack **a, t_stack **b)
{
	if (direction == 0)
		pa(a, b, 1);
	else
	{
		while (1)
		{
			if (direction == -1)
				rb(b, 0);
			else
				rrb(b, 0);
			if ((*b)->order == find_order)
			{
				pa(a, b, 1);
				break ;
			}
		}
	}
}

// b->a 스택으로 보내기
void	send_b_to_a(t_stack **a, t_stack **b, t_info *info)
{
	int		find_order;
	int		direction;

	direction = 0;
	find_order = info->fish;
	while (find_order != 0)
	{
		direction = find_least_command(find_order, b);
		run_com(direction, find_order, a, b);
		find_order--;
	}
}
