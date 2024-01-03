/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:50:25 by darotche          #+#    #+#             */
/*   Updated: 2023/05/27 21:29:48 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void    ft_putchar_fd(char c, int fd)
// {
//     if (fd < 0)
//         return;
//     write(fd, &c, 1);
// }

// void    ft_putstr_fd(char   *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		ft_putchar_fd(s[i], 1);
// 		i++;
// 	}
// }

void	ft_putendl_fd(char	*s, int fd)
{
	if (fd < 0)
		return ;
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

// int main()
// {
//     char    s[] = "Hello!";
//     ft_putendl_fd(s, 1);    
// }
