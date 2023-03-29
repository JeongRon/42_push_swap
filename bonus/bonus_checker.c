/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:57:01 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 20:26:59 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

// str과 명령어가 같은지 비교하는 함수 
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// 한 줄 읽어 온 str이 명령어인지 확인 하는 함수
int	run_one_command(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 2);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 2);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 2);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b, 2);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(a, b, 2);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 2);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 2);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, 2);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 2);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 2);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 2);
	else
		return (ERROR);
	return (SUCCESS);
}

// 한 줄씩 계속 읽으면서 읽은 명령어들을 처리하는 함수
void	read_all_command(t_stack **a, t_stack **b)
{	
	char	*str;
	int		flag;

	flag = SUCCESS;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			flag = FAIL;
			break ;
		}
		flag = run_one_command(str, a, b);
		if (flag == ERROR)
			break ;
		free(str);
	}
	free(str);
	if (flag == ERROR)
		error_msg();
	else if (check_sorted(a) && ft_lstsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

// bonus checker 메인 함수
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
