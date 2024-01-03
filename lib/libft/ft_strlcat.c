/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:43:05 by darotche          #+#    #+#             */
/*   Updated: 2023/05/27 17:14:14 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char	*str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] && (dest_len + i) < size -1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>
// #include <bsd/string.h>

// int	main(void)
// {
// 	char dest[] = "1234";
// 	char src[] = "567890123";

// 	char dest2[] = "1234";
// 	char src2[] = "567890123";

// 	//ORIGNAL
// 	size_t og = strlcat(dest, src, 6);
// 	printf("Original strlcat = %zu\n\n", og);

// 	///Mine
//     printf("Dest before = %s\n", dest2);

//     size_t result = ft_strlcat(dest2, src2, 6);
//     printf("Dest after = %s\n", dest2);
//     printf("My result = %zu\n\n", result);	
// }