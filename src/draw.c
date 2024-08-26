/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:11:09 by darotche          #+#    #+#             */
/*   Updated: 2024/08/26 14:21:53 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	x = x + W_WIDTH / 2;
	y = y + W_HEIGHT / 2;
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

void	draw_line(t_img *img, t_line *line)
{
	int		x;
	int		y;
	int		i;
	double	line_len;
	int		color;

	i = 0;
	line_len = hypot((line->x2 - line->x1), (line->y2 - line->y1));
	color = gradient(line->color1, line->color2, line_len, i);
	while (i < line_len)
	{
		x = line->x1 + i * (line->x2 - line->x1) / line_len;
		y = line->y1 + i * (line->y2 - line->y1) / line_len;
		img_pix_put(img, x, y, color);
		i++;
	}
}

void	set_line_params1(t_line *line, t_map *map, int x, int y)
{
	line->x1 = map->c[x][y].x_t;
	line->y1 = map->c[x][y].y_t;
	line->x2 = map->c[x + 1][y].x_t;
	line->y2 = map->c[x + 1][y].y_t;
	line->color1 = map->c[x][y].color;
	line->color2 = map->c[x +1][y].color;
}

void	set_line_params2(t_line *line, t_map *map, int x, int y)
{
	line->x1 = map->c[x][y].x_t;
	line->y1 = map->c[x][y].y_t;
	line->x2 = map->c[x][y + 1].x_t;
	line->y2 = map->c[x][y + 1].y_t;
	line->color1 = map->c[x][y].color;
	line->color2 = map->c[x][y + 1].color;
}

void	draw_lines(t_img *img, t_map *map, t_line *line)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (x < map->n_rows - 1)
			{
				set_line_params1(line, map, x, y);
				draw_line(img, line);
			}
			if (y < map->n_cols - 1)
			{
				set_line_params2(line, map, x, y);
				draw_line(img, line);
			}
			y++;
		}
		x++;
	}
}
