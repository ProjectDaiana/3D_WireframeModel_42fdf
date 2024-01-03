/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:01:14 by darotche          #+#    #+#             */
/*   Updated: 2023/08/29 20:19:13 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new != NULL)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
	return ;
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
// 	ft_lstadd_back(&a, b);
// 	ft_lstadd_back(&a, c);
// 	ft_lstadd_back(&a, d);
// 	// printf("this is C list: %s\n", c->content);
// 	// printf("this is the next after C: %s\n", (c->next)->content);
// 	while (a)
// 	{
// 		printf("%s\n", (char *)a->content);
// 		a = a->next;
// 	}

// }