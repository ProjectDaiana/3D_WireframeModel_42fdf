/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:57:07 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:26:41 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (n == 0 || dest == src)
		return (dest);
	if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
// 	char Like[10] = { "ILikeYou" };
// 	char Hate[10] = { "IHateyou" };
// 	char str[] = "12345678";
//     // Original
//     printf("Original memmove:\n");
//     printf("memmove before: %s\n", Like);
//     memmove(Like, Hate, 4);
//     printf("memmove after: %s\n\n", Like);
//     printf("memmove before: %s\n", str);
//     memmove(str+3, str+1, 3);
//     printf("memmove after: %s\n\n", str);
//     // Mine
//     printf("Mine:\n");
// 	printf("memmove before : %s\n", Like);
// 	ft_memmove(Like, Hate, 4);
// 	printf("memmove after : %s\n\n", Like);
// 	printf("memmove before : %s\n", str);
// 	ft_memmove(str+3, str +1, 3);
// 	printf("memmove after : %s\n", str);
// 	return 0;
// }
