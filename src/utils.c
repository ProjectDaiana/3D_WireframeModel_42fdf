/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:41:15 by darotche          #+#    #+#             */
/*   Updated: 2024/08/26 14:22:05 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max_z(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->max_z = map->c[x][y].z;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (map->max_z < map->c[x][y].z)
				map->max_z = map->c[x][y].z;
			y++;
		}
		x++;
	}
	return (map->max_z);
}

int	min_z(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->min_z = map->c[x][y].z;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (map->min_z > map->c[x][y].z)
				map->min_z = map->c[x][y].z;
			y++;
		}
		x++;
	}
	return (map->min_z);
}
