/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:15:54 by darotche          #+#    #+#             */
/*   Updated: 2023/05/29 16:34:18 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char s[] = "underworld";
//     char *c = ft_strchr(s, 'w');
//     // Mine
//     printf("%s\n", c);

//     //Original
//     c = strchr(s, 'w');
//     printf("%s\n", c);
// }