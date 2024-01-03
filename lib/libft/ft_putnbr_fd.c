/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:45:16 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:53:47 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * (-1);
		}
		if (n < 10)
		{
			if (n == 0)
				ft_putchar_fd('0', fd);
			else
			{
				n = n + 48;
				ft_putchar_fd(n, fd);
			}
		}
		else if (n >= 10)
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(-2147483648, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(0, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-21474, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(83648, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(1, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-1, 1);
// }