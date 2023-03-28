/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:57:01 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/28 20:20:23 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"
#include <stdio.h>

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

void	checker_res(int flag, t_stack **a, t_stack **b)
{
	if (flag == -1)
		write(1, "Error\n", 6);
	else if (check_sorted(a) && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	check_one_command(char *buff, t_stack **a, t_stack **b)
{
	if (ft_strcmp(buff, "sa\n") == 0)
		sa(a, 2);
	else if (ft_strcmp(buff, "sb\n") == 0)
		sb(b, 2);
	else if (ft_strcmp(buff, "ss\n") == 0)
		ss(a, b, 2);
	else if (ft_strcmp(buff, "pa\n") == 0)
		pa(a, b, 2);
	else if (ft_strcmp(buff, "pb\n") == 0)
		pb(a, b, 2);
	else if (ft_strcmp(buff, "ra\n") == 0)
		ra(a, 2);
	else if (ft_strcmp(buff, "rb\n") == 0)
		rb(b, 2);
	else if (ft_strcmp(buff, "rr\n") == 0)
		rr(a, b, 2);
	else if (ft_strcmp(buff, "rra\n") == 0)
		rra(a, 2);
	else if (ft_strcmp(buff, "rrb\n") == 0)
		rrb(b, 2);
	else if (ft_strcmp(buff, "rrr\n") == 0)
		rrr(a, b, 2);
	else
		return (-1);
	return (0);
}

void	read_all_command(t_stack **a, t_stack **b)
{	
	char	buff[10];
	int		flag;
	int		n_read;

	flag = 0;
	n_read = 0;
	while (1)
	{
		n_read = read(0, buff, 10);
		if (n_read == 0)
			break ;
		if (n_read > 4)
		{
			flag = -1;
			break ;
		}
		buff[n_read] = '\0';
		flag = check_one_command(buff, a, b);
		if (flag == -1)
			break ;
	}
	checker_res(flag, a, b);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_info		info;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		if (check_ac_av(ac, av, &a) == FAIL)
		{
			ft_lstclear(&a);
			return (error_msg());
		}
		init_info(&a, &info);
		init_order(&a, &info);
		read_all_command(&a, &b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
