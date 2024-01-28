/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:14:24 by darotche          #+#    #+#             */
/*   Updated: 2024/01/28 17:21:37 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_hexlong(unsigned long num, int c)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		len += ft_put_hexlong(num / 16, c);
		len += ft_put_hexlong(num % 16, c);
	}
	if (num < 16)
	{
		if (num > 9)
		{
			if (c == 1)
				len += ft_putchar(num + 55);
			else
				len += ft_putchar(num + 87);
		}
		else
			len += ft_putchar(num + 48);
	}
	return (len);
}

int	ft_put_adr(unsigned long n)
{
	int	len;

	if (n == 0)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += ft_put_hexlong(n, 0);
	return (len);
}
