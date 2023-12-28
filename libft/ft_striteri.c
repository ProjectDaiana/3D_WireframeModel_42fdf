/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:35:59 by darotche          #+#    #+#             */
/*   Updated: 2023/05/27 21:24:28 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char	*s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static void modify_char(unsigned int i, char *s)
// {
//     s[i] = s[i] + 1;
// }

// #include <stdio.h>
// int main()
// {
//     char s[] = "Hello, world.";
//     ft_striteri(s, modify_char);  
//     printf("\033[0;33m%s\n\033[0m", s);
// }