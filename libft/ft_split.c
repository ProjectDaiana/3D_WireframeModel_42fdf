/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:30:16 by darotche          #+#    #+#             */
/*   Updated: 2023/10/07 14:45:41 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	str_count(char const *s, char c)
// {
// 	int	i;
// 	int	b;

// 	i = 0;
// 	b = 0;
// 	while (*s)
// 	{
// 		if (*s != c && b == 0)
// 		{
// 			i++;
// 			b = 1;
// 		}
// 		else if (*s == c && b == 1)
// 			b = 0;
// 		s++;
// 	}
// 	return (i);
// }

// char	**ft_split(char const	*s, char c)
// {
// 	char	**arrstr;
// 	int		len;
// 	int		i;

// 	arrstr = (char **)malloc((str_count(s, c) + 1) * sizeof(char *));
// 	if (!s || !arrstr)
// 		return (NULL);
// 	i = 1;
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s)
// 		{
// 			if (!ft_strchr(s, c))
// 				len = ft_strlen(s);
// 			else
// 				len = ft_strchr(s, c) - s;
// 			arrstr[i++] = ft_substr(s, 0, len);
// 			s = s + len;
// 		}
// 	}
// 	arrstr[i] = NULL;
// 	return (arrstr);
// }

//////////////////

int	get_vec_size(const char *s, char c)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (result);
}

char	*copy_word(const char *s, int start, int end)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * ((end - start) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**vec;
	int		end;
	int		start;
	int		word;

	vec = malloc((get_vec_size(s, c) + 1) * sizeof(char *));
	if (!s || !vec)
		return (0);
	vec[get_vec_size(s, c)] = NULL;
	end = 0;
	word = 0;
	while (s[end] != '\0' && word < get_vec_size(s, c))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		vec[word] = copy_word(s, start, end);
		if (vec[word] == NULL)
			return (NULL);
		word++;
	}
	return (vec);
}
