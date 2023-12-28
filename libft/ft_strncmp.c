/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:07:01 by darotche          #+#    #+#             */
/*   Updated: 2023/08/29 18:49:12 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (s1[i] == s2[i]) && i < n - 1)
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	const char	s1 [] = "AC20";
// 	const char	s2 [] = "AB20jhkabnkabn";
// 	int result;
// 	result = strncmp(s1, s2, 2);
// 	printf("Original func = %d \n", result);
// 	ft_strncmp(s1, s2, 2);
// 	printf("42 func = %d", ft_strncmp(s1, s2, 2));
// }