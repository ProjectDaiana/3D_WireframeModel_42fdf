/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:33 by darotche          #+#    #+#             */
/*   Updated: 2023/05/31 17:20:45 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*nnode;

	nlst = NULL;
	if (lst && f)
	{
		while (lst)
		{
			nnode = ft_lstnew(f(lst->content));
			if (!nnode)
			{
				ft_lstclear(&nlst, del);
				return (NULL);
			}
			ft_lstadd_back(&nlst, nnode);
			lst = lst->next;
		}
	}
	return (nlst);
}

// void	*f(void *content)
// {
// 	int *num = (int *)content;
// 	int *result = malloc(sizeof(int));
// 	if (!result)
// 		return (NULL);
// 	*result = *num + 1;
// 	return (result);
// }
// #include <stdio.h>

// void	d(void *content)`
// {
// 	free(content);
// }

// int main ()
// {
// 	t_list *node1 = malloc(sizeof(t_list));
// 	node1->content = 1;
// 	t_list *node2 = malloc(sizeof(t_list));
// 	node2->content = 2;
// 	t_list *node3 = malloc(sizeof(t_list));
// 	node3->content = 3;
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = 0;
// 	printf("Initial list: ");
// 	t_list *current = node1;
// 	while (current)
// 	{
// 		printf("%d ", current->content);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	t_list *tmp = ft_lstmap(node1, f, d);
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }