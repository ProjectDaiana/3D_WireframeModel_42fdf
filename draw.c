/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:11:09 by darotche          #+#    #+#             */
/*   Updated: 2024/01/30 18:07:45 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ///// LONG B. Algorithm
// void draw_line(t_img *img, t_map *map, int x1, int y1, int x2, int y2)
// {
//     // Iterators, counters required by algorithm
//     int x, y, dx, dy, dx1, dy1, px, py, xe, ye;
//     // Calculate line deltas
//     dx = x2 - x1;
//     dy = y2 - y1;

//     // Create a positive copy of deltas (makes iterating easier)
//     dx1 = abs(dx);
//     dy1 = abs(dy);
//     // Calculate error intervals for both axis
//     px = 2 * dy1 - dx1;
//     py = 2 * dx1 - dy1;

// 	double line_len = hypot(dx1, dy1);
// 	if(x1 == 0 && y1 == 0)
// 		printf("Line Len is: %f", line_len);
//     // The line is X-axis dominant
//     if (dy1 <= dx1)
// 	{
//         if (dx >= 0)
// 		{
//             x = x1; y = y1; xe = x2;
// 		}
//         else
// 		{// Line is drawn right to left (swap ends)
//             x = x2; y = y2; xe = x1;
// 		}
//     //     Rasterize the line
// 		while (x < xe)
// 		{
// 			if (px < 0)
// 				px = px + 2 * dy1;
// 			else
// 			{
// 				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
//                     y = y + 1;
//                 else
// 				{
//         			y = y - 1;
// 				}
// 				px = px + 2 * (dy1 - dx1);
// 			}
// 				map->color =  gradient(RGB(0, 0, 255),  RGB(0, 255, 0), line_len, x);
// 				printf("PX is %d",px);
// 					img_pix_put(img, x, y,map->color+y);
// 			x++;
// 		}
//     }
// 	else
// 	{ // The line is Y-axis dominant
//         // Line is drawn bottom to top
//         if (dy >= 0) {
//             x = x1; y = y1; ye = y2;
//         }
// 		else { // Line is drawn top to bottom
//             x = x2; y = y2; ye = y1;
//         }
//         // Rasterize the line
// 		while(y < ye)
// 		{
//             // Deal with octants...
//             if (py <= 0) {
//                 py = py + 2 * dx1;
//             } else {
//                 if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
//                     x = x + 1;
//                 } else {
//                     x = x - 1;
//                 }
//                 py = py + 2 * (dx1 - dy1);

//             }

//             // Draw pixel from line span at
//             // currently rasterized position
// 			map->color =  gradient(RGB(0, 0, 255),  RGB(0, 255, 0), line_len, y);
// 			img_pix_put(img, x, y, map->color);
// 		    y++;
//         }
//     }
//  }
// //////////

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

void	convert_to_iso(t_map *map, t_data *data)
{
	int		z_val;
	int		x;
	int		y;
	double	x_offs;
	double	y_offs;

	x = 0;
	follow_mouse(data);
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			z_val = (map->c[x][y].z) * map->scale;
			x_offs = ((x - map->n_rows / 2) * map->scale);
			y_offs = ((y - map->n_cols / 2) * map->scale);
			map->c[x][y].x_t = (-x_offs * cos(map->a_z)
					- y_offs * sin(map->a_z)) + map->x_mouse_mov;
			map->c[x][y].y_t = -x_offs * sin(map->a_z) + y_offs * cos(map->a_z);
			map->c[x][y].y_t = (map->c[x][y].y_t * cos(map->a_x)
					- z_val * sin(map->a_x)) + map->y_mouse_mov;
			y++;
		}
		x++;
	}
}

void	draw_line(t_img *img, int x1, int y1, int x2, int y2, int color, int n_color)
{
	int		x;
	int		y;
	int		i;
	int		colour;
	double	line_len;

	i = 0;
	line_len = hypot((x2 - x1), (y2 - y1));
	while (i < line_len)
	{
		colour = gradient(color, n_color, line_len, i);
		x = x1 + i * (x2 - x1) / line_len;
		y = y1 + i * (y2 - y1) / line_len;
		img_pix_put(img, x, y, colour);
		i++;
	}
}

void	draw_lines(t_img *img, t_map *map)
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
				draw_line(img, map->c[x][y].x_t, map->c[x][y].y_t,
					map->c[x + 1][y].x_t, map->c[x + 1][y].y_t,
					map->c[x][y].color, map->c[x + 1][y].color);
			}
			if (y < map->n_cols - 1)
			{
				draw_line(img, map->c[x][y].x_t, map->c[x][y].y_t,
					map->c[x][y + 1].x_t, map->c[x][y + 1].y_t,
					map->c[x][y].color, map->c[x][y + 1].color);
			}
			y++;
		}
		x++;
	}
}

// void	draw_line(t_img *img, int x1, int y1, int x2, int y2, int color, int n_color)
// {
// 	int	dx;
// 	int	dy;
// 	int	i;
// 	int	x;
// 	int	y;
// 	int	colour;
// 	double	line_len;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	i = 0;
// 	line_len = hypot(dx, dy);
// 	while (i < line_len)
// 	{
// 		colour = gradient(color, n_color, line_len, i);
// 		x = x1 + i * dx / line_len;
// 		y = y1 + i * dy / line_len;
// 		img_pix_put(img, x, y, colour);
// 		i++;
// 	}
// }

// void	draw_lines(t_img *img, t_map *map)
// {
// 	int	x;
// 	int	y;
// 	int	nx;
// 	int	ny;
// 	int	nx_next;
// 	int	ny_next;
// 	int	color;
// 	int	n_color;

// 	x = 0;
// 	asign_colors(map);
// 	while (x < map->n_rows)
// 	{
// 		y = 0;
// 		while (y < map->n_cols)
// 		{
// 			nx = map->c[x][y].x_t;
// 			ny = map->c[x][y].y_t;
// 			color = map->c[x][y].color;
// 			if (x < map->n_rows - 1)
// 			{
// 				nx_next = map->c[x + 1][y].x_t;
// 				ny_next = map->c[x + 1][y].y_t;
// 				n_color = map->c[x + 1][y].color;
// 				draw_line(img, nx, ny, nx_next, ny_next, color, n_color);
// 			}
// 			if (y < map->n_cols - 1)
// 			{
// 				nx_next = map->c[x][y + 1].x_t;
// 				ny_next = map->c[x][y + 1].y_t;
// 				n_color = map->c[x][y + 1].color;
// 				draw_line(img, nx, ny, nx_next, ny_next, color, n_color);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }
