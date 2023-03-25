/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:22:43 by jeongrol          #+#    #+#             */
/*   Updated: 2023/03/25 22:49:26 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

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

int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_stack	*temp;

	temp = lst;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
