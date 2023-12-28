/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:52:51 by darotche          #+#    #+#             */
/*   Updated: 2023/05/31 16:05:01 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*hay, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)hay);
	while ((hay[i] != '\0') && i < len)
	{
		if (hay[i] == needle[0])
		{
			j = 0;
			while (i + j < len && hay[i + j] == needle[j] && needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)hay + i);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
//     char haystack[] = "underworld";
//     char needle[] = "under";
//     // Mine
//     char *c = ft_strnstr(haystack, needle, 0);
//     printf("%s\n", c);
//     // //Original
//     // char *d = strnstr(haystack, needle, 0);
//     // printf("%s\n", d);
// }