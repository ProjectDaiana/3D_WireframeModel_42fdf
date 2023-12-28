/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:57:32 by darotche          #+#    #+#             */
/*   Updated: 2023/05/27 16:00:13 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void    ft_putchar_fd(char c, int fd)
// {
//     if (fd < 0)
//         return;
//     write(fd, &c, 1);
// }
void	ft_putstr_fd(char	*s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
// int	main(void)
// {
//     char    s[] = "Hello!";
//     ft_putstr_fd (s, 1);
// }