/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:38:39 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 20:23:35 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push_swap 메인 함수
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
		if (check_sorted(&a) == SUCCESS)
		{
			ft_lstclear(&a);
			return (0);
		}
		init_order(&a, &info);
		sort_stack(&a, &b, &info);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
