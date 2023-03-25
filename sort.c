/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:17:43 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/25 22:50:00 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_ra_command(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	while (1)
	{
		if (info->order_start <= (*stack_a)->order && (*stack_a)->order <= info->order_end)
		{
			pb(stack_a, stack_b);
			break ;
		}
		ra(stack_a, 0);
	}
	if (info->order_center > (*stack_b)->order)
	{
		if (info->play_cnt >= 2 && (info->order_start > (*stack_a)->order || (*stack_a)->order > info->order_end))
			rr(stack_a, stack_b, 1);
		else
			rb(stack_b, 0);
	}
}

void	run_rra_command(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	while (1)
	{
		if (info->order_start <= (*stack_a)->order && (*stack_a)->order <= info->order_end)
		{
			pb(stack_a, stack_b);
			break ;
		}
		rra(stack_a, 0);
	}
	if (info->order_center > (*stack_b)->order)
	{
		rb(stack_b, 0);
	}
}

// 최적화 방법 - 3분의 2 이상 지점에 분포가 많을시? 
int	choose_direction(t_stack **stack_a, t_info *info)
{
	t_stack		*tmp;
	int			standard;
	int			node;
	int			cnt;

	tmp = *stack_a;
	standard = ft_lstsize(*stack_a) / 2;
	node = 1;
	cnt = 0;
	while (tmp)
	{
		if (standard <= node)
			if (info->order_start <= tmp->order && tmp->order <= info->order_end)
				cnt++;
		tmp = tmp->next;
	}
	if (cnt >= (info->play_cnt * 2) / 3)
		return (-1);
	return (1);
}

// a->b 스택으로 보내기 
void	send_a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int	dir;

	dir = 0;
	// section 순으로 보내기
	while (info->section_all >= info->play_section)
	{
		dir = choose_direction(stack_a, info);
		while (info->play_cnt != 0)
		{
			if (dir == 1)
				run_ra_command(stack_a, stack_b, info);
			else
				run_rra_command(stack_a, stack_b, info);
			info->play_cnt--;
		}
		// section 1증가 -> 다른 값들도 갱신
		info->play_section++;
		info->order_start = info->order_end + 1;
		if (info->section_remainder != 0)
		{
			info->order_end += info->section_divide + 1;
			info->section_remainder--;
		}
		else
			info->order_end += info->section_divide;
		info->play_cnt = info->order_end - info->order_start + 1;
		info->order_center = (info->order_end + info->order_start) / 2;
	}
}

int	find_least_com(int find_order, t_stack **stack_b)
{
	t_stack	*tmp;
	int		b_length;
	int		cnt;

	tmp = *stack_b;
	b_length = ft_lstsize(*stack_b);
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

void	run_com(int direction, int find_order, t_stack **stack_a, t_stack **stack_b)
{
	if (direction == 0)
		pa(stack_a, stack_b);
	else if (direction == -1)
	{
		while (1)
		{
			rb(stack_b, 0);
			if ((*stack_b)->order == find_order)
			{
				pa(stack_a, stack_b);
				break ;
			}
		}
	}
	else
	{
		while (1)
		{
			rrb(stack_b, 0);
			if ((*stack_b)->order == find_order)
			{
				pa(stack_a, stack_b);
				break ;
			}
		}
	}
}

// b->a 스택으로 보내기
void	send_b_to_a(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int		find_order;
	int		direction;

	direction = 0;
	find_order = info->length;
	while (find_order != 0)
	{
		direction = find_least_com(find_order, stack_b);
		run_com(direction, find_order, stack_a, stack_b);
		find_order--;
	}
}
