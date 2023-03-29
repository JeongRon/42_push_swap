/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:56:23 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 19:48:26 by jeongrol         ###   ########.fr       */
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

// 문자열 길이 반환 함수
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// 문자열을 숫자로 바꿔주는 함수
long long	ft_atoi(char *s)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	i = 0;
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (sign * result);
}

// 에러 메시지 표시 함수
int	error_msg(void)
{
	write(2, "Error\n", 6);
	return (0);
}
