/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:07:27 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:06:37 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] != s1[start] && ft_strrchr(set, s1[end]))
		end--;
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}

// #include <stdio.h>
// int main(void)
// {
//     char s[] = "undxxx";
//     char set[] = "xxxxx";
//     char *c = ft_strtrim(s, set);

//     // Mine
//     printf("%s\n", c);

//     free(c);
//     return 0;
// }