/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:49:49 by darotche          #+#    #+#             */
/*   Updated: 2023/05/29 14:36:06 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
		lst = NULL;
	}
}

// void del_content(void *content)
// {
//     free(content);
// }
// #include <stdio.h>
// int	main()
// {
// 	char *str1 = malloc(2);
// 	char *str2 = malloc(2);
// 	char *str3 = malloc(2);

// 	*str1 = 'a';
// 	*str2 = 'b';
// 	*str3 = 'c';
// 	t_list *a = ft_lstnew(str1);
// 	t_list *b = ft_lstnew(str2);
// 	t_list *c = ft_lstnew(str3);
//     //Print list
// 	ft_lstadd_back(&a,b);
// 	ft_lstadd_back(&a,c);
// 	printf("\033[0;33m%s\n\033[0m", a->content);
// 	printf("\033[0;33m%s\n\033[0m", b->content);
// 	printf("\033[0;33m%s\n\033[0m", c->content);
// 	//Delete and print list again 
// 	//ft_lstclear(&a, del_content);
// 		printf("\033[0;34m%s\n\033[0m", a->content);
// 		printf("\033[0;34m%p\n\033[0m", a->next);
// 		printf("\033[0;35m%s\n\033[0m", b->content);
// 	 	printf("\033[0;35m%p\n\033[0m", b->next);
// 		printf("\033[0;32m%s\n\033[0m", c->content);
// 		printf("\033[0;32m%s\n\033[0m", c->next);
// }
