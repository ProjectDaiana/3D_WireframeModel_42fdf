/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:01:20 by darotche          #+#    #+#             */
/*   Updated: 2023/05/31 15:41:44 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// int main()
// {
// 	t_list *a;
// 	t_list *b;
// 	t_list *c;
// 	t_list *d;
// 	t_list *e;

// 	a = ft_lstnew("a");
// 	b = ft_lstnew("b");
// 	c = ft_lstnew("c");
// 	d = ft_lstnew("d");
// 	e = ft_lstnew("e");
// 	ft_lstadd_back(&a, b); // Then add "b"
// 	ft_lstadd_back(&a, c); // Then add "c"
// 	ft_lstadd_back(&a, d); // Add "a" first
// 	ft_lstadd_back(&a, e); // Add "a" first
// 	t_list *current = a;
// 	while (current != NULL)
// 	{
// 		printf("Address: %p, Content: %s\n", current, (char *)current->content);
// 		current = current->next;
// 	}
// 	t_list *last = ft_lstlast(a);

// 	// Print the value of the last node
// 	if (last != NULL)
// 		printf("Last node value: %s\n", (char*)last->content);
// 	else
// 		printf("List is empty.\n");
// 	return 0;
// }