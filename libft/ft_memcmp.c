/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:05:12 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:10:31 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char		*p1;
	const unsigned char		*p2;
	size_t					i;

	i = 0;
	p1 = (const unsigned char *) ptr1;
	p2 = (const unsigned char *) ptr2;
	while (i < num)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	const char	ptr1[2] = "0";
// 	const char	ptr2[2] = "0";
// 	int result;
// 	result = memcmp(ptr1, ptr2, 2);
// 	printf("Original func = %d \n", result);
// 	ft_memcmp(ptr1, ptr2, 2);
// 	printf("42 func = %d", ft_memcmp(ptr1, ptr2, 2));
// }