/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:38:39 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/18 23:07:23 by jeongrol         ###   ########.fr       */
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

// stack_a 에서 숫자 중복 확인, 숫자 추가 
int	check_same_num(long long num, t_stack **stack_a)
{
	t_stack	*tmp_stack;
	int		tmp_num;

	tmp_stack = *stack_a;
	tmp_num = (int)num;
	while (tmp_stack) // 숫자 중복 확인
	{
		if (tmp_num == tmp_stack -> value)
			return (FAIL);
		tmp_stack = tmp_stack -> next;
	}
	ft_lstadd_back(stack_a, ft_lstnew(tmp_num)); // 리스트에 숫자 추가
	return (SUCCESS);
}

int	input_num(char *s, t_stack **stack_a)
{
	long long	num;
	int			s_len;

	s_len = ft_strlen(s);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s_len == 1)
			return (FAIL); // only - or +
		else if (s_len > 11)
			return (FAIL); // int size number
	}
	else
		if (s_len > 10)
			return (FAIL); // int size number
	num = ft_atoi(s);
	if (-2147483648 <= num && num <= 2147483647)
	{
		if (check_same_num(num, stack_a) == FAIL) // same_number 
			return (FAIL);
	}
	else
		return (FAIL); // int size number
	return (SUCCESS);
}

int	check_num(char *s, int start, int end, t_stack **stack_a)
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
			return (FAIL); 	// 1. not number (+, - included)
		index++;
	}
	num[index] = '\0';
	if (input_num(num, stack_a) == FAIL)
		return (0); 	// 2. only (- or +) / same number / int size number
	return (SUCCESS);
}

int	check_av(char *s, t_stack **stack_a)
{
	int	i;
	int	start;

	i = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (start != -1)
			{
				if (check_num(s, start, i - 1, stack_a) == FAIL)
					return (FAIL);
				start = -1;
			}
		}
		else
			if (start == -1)
				start = i;
		i++;
	}
	if (start != -1 && check_num(s, start, i - 1, stack_a) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_ac_av(int ac, char **av, t_stack **stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_av(av[i], stack_a) == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	error_msg(void)
{
	write(2, "Error\n", 6);
	return (0);
}

#include <stdio.h>

void	leak_check(void)
{
	system("leaks --list a.out");
}

void	make_order_one(t_stack **stack_a, int order)
{
	long long	small;
	t_stack		*tmp;

	small = 2147483650;
	tmp = *stack_a;
	while (tmp)
	{
		if (small > tmp->value && tmp->order == 0)
			small = tmp->value;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == small)
		{
			tmp->order = order;
			break ;
		}
		tmp = tmp->next;
	}
}

void	make_order(t_stack **stack_a, t_info info)
{
	int		order;
	t_stack	*tmp;

	info.length = ft_lstsize(*stack_a);
	order = 1;
	while (order <= info.length)
	{
		tmp = *stack_a;
		make_order_one(stack_a, order);
		order++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	info;
	t_stack	*buff_a;
	t_stack	*buff_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		if (check_ac_av(ac, av, &stack_a) == FAIL)
		{
			ft_lstclear(&stack_a);
			return (error_msg());
		}
		make_order(&stack_a, info);
	}
	/*
	sa(&stack_a);
	sb(&stack_b);
	ss(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ra(&stack_a);
	rb(&stack_b);
	rr(&stack_a, &stack_b);
	rra(&stack_a);
	rrb(&stack_b);
	rrr(&stack_a, &stack_b);
	*/
	// // 출력 확인
	// sa(&stack_a);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// sa(&stack_a);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);


	buff_a = stack_a;
	buff_b = stack_b;
	while (buff_a)
	{
		printf("%d  %d\n", buff_a->value, buff_a->order);
		buff_a = buff_a -> next;
	}
	// printf("stack_a : ");
	// while (buff_a)
	// {
	// 	printf("%d  ", buff_a -> value);
	// 	buff_a = buff_a -> next;
	// }
	// printf("\n");
	// printf("stack_b : ");
	// while (buff_b)
	// {
	// 	printf("%d  ", buff_b -> value);
	// 	buff_b = buff_b -> next;
	// }
	ft_lstclear(&stack_a);
	atexit(leak_check);
	return (0);
}
