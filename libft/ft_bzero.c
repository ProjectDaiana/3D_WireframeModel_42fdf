/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:04:12 by darotche          #+#    #+#             */
/*   Updated: 2023/05/26 17:40:47 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*news;
	size_t			i;

	news = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		news[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// int main(void)
// {
//     char s[24];
//     ft_bzero(s, 24);
//      for (int i = 0; i < 24; i++)
//      {
//         printf("%d ", s[i]);
//      }
// }