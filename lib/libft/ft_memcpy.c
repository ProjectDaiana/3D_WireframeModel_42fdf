/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:27:44 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:19:26 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
// char src[] = "Hello, world!";
// char dest[sizeof(src)];

// ft_memcpy(dest, src, sizeof(src));

// printf("src: %s\n", src);
// printf("dest: %s\n", dest);

// }