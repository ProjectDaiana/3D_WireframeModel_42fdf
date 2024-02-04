/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:30:16 by darotche          #+#    #+#             */
/*   Updated: 2024/02/04 13:40:35 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

int str_end(const char *str)
{
    int i;
    i = 0;
    while (str[i])
            i++;
	i--;
	while(str[i] == ' ' || str[i] == '\t')
		i--;
        return(i);
}

int count_words(const char *str)
{
	int i;
	int n_words;
	int end;
	int flag = 0;

	i = 0;
	n_words = 0;
	end = str_end(str);
       	while(str[i] == ' ' || str[i] == '\t')
        	i++;
     	while(i <= end)
        {
			if (str[i] != ' ' && str[i != '\t'])
				flag = 1;
        	if(str[i] == ' ' || str[i] == '\t')
            	n_words++;
			i++;
        }

	return(n_words+flag);
}

char	**ft_split(char const *str, char c)
{
	int i;
	int sp;
	int w;
	int j;
	char **words;
	int n_words;

	w = 0;
    n_words = count_words(str);
	words = malloc(sizeof(char*) * (n_words + 1));
	if (!words)
		return(NULL);
	i = 0;
	while(str[i])
	{
		while((str[i] == c || str[i] == '\t') && str[i] != '\0')
			i++;
		sp = i;
		if(w < n_words)
		{	//printf("loop");
			words[w] = malloc(sizeof(char) * (i - sp + 1));
			if(!words[w])
			{
				//printf("returning null");
				return(NULL);
			}
			j = 0;
			while(str[i] != c && str[i] != '\t' && str[i])
			{
				//printf("loop");
				words[w][j] = str[i];
				i++;
				j++;
			}
			//printf("loop");
			words[w][j] = '\0';
			w++;
		}	
	}
	words[w] = NULL;
	return(words);
}

// #include <stdio.h>
// void print_words(char **words)
// {
// 	int w = 0;
//     while (words[w])
// 	{
//         printf("%s\n", words[w]);
//         w++;
//     }
// }
// int main()
// {
// 	char **words = ft_split("    ");
// 	//char **words = ft_split("   a ");
// 	//char **words = ft_split("three words apart  ");
// 	//char **words = ft_split("         la re mil re concha de la mismisima Dios!     ");
// 	if (words == NULL) {
//     printf("null\n");
// 	} else {
//     print_words(words);	
// 	}
// 	return(0);
// }