/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:43:16 by darotche          #+#    #+#             */
/*   Updated: 2023/05/31 17:11:47 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;

	i = 0;
	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	subs = (char *) malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

// #include <stdio.h>
// int main(void)
// {
//     const char s[] = "1234567890abc";
//     printf("%s\n", ft_substr(s, 11, 12));
// }