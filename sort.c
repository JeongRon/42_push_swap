/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:17:43 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/21 21:46:05 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 반환값 (0이면,바로 pb) (-1이면, ra + pb) (1이면, rra + pb) 
int	find_least_command(t_stack **stack_a, t_info *info)
{
	t_stack		*tmp;
	int			cnt;
	int			ra_cnt;
	int			rra_cnt;

	tmp = *stack_a;
	cnt = 0;
	ra_cnt = 0;
	rra_cnt = 0;
	if (info->order_start <= tmp->order && tmp->order <= info->order_end)
		return (0);
	while (tmp)
	{
		if (info->order_start <= tmp->order && tmp->order <= info->order_end)
		{
			if (ra_cnt == 0)
				ra_cnt = cnt;
			else
				rra_cnt = cnt;
		}
		cnt++;
		tmp = tmp->next;
	}
	rra_cnt = ft_lstsize(*stack_a) - rra_cnt;
	if (ra_cnt <= rra_cnt)
		return (-1);
	return (1);
}

void	run_command(int flag, t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	if (flag == 0)
		pb(stack_a, stack_b);
	else if (flag == -1)
	{
		while (1)
		{
			ra(stack_a);
			if (info->order_start <= (*stack_a)->order && (*stack_a)->order <= info->order_end)
			{
				pb(stack_a, stack_b);
				break ;
			}
		}
	}
	else
	{
		while (1)
		{
			rra(stack_a);
			if (info->order_start <= (*stack_a)->order && (*stack_a)->order <= info->order_end)
			{
				pb(stack_a, stack_b);
				break ;
			}
		}
	}
}

// a->b 스택으로 보내기 
void	send_a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int		flag;

	flag = 0;
	// section 순으로 보내기
	while (info->section_all >= info->play_section)
	{
		while (info->play_cnt != 0)
		{
			// ra, rra 중 최단 명령어 찾기
			flag = find_least_command(stack_a, info);
			// 최단 명령어로 실제 동작 (ra || rra) + (pb)
			run_command(flag, stack_a, stack_b, info);
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
	}
}

int	find_least_com(int find_order, t_stack **stack_b, t_info *info)
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

void	run_com(int flag, int find_order, t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	if (flag == 0)
		pa(stack_a, stack_b);
	else if (flag == -1)
	{
		while (1)
		{
			rb(stack_b);
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
			rrb(stack_b);
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
	int		flag;

	flag = 0;
	find_order = info->length;
	while (find_order != 0)
	{
		flag = find_least_com(find_order, stack_b, info);
		run_com(flag, find_order, stack_a, stack_b, info);
		find_order--;
	}
}
