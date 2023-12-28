/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:18:20 by darotche          #+#    #+#             */
/*   Updated: 2023/05/30 18:54:36 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	find;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	find = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char s[] = "underworld";
//     char *c = ft_memchr(s, 'l', 6);
//     // Mine
//     printf("Mine: %s\n", c);

//     //Original
//     char *og = memchr(s, 'l', 6);
//     printf("Original: %s\n", og);
// }