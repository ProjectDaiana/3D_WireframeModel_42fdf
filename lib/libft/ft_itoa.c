/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:33:34 by darotche          #+#    #+#             */
/*   Updated: 2023/05/28 13:22:00 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i = i * -1;
		count++;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long int	num;

	num = (long int)n;
	i = count_digits(num);
	str = malloc((i + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[i--] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[i--] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
//     int n = 1234567890;
//     printf("\033[0;34mCount: %d\n\033[0m", count_digits(n));

//     char *string = ft_itoa(n);
//     printf("\033[0;35mString: %s\033[0m", string);
//     free(string);
// }