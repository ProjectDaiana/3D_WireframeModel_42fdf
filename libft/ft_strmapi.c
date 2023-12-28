/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:50:34 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:15:09 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// char	modify_char(unsigned int index, char c) {
//     return c + index;
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*newstr;
	size_t		len;
	size_t		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < len)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// #include <stdio.h>
// int main()
// {
//     char const  *s = "Pasta de dientes";
//     char *nstr = ft_strmapi(s, modify_char);
//     printf("Old string: \033[2;31m%s\n\033[0m", s);

//     printf("New string: \033[2;33m%s\n\033[0m", nstr);
//     free(nstr);
//     return(0);
// }