
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *temp;

	temp = lst;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

int ft_lstsize(t_list *lst)
{
	int count;
	t_list *temp;

	temp = lst;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void ft_pb(t_list **node_a, t_list **node_b)
{
	t_list *tmp;
	tmp = *node_a;
	*node_a = (*node_a)->next;
	tmp->next = *node_b;
	*node_b = tmp;
}

int main()
{
	t_list *node_a = NULL;
	t_list *node_b = NULL;
	int i;
	int ac = 5;
	char *av[] = {"a.out", "aa", "bb", "cc", "dd"};

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(&node_a, ft_lstnew(av[i]));
		i++;
	}
	ft_pb(&node_a, &node_b);
	ft_pb(&node_a, &node_b);
	printf("----node_a-----\n");
	while (node_a)
	{
		printf("%s\n", node_a->content);
		node_a = node_a->next;
	}
	printf("----node_b-----\n");
	while (node_b)
	{
		printf("%s\n", node_b->content);
		node_b = node_b->next;
	}
	return (0);
}
