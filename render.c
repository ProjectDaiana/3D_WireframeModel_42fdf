#include "fdf.h"
#include "stdio.h"
#include "math.h"

//////// Background to window!!!!!!!!!!!!!!!!
// void	render_background(t_data *data, int color)
// {
//     int	i;
//     int	j;

//     if (data->win_ptr == NULL)
//         return ;
//     i = 0;
//     while (i < W_HEIGHT)
//     {
//         j = 0;
//         while (j < W_WIDTH)
//             mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
//         ++i;
//     }
// }

// int render_rect(t_img *img, t_rect rect)
// {
// 	int i;
// 	int j;

// 	i = rect.y;
// 	while (i < rect.y + rect.height)	
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			img_pix_put(img, j++, i, rect.color + i);
// 		i++;
// 	}
// 	return (0);
// }

// int render_hline(t_img *img, t_map map)
// {
// 	int x;
// 	int y;
// 	int zoom;
// 	int offset;

// 	x = 0;
// 	y = 0;
// 	zoom = 20;
// 	//offset = (W_WIDTH - img_width) / 2;
// 	offset = 100;
// 	while (x < map.n_cols*zoom)	
// 	{
// 		img_pix_put(img, x + offset, y + offset, G);
// 		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color + j);
// 		x++;
// 	}
// 	return (0);
// }

// int render_vline(t_img *img, t_map *map)
// {
// 	int x;
// 	int y;
// 	int zoom;
// 	int offset;
	
// 	x = 0;
// 	y = 0;
// 	zoom = 20;
// 	//offset = (W_WIDTH - img_width) / 2;
// 	offset = 100;
// 	while (y < map->n_rows*zoom)	
// 	{
// 		img_pix_put(img, x + offset, y + offset, R);
// 		y++;
// 	}
// 	return (0);
// }

///////////////// DRAW

// int draw_grid(t_img *img, t_map *map)
// {
// 	int x;
// 	int y;
// 	int zoom;
// 	int offset;
	
// 	x = 0;
// 	zoom = 20;
// 	offset = 100;

// 	while(x < map->n_rows)
// 	{
// 		y = 0;
// 		while (y < map->n_cols)
// 		{
// 			img_pix_put(img, x + offset*(x+1), y + offset*(y+1), R);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return(0);
// }

// void draw_lines(double x_beg, double y_beg, double x_end, double y_end)
// {
// 	double dx;
// 	double dy;
// 	double D;

// 	dx = x_beg - x_end;
// 	dy = y_beg - y_end;
// 	D = (2 * dy) - dx;
// }
// void	img_pix_put(t_img *img, int x, int y, int color)
// {
//     char    *pixel;
//     int		i;

//     i = img->bpp - 8;
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
//     while (i >= 0)
//     {
//         /* big endian, MSB is the leftmost bit */
//         if (img->endian != 0)
//             *pixel++ = (color >> i) & 0xFF;
//         /* little endian, LSB is the leftmost bit */
//         else
//             *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
//         i -= 8;
//     }
// }


void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

	x = x + W_WIDTH/2;
	y= y + W_HEIGHT/2;
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
	{
    	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    	*(int *)pixel = color;
	}
}

void perspectivate(t_map *map, int scale)
{
	int z_val;
	int x;
	int y;
	
	x = 0;
	while(x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			z_val = (map->coords[x][y].z)*scale;

			/// OFFFSET
			double x_offset = (x - map->n_rows / 2)*scale;
            double y_offset = (y - map->n_cols / 2)*scale;

			// Passing arrow keys to rotate
			map->coords[x][y].x_pers = (-x_offset *cos(map->a_z) - y_offset *sin(map->a_z));
			map->coords[x][y].y_pers = -x_offset *sin(map->a_z) + y_offset *cos(map->a_z);
			map->coords[x][y].y_pers = (map->coords[x][y].y_pers * cos(map->a_x) - z_val * sin(map->a_x));

			////// NO OFFSET
			// map->coords[x][y].x_pers = x * cos(map->a_z) - y * sin(map->a_z);
			// map->coords[x][y].y_pers = (x * sin(map->a_z) + (y)*cos(map->a_z)) * cos(map->a_x) - z_val * sin(map->a_x);

			// map->coords[x][y].x_pers *= scale;
			// map->coords[x][y].y_pers *= scale;

			// printf("x=%f, x_pers=%f, y=%f, y_pers=%f\n", x, x_pers, y, y_pers);
			//img_pix_put(img, map->coords[x][y].x_pers + W_WIDTH/2, map->coords[x][y].y_pers + W_HEIGHT/2, G);
			y++;
		}
		x++;
	}
}

void draw_line(t_img *img, t_map *map, int x1, int y1, int x2, int y2) 
{
    // Iterators, counters required by algorithm
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye;
    // Calculate line deltas
    dx = x2 - x1;
    dy = y2 - y1;

    // Create a positive copy of deltas (makes iterating easier)
    dx1 = abs(dx); 
    dy1 = abs(dy);
    // Calculate error intervals for both axis
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;

	double line_len = hypot(dx, dy);
	if(x1 == 0 && y1 == 0)
		printf("Line Len is: %f", line_len);
    // The line is X-axis dominant
    if (dy1 <= dx1)
	{
        if (dx >= 0)
		{
            x = x1; y = y1; xe = x2;
		}
        else
		{// Line is drawn right to left (swap ends)
            x = x2; y = y2; xe = x1;
		}
    //     Rasterize the line
		while (x < xe)
		{
			if (px < 0)
				px = px + 2 * dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    y = y + 1;
                else
				{
        			y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
				map->color =  gradient(RGB(0, 0, 255),  RGB(0, 255, 0), line_len, x);
				printf("PX is %d",px);
					img_pix_put(img, x, y,map->color+y);
			x++;
		}
    }
	else
	{ // The line is Y-axis dominant
        // Line is drawn bottom to top
        if (dy >= 0) {
            x = x1; y = y1; ye = y2;
        } 
		else { // Line is drawn top to bottom
            x = x2; y = y2; ye = y1;
        }
        // Rasterize the line
		while(y < ye)
		{
            // Deal with octants...
            if (py <= 0) {
                py = py + 2 * dx1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            // Draw pixel from line span at
            // currently rasterized position
			map->color =  gradient(RGB(0, 0, 255),  RGB(0, 255, 0), line_len, y);
			img_pix_put(img, x, y, map->color);
		    y++;
        }
    }
 }

void draw_lines(t_img *img, t_map *map)
{
	int x;
	int y;
	int nx;
	int ny;
	int nx_next;
	int ny_next;

	x = 0;
	while(x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			nx = map->coords[x][y].x_pers;
			ny = map->coords[x][y].y_pers;

			if (x < map->n_rows - 1)
			{
				nx_next = map->coords[x + 1][y].x_pers;
				ny_next = map->coords[x + 1][y].y_pers;
				draw_line(img, map, nx, ny, nx_next, ny_next);
			}
			if (y < map->n_cols - 1)
			{
				nx_next = map->coords[x][y + 1].x_pers;
				ny_next = map->coords[x][y + 1].y_pers;
				draw_line(img, map, nx, ny, nx_next, ny_next);
			}
			y++;
		}
		x++;
	//	printf("nx %d ny %d \n", nx, ny);
	}
 }

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	//render_rect(&data->img, (t_rect){W_WIDTH - 100, W_HEIGHT - 100, 100, 100, G});
    //render_rect(&data->img, (t_rect){0, 0, 20, 20, R});
	//render_vline(&data->img, (t_rect){W_WIDTH/2, W_HEIGHT/2, 0, 300, G});
	
	//TRANSLATION(t_rect){row end of line, col start of line, }
	//render_hline(&data->img, (t_rect){600, 150, 0, 0, R});
	//render_hline(&data->img, data->map);
	//render_vline(&data->img, &data->map);
	//draw_grid(&data->img, &data->map);
	//render_vline(&data->img, &data.map->rows.n_cols);

	static double last_a_z;
	static double last_a_x;
	if (data->img.mlx_img && (last_a_z != data->map.a_z || last_a_x != data->map.a_x))
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	}
	perspectivate(&data->map,20);
	draw_lines(&data->img, &data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	last_a_z = data->map.a_z;
	last_a_x = data->map.a_x;
	return(0);
}