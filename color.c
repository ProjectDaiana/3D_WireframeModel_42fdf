/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:11:25 by darotche          #+#    #+#             */
/*   Updated: 2024/02/04 18:05:00 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(int a, int b, int c)
{
	int	red;
	int	grn;
	int	blu;

	red = a << 16;
	grn = b << 8;
	blu = c;
	return ((red & 0xFF0000) | (grn & 0x00FF00) | (blu & 0x0000FF));
}

int	getcolor(int color, int shift)
{
	return ((color >> shift) & 0xFF);
}

int	gradient(int s_color, int e_color, int range, int i)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((getcolor(e_color, 16)) 
			- (getcolor(s_color, 16))) / (double)range;
	increment[1] = (double)((getcolor(e_color, 8))
			- (getcolor(s_color, 8))) / (double)range;
	increment[2] = (double)((getcolor(e_color, 0))
			- (getcolor(s_color, 0))) / (double)range;
	new[0] = (getcolor(s_color, 16)) + round(abs(i) * increment[0]);
	new[1] = (getcolor(s_color, 8)) + round(abs(i) * increment[1]);
	new[2] = (getcolor(s_color, 0)) + round(abs(i) * increment[2]);
	newcolor = rgb(new[0], new[1], new[2]);
	return (newcolor);
}

void	asign_colors(t_map *map, int s_color, int e_color)
{
	int	x;
	int	y;
	int	color_range;

	color_range = abs(max_z(map)) + abs(min_z(map)) - 2;
	x = 0;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (map->c[x][y].z == max_z(map))
				map->c[x][y].color = e_color;
			else if (map->c[x][y].z == min_z(map) || map->c[x][y].z == 0)
				map->c[x][y].color = s_color;
			else
			{
				map->c[x][y].color = gradient(s_color, e_color, 
						color_range, (map->c[x][y].z));
			}
			y++;
		}
		x++;
	}
}