/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:11:25 by darotche          #+#    #+#             */
/*   Updated: 2024/01/21 20:17:32 by darotche         ###   ########.fr       */
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

int max_z(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	map->max_z = map->coords[x][y].z;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (map->max_z < map->coords[x][y].z)
				map->max_z = map->coords[x][y].z;
			y++;
		}
		x++;
	}
	return (map->max_z);
}

int min_z(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	map->min_z = map->coords[x][y].z;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (map->min_z > map->coords[x][y].z)
				map->min_z = map->coords[x][y].z;
			y++;
		}
		x++;
	}
	return (map->min_z);
}

int	gradient(int startcolor, int endcolor, int len, int i)
{
	double increment[3];
	int new[3];
	int newcolor;
	(void) len;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
    increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
    increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;

    new[0] = (R(startcolor)) + round(i * increment[0]);
    new[1] = (G(startcolor)) + round(i * increment[1]);
    new[2] = (B(startcolor)) + round(i * increment[2]);

	// double t = (double)(y - y_start) / (double)(y_end - y_start);
    // new[0] = (int)(new[0] * (1.0 - t) + (R(endcolor)) * t);
    // new[1] = (int)(new[1] * (1.0 - t) + (G(endcolor)) * t);
    // new[2] = (int)(new[2] * (1.0 - t) + (B(endcolor)) * t);
    newcolor = RGB(new[0], new[1], new[2]);

    return (newcolor);
}

void asign_colors(t_map *map)
{
	int x;
	int y;
	int startcolor = RGB(220, 220, 180);
	//int midcolor = RGB(80, 120, 230);
	int endcolor = RGB(50, 0, 180);

	// int startcolor = RGB(255, 0, 0);
	// //int midcolor = RGB(80, 120, 230);
	// int endcolor = RGB(0, 0, 255);

	// int grad_len = (abs(map->max_z)+abs(map->min_z))*map->scale;
	x = 0;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (map->coords[x][y].z == max_z(map))
				map->coords[x][y].color = startcolor;
			else if (map->coords[x][y].z == min_z(map))
				map->coords[x][y].color = endcolor;
			else
				map->coords[x][y].color = gradient(startcolor, endcolor, map->n_cols, y);
				//map->coords[x][y].color =midcolor;
			y++;
		}
		x++;
	}
}
