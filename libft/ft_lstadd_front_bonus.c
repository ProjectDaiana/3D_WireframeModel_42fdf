/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:45:32 by darotche          #+#    #+#             */
/*   Updated: 2023/05/29 14:47:18 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
// #include <stdio.h>
// int main ()
// {
// 	t_list *a;
// 	t_list *b;
// 	t_list *c;
// 	t_list *d;
// 	a = ft_lstnew("a");
// 	b = ft_lstnew("b");
// 	c = ft_lstnew("c");
// 	d = ft_lstnew("d");
// 	ft_lstadd_front(&a, b);
// 	ft_lstadd_front(&a, c);
// 	ft_lstadd_front(&a, d);
// 	// printf("this is C list: %s\n", c->content);
// 	// printf("this is the next after C: %s\n", (c->next)->content);
// 	while (a)
// 	{
// 		printf("%s\n", (char *)a->content);
// 		a = a->next;
// 	}
// }
// #include <stdio.h>
// void printList(t_list* node)
// {
// 	while (node != NULL) {
// 		printf("%s ", node->name);
// 		node = node->next;
// 	}
// 	printf("\n");
// }
// int main()
// {
// 	// Create an empty linked list
// 	t_list* lst = NULL;
// 	// Create new nodes
// 	t_list* a = malloc(sizeof(t_list));
// 	a->name = "a";
// 	a->next = NULL;
// 	t_list* b = malloc(sizeof(t_list));
// 	b->name = "b";
// 	b->next = NULL;
// 	t_list* c = malloc(sizeof(t_list));
// 	c->name = "c";
// 	c->next = NULL;
// 	t_list* d = malloc(sizeof(t_list));
// 	d->name = "d";
// 	d->next = NULL;
// 	// Add nodes to the front of the list
// 	ft_lstadd_front(&lst, d);
// 	ft_lstadd_front(&lst, c);
// 	ft_lstadd_front(&lst, b);
// 	ft_lstadd_front(&lst, a);
// 	// Print the updated linked list
// 	printf("Linked list after adding nodes at the front: ");
// 	printList(lst);
// 	// Free the memory allocated for the nodes
// 	free(a);
// 	free(b);
// 	free(c);
// 	free(d);
// 	return 0;
// }