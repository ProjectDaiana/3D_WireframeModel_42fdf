/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:46:49 by darotche          #+#    #+#             */
/*   Updated: 2023/05/29 16:38:09 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)(s + len));
	while (len)
	{
		if (s[len - 1] == (char)c)
			return ((char *)&s[len - 1]);
		len--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char s[] = "a1a2a3b1a4b2a5";
//     char *c = ft_strrchr(s, 'b');
//     // Mine
//     printf("%s\n", c);
//     //Original
//     char *d = strrchr(s, 'b');
//     printf("%s\n", d);
// }