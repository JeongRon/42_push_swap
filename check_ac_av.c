/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ac_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:13:37 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/28 20:10:32 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// a리스트 에서 숫자 중복 확인 함수 (맞으면, a리스트에 숫자 추가) 
int	check_same_num(long long num, t_stack **a)
{
	t_stack	*tmp_stack;
	int		tmp_num;

	tmp_stack = *a;
	tmp_num = (int)num;
	while (tmp_stack)
	{
		if (tmp_num == tmp_stack -> value)
			return (FAIL);
		tmp_stack = tmp_stack -> next;
	}
	ft_lstadd_back(a, ft_lstnew(tmp_num));
	return (SUCCESS);
}

// int 범위 숫자인지 확인하는 함수
int	check_input_num(char *s, t_stack **a)
{
	long long	num;
	int			s_len;

	s_len = ft_strlen(s);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s_len == 1)
			return (FAIL);
		else if (s_len > 11)
			return (FAIL);
	}
	else
		if (s_len > 10)
			return (FAIL);
	num = ft_atoi(s);
	if (-2147483648 <= num && num <= 2147483647)
	{
		if (check_same_num(num, a) == FAIL)
			return (FAIL);
	}
	else
		return (FAIL);
	return (SUCCESS);
}

// 문자열이 숫자 인지 확인 하는 함수 (문자 들어 올 시 에러 처리)
int	check_num(char *s, int start, int end, t_stack **a)
{
	char	num[10000];
	int		index;

	index = 0;
	if (s[start] == '-' || s[start] == '+')
	{
		num[index] = s[start];
		index++;
	}
	while (start + index != end + 1)
	{
		if ('0' <= s[start + index] && s[start + index] <= '9')
			num[index] = s[start + index];
		else
			return (FAIL);
		index++;
	}
	num[index] = '\0';
	if (check_input_num(num, a) == FAIL)
		return (0);
	return (SUCCESS);
}

// 입력된 문자열을 space 단위로 끊고, 숫자인지 확인하는 함수
int	check_av(char *s, t_stack **a, int i, int start)
{
	if (!s[i])
		return (FAIL);
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (start != -1)
			{
				if (check_num(s, start, i - 1, a) == FAIL)
					return (FAIL);
				start = -1;
			}
		}
		else
			if (start == -1)
				start = i;
		i++;
	}
	if (start != -1 && check_num(s, start, i - 1, a) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

// 입력된 문자열을 각 av 문자열로 나누어서 확인하는 함수   
int	check_ac_av(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_av(av[i], a, 0, -1) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
