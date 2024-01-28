/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:13:58 by darotche          #+#    #+#             */
/*   Updated: 2024/01/28 17:21:33 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hex(unsigned int num, int c)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		len += ft_put_hex(num / 16, c);
		len += ft_put_hex(num % 16, c);
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
