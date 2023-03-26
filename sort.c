/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:17:43 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/26 11:23:37 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 스택이 정렬되어 있는지 확인하는 함수
int	check_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

// 스택 정렬하는 함수
void	sort_stack(t_stack **a, t_stack **b, t_info *info)
{
	if (info->fish > 5)
	{
		send_a_to_b(a, b, info);
		send_b_to_a(a, b, info);
	}
	else
		mini_sort(a, b, info);
}
