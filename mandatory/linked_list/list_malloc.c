/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:55:18 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/29 22:37:01 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->order = 0;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*curr;
	t_stack	*next;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr -> next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}
