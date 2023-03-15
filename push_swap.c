/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:38:39 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/15 19:02:30 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int	check_same_num(long long num, t_stack stack_a)
{
	
}

int	input_num(char *s, t_stack stack_a)
{
	long long	num;
	int			s_len;

	s_len = ft_strlen(s);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s_len == 1)
			return (0); // only - or +
		else if (s_len > 11)
			return (0); // int size number
	}
	else
		if (s_len > 10)
			return (0); // int size number
	num = ft_atoi(s);
	if (-2147483648 <= num && num <= 2147483647)
		if (check_same_num(num, stack_a) == 0) // same_number 
			return (0);
	else
		return (0); // int size number
	return (1);
}

int	check_num(char *s, int start, int end, t_stack stack_a)
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
			return (0); 	// 1. not number (+, - included)
		index++;
	}
	num[index] = '\0';
	if (input_num(num, stack_a) == 0)
		return (0); 	// 2. only (- or +) / same number / int size number
	return (1);
}

int	check_av(char *s, t_stack stack_a)
{
	int	i;
	int	start;

	i = 0;
	start = -1;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (start != -1)
			{
				if (check_num(s, start, i - 1, stack_a) == 0)
					return (0);
				start = -1;
			}
		}
		else
			if (start == -1)
				start = i;
		i++;
	}
	if (start != -1)
		if (check_num(s, start, i - 1, stack_a) == 0)
			return (0);
	return (1);
}

int	check_ac_av(int ac, char **av, t_stack stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_av(av[i], stack_a) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	error_msg(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;

	if (ac >= 2)
	{
		if (check_ac_av(ac, av, stack_a) == 0)
			return (error_msg());

	}
	return (0);
}
