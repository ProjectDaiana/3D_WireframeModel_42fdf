/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:45:07 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:28:04 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*news;
	size_t			i;

	i = 0;
	news = (unsigned char *)s;
	while (i < n)
	{
		news[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// int main(void)
// {
//     char str[24];
//     int c = '*';
//     ft_memset(str, c, 24);
//     printf("str = %s\n", str);
// }
