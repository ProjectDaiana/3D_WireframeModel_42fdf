/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:11:25 by darotche          #+#    #+#             */
/*   Updated: 2024/01/26 18:30:46 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

///// COLOR
//#include <inttypes.h>

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

/////////// IMPORT /////////////////////////////////////

int	max_z(t_map *map)
{
	int x;
	int y;

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

int	gradient(int s_color, int e_color, int range, int i)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((R(e_color)) - (R(s_color))) / (double)range;
    increment[1] = (double)((G(e_color)) - (G(s_color))) / (double)range;
	increment[2] = (double)((B(e_color)) - (B(s_color))) / (double)range;
    new[0] = (R(s_color)) + round(i * increment[0]);
    new[1] = (G(s_color)) + round(i * increment[1]);
    new[2] = (B(s_color)) + round(i * increment[2]);
    newcolor = RGB(new[0], new[1], new[2]);
	return (newcolor);
}

void asign_colors(t_map *map)
{
	int	x;
	int	y;
	int	s_color;
	int	e_color;
	int	color_range;

	s_color = RGB(50, 0, 210);
	e_color = RGB(100, 120, 180);
	// s_color = RGB(0, 25, 25);
	// e_color = RGB(250, 250, 250);
	color_range = abs(max_z(map)) + abs(min_z(map)) - 2;
	x = 0;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			printf("max_z %d\n", max_z(map));
			printf("min_z %d\n", min_z(map));
			printf("color_range = %d\n",color_range);
			if (map->c[x][y].z == max_z(map))
				map->c[x][y].color = e_color;
			else if (map->c[x][y].z == min_z(map))
				map->c[x][y].color =s_color;
			else
			{
				if (map->c[x][y].z < 0)
					map->c[x][y].z = fabs(map->c[x][y].z);
				printf("map->c[x][y].z =  %f\n", map->c[x][y].z);
				map->c[x][y].color = gradient(s_color, e_color, color_range, map->c[x][y].z);
			}
			y++;
		}
		x++;
	}
}
