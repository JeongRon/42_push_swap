/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:17:43 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 19:47:59 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
