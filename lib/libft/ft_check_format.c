/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:20:40 by darotche          #+#    #+#             */
/*   Updated: 2024/01/28 17:30:14 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_format(const char i, va_list list, int count)
{
	if (i == '%')
		count += ft_putchar('%');
	else if (i == 'c')
		count += ft_putchar((char)va_arg(list, int));
	else if (i == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (i == 'p')
		count += ft_put_adr(va_arg(list, unsigned long));
	else if (i == 'd' || i == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (i == 'u')
		count += ft_put_unsigned(va_arg(list, int));
	else if (i == 'x')
		count += ft_put_hex(va_arg(list, unsigned int), 0);
	else if (i == 'X')
		count += ft_put_hex(va_arg(list, unsigned int), 1);
	return (count);
}
