/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:20:37 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 16:48:49 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (mini) 3개 숫자를 최적으로 정렬하는 함수
void	mini_sort_command(t_stack **a, int *arr)
{
	if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		sa(a, 0);
		ra(a, 0);
	}
	else if (arr[1] < arr[0] && arr[1] < arr[2])
	{
		if (arr[0] < arr[2])
			sa(a, 0);
		else
			ra(a, 0);
	}
	else
	{
		if (arr[0] > arr[1])
			sa(a, 0);
		ra(a, 0);
		ra(a, 0);
	}
}

// (mini) 3개 숫자의 순서를 찾고, 정렬하는 함수
void	mini_check_command(t_stack **a)
{
	t_stack	*tmp;
	int		arr[3];
	int		index;

	tmp = *a;
	index = 0;
	if (check_sorted(a) == SUCCESS)
		return ;
	while (tmp)
	{
		arr[index] = tmp->order;
		index++;
		tmp = tmp->next;
	}
	mini_sort_command(a, arr);
}

// (mini) a->b스택으로 이동하는 함수
void	mini_a_to_b(t_stack **a, t_stack **b, int fish)
{
	int		catch_order;
	int		cnt;

	catch_order = fish - 3;
	cnt = fish - 3;
	while (cnt != 0)
	{
		if ((*a)->order <= catch_order)
		{
			pb(a, b);
			cnt--;
		}
		else
			ra(a, 0);
	}
}

// (mini) b->a스택으로 이동하는 함수
void	mini_b_to_a(t_stack **a, t_stack **b, int fish)
{
	if (fish == 5)
		pa(a, b);
	pa(a, b);
	if (check_sorted(a) == FAIL)
		sa(a, 0);
}

// (mini) 5개 이하의 숫자가 들어온 스택 정렬하는 함수
void	mini_sort(t_stack **a, t_stack **b, t_info *info)
{
	if (info->fish == 2)
		sa(a, 0);
	else if (info->fish == 3)
		mini_check_command(a);
	else
	{
		mini_a_to_b(a, b, info->fish);
		mini_check_command(a);
		mini_b_to_a(a, b, info->fish);
	}
}
