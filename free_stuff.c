/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:54 by darotche          #+#    #+#             */
/*   Updated: 2024/01/21 20:10:57 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_stuff(t_map *map)
{
	int i;

	i = 0;
	while(i < map->n_rows)
	{
			free(map->coords[i]);
			i++;
	}
	free(map->coords);
}

void free_arr2D(char **arr2D)
{
	int i;

	i = 0;
	while (arr2D[i] != NULL && arr2D[i][0] != '\n')
		free(arr2D[i++]);
	free(arr2D);
}