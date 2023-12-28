/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:55:20 by darotche          #+#    #+#             */
/*   Updated: 2023/05/31 17:45:13 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

// #include <stdio.h>
// void print_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int	main ()
// {
// 	t_list *a = ft_lstnew("a");
// 	t_list *b = ft_lstnew("b");
// 	t_list *c = ft_lstnew("c");
// 	t_list *d = ft_lstnew("d");

// 	ft_lstadd_back(&a, b);
// 	ft_lstadd_back(&a, c);
// 	ft_lstadd_back(&a, d);

// 	ft_lstiter(a, print_content);
// }