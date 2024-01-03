/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:09:27 by darotche          #+#    #+#             */
/*   Updated: 2023/10/07 14:43:33 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (size -1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	char dest[] = "abcdefghijk";
// 	char src[] = "12345678901234567";

//     ////MY FUNCTION
//     printf("Dest before =%s\n", dest);
//     int len = ft_strlcpy(dest, src, 0);
//     printf("Dest after =%s\n", dest);
//     printf("My result =%d\n", len);

//     ////OG FUNCTION
//     size_t og = strlcpy(dest, src, 0);
//     printf("Orignal strlcpy =%zu\n", og);
// }