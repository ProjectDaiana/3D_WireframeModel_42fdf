/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:42:38 by darotche          #+#    #+#             */
/*   Updated: 2023/05/31 15:58:01 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 1;
	if (!lst)
		return (0);
	current = lst;
	while (current->next != 0)
	{
		current = current->next;
		i++;
	}
	return (i);
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
// 	t_list *current = a;
// 	printf("Elements of the list:\n");
// 	while (current)
// 	{
// 		printf("%s\n", (char*)current->content);
// 		current = current->next;
// 	}
// 	printf("\033[0;33mSize of list: %d\n\33[0m", ft_lstsize(a));
// }