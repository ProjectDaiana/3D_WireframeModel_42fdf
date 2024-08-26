/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:30:16 by darotche          #+#    #+#             */
/*   Updated: 2024/02/04 22:10:29 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int str_end(const char *str)
// {
//     int i;
//     i = 0;
//     while (str[i])
//             i++;
// 	i--;
// 	while(str[i] == ' ' || str[i] == '\t')
// 		i--;
//         return(i);
// }

// int count_words(const char *str)
// {
// 	int i;
// 	int n_words;
// 	int end;
// 	int flag = 0;

// 	i = 0;
// 	n_words = 0;
// 	end = str_end(str);
//        	while(str[i] == ' ' || str[i] == '\t')
//         	i++;
//      	while(i <= end)
//         {
// 			if (str[i] != ' ' && str[i != '\t'])
// 				flag = 1;
//         	if(str[i] == ' ' || str[i] == '\t')
//             	n_words++;
// 			i++;
//         }

// 	return(n_words+flag);
// }

// char	**ft_split(char const *str, char c)
// {
// 	int i;
// 	int sp;
// 	int w;
// 	int j;
// 	char **words;
// 	int n_words;

// 	w = 0;
//     n_words = count_words(str);
// 	words = malloc(sizeof(char*) * (n_words + 1));
// 	if (!words)
// 		return(NULL);
// 	i = 0;
// 	while(str[i])
// 	{
// 		while((str[i] == c || str[i] == '\t') && str[i] != '\0')
// 			i++;
// 		sp = i;
// 		if(w < n_words)
// 		{	//printf("loop");
// 			words[w] = malloc(sizeof(char) * (i - sp + 1));
// 			if(!words[w])
// 			{
// 				//printf("returning null");
// 				return(NULL);
// 			}
// 			j = 0;
// 			while(str[i] != c && str[i] != '\t' && str[i])
// 			{
// 				//printf("loop");
// 				words[w][j] = str[i];
// 				i++;
// 				j++;
// 			}
// 			//printf("loop");
// 			words[w][j] = '\0';
// 			w++;
// 		}	
// 	}
// 	words[w] = NULL;
// 	return(words);
// }

// // #include <stdio.h>
// // void print_words(char **words)
// // {
// // 	int w = 0;
// //     while (words[w])
// // 	{
// //         printf("%s\n", words[w]);
// //         w++;
// //     }
// // }
// // int main()
// // {
// // 	char **words = ft_split("    ");
// // 	//char **words = ft_split("   a ");
// // 	//char **words = ft_split("three words apart  ");
// // 	//char **words = ft_split("         la re mil re concha de la mismisima Dios!     ");
// // 	if (words == NULL) {
// //     printf("null\n");
// // 	} else {
// //     print_words(words);	
// // 	}
// // 	return(0);
// // }


static int  ft_delicount(char const *s, char c)
{
    int switcharoony;
    int a;
    switcharoony = 0;
    a = 0;
    while (*s)
    {
        if (*s != c && switcharoony == 0)
        {
            switcharoony = 1;
            a++;
        }
        else if (*s == c)
            switcharoony = 0;
        s++;
    }
    return (a);
}
static int  ft_sizecount(char const *s, char c, int i)
{
    int d;
    d = 0;
    while (s[i] != c && s[i])
    {
        i++;
        d++;
    }
    return (d);
}
static void ft_freemebaby(char **ptr, int f)
{
    while (f > -1)
    {
        free(ptr[f]);
        f--;
    }
    free(ptr);
}
char    **ft_split(char const *s, char c)
{
    int     i;
    int     a;
    int     f;
    char    **ptr;
    i = 0;
    f = -1;
    a = ft_delicount(s, c);
    ptr = (char **)malloc((a + 1) * sizeof(char *));
    if (!ptr)
        return (NULL);
    while (++f < a)
    {
        while (s[i] == c)
            i++;
        ptr[f] = ft_substr(s, i, ft_sizecount(s, c, i));
        if (!ptr[f])
        {
            ft_freemebaby(ptr, f);
            return (NULL);
        }
        i = ft_sizecount(s, c, i) + i;
    }
    ptr[f] = NULL;
    return (ptr);
}