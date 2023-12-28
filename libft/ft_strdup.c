/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:17:03 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:14:05 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char		*str;
	int			len;
	int			i;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int main()
// {
//     printf("%s", ft_strdup("hola"));
// }