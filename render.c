#include "fdf.h"
#include "stdio.h"
#include "math.h"

//////// Background to window!!!!!!!!!!!!!!!!
void	render_background(t_data *data, int color)
{
    int	i;
    int	j;

    if (data->win_ptr == NULL)
        return ;
    i = 0;
    while (i < V_HEIGHT)
    {
        j = 0;
        while (j < V_WIDTH)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
        ++i;
    }
}

int render_rect(t_img *img, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)	
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color + i);
		i++;
	}
	return (0);
}

int render_hline(t_img *img, t_map map)
{
	int x;
	int y;
	int zoom;
	int offset;

	x = 0;
	y = 0;
	zoom = 20;
	//offset = (v_width - img_width) / 2;
	offset = 100;
	while (x < map.n_cols*zoom)	
	{
		img_pix_put(img, x + offset, y + offset, GRN_PIXEL);
		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color + j);
		x++;
	}
	return (0);
}

int render_vline(t_img *img, t_map *map)
{
	int x;
	int y;
	int zoom;
	int offset;
	
	x = 0;
	y = 0;
	zoom = 20;
	//offset = (v_width - img_width) / 2;
	offset = 100;
	while (y < map->n_rows*zoom)	
	{
		img_pix_put(img, x + offset, y + offset, RED_PIXEL);
		y++;
	}
	return (0);
}

///////////////// DRAW
void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

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
// 			img_pix_put(img, x + offset*(x+1), y + offset*(y+1), RED_PIXEL);
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

void draw_line(t_img *img, int x1, int y1, int x2, int y2) 
{
    // Iterators, counters required by algorithm
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
    // Calculate line deltas
    dx = x2 - x1;
    dy = y2 - y1;

    // Create a positive copy of deltas (makes iterating easier)
    dx1 = abs(dx); 
    dy1 = abs(dy);
    // Calculate error intervals for both axis
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;
    // The line is X-axis dominant
    if (dy1 <= dx1) {
        // Line is drawn left to right
        if (dx >= 0) {
            x = x1; y = y1; xe = x2;
        } else { // Line is drawn right to left (swap ends)
            x = x2; y = y2; xe = x1;
        }
        img_pix_put(img, x + V_WIDTH/2, y + V_HEIGHT/2, GRN_PIXEL);
        // Rasterize the line
        for (i = 0; x < xe; i++) {
            x = x + 1;
            // Deal with octants...
            if (px < 0) {
                px = px + 2 * dy1;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
                    y = y + 1;
                } else {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            img_pix_put(img, x + V_WIDTH/2, y + V_HEIGHT/2, GRN_PIXEL);
        }
    } else { // The line is Y-axis dominant
        // Line is drawn bottom to top
        if (dy >= 0) {
            x = x1; y = y1; ye = y2;
        } else { // Line is drawn top to bottom
            x = x2; y = y2; ye = y1;
        }
       img_pix_put(img, x + V_WIDTH/2, y + V_HEIGHT/2, GRN_PIXEL);
        // Rasterize the line
        for (i = 0; y < ye; i++) {
            y = y + 1;
            // Deal with octants...
            if (py <= 0) {
                py = py + 2 * dx1;
            } else {
                if ((dx < 0 && dy<0) || (dx > 0 && dy > 0)) {
                    x = x + 1;
                } else {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            // Draw pixel from line span at
            // currently rasterized position
           img_pix_put(img, x + V_WIDTH/2, y + V_HEIGHT/2, GRN_PIXEL);
        }
    }
 }


void perspectivate(t_map *map)
{
	int z_val;
	int scale;
	int x;
	int y;
	
	x = 0;
	scale = 25;

	while(x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			z_val = map->coords[x][y].z;

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
			//img_pix_put(img, map->coords[x][y].x_pers + V_WIDTH/2, map->coords[x][y].y_pers + V_HEIGHT/2, GRN_PIXEL);
			y++;
		}
		x++;
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
	int scale;

	x = 0;
	scale = 1;
	// int nx = map->x_pers;
	// int ny = map->y_pers;
	while(x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			nx = map->coords[x][y].x_pers;
			ny = map->coords[x][y].y_pers;

			// if (y < map->n_cols - 1 && x < map->n_rows - 1)
			// 	break;
			if (x < map->n_rows - 1)
			{
				nx_next = map->coords[x + 1][y].x_pers;
				ny_next = map->coords[x + 1][y].y_pers;
				draw_line(img, nx, ny, nx_next, ny_next);
				//draw_line(img, nx*scale, ny*scale, nx * scale, (ny + 1) * scale);
			}
			if (y < map->n_cols - 1)
			{
				nx_next = map->coords[x][y + 1].x_pers;
				ny_next = map->coords[x][y + 1].y_pers;
				draw_line(img, nx, ny, nx_next, ny_next);
				// 	draw_line(img, nx*scale, ny*scale, (x + 1) * scale, ny * scale);
			}
			y++;
			// // else
			// // {
			// 	draw_line(img, x*scale, y*scale, (nx + 1) * scale, ny * scale);
			// 	draw_line(img, x*scale, y*scale, nx * scale, (ny + 1) * scale);
			// //}
		}
		x++;
	//	printf("nx %d ny %d \n", nx, ny);
	}
 }

// void draw_perspective_grid(t_img *img, t_map *map)
// {
// 	double x;
// 	double y;
// 	int z;
// 	double scale;
// 	double x_pers;
// 	double y_pers;
	
// 	x = 0;
// 	scale = 13;

// 	while(x < map->n_rows)
// 	{
// 		y = 0;
// 		while (y < map->n_cols)
// 		{
// 			z = map->z_value[(int)x][(int)y];

// 			//This works with angle of 30
// 			// x_pers = (x *cos(a) -y *cos(a))*scale;
// 			// y_pers = (x *sin(a) + y *sin(a)-z)*scale;

// 			// Or this works
// 			// x_pers = (x * 1/sqrt(2) + y * (-1)/sqrt(2))*scale;
// 			// y_pers = (x * 1/sqrt(6) + y * 1/sqrt(6) - z)*scale;

// 			// This only rotates
// 			// x_pers = (x*cos(a) - y *sin(a))*scale;
// 			// y_pers = (x*sin(a) + y*cos(a))*scale;

// 			double x_offset = (x - map->n_rows / 2)*scale;
//             double y_offset = (y - map->n_cols / 2)*scale;

// 			// Passing a 
// 			// x_pers = x *cos(a) - y *cos(a);
// 			// y_pers = (x *sin(a) + y *cos(a)) * cos(a) - z * sin(a);
// 			// x_pers = x_pers *scale;
// 			// y_pers = y_pers *scale;

// 			//y_pers = (y_pers * cos(a) - z * sin(a))*scale;

// 			// Passing arrow keys rotates
// 			x_pers = (-x_offset *cos(map->a_z) - y_offset *sin(map->a_z));
// 			y_pers = -x_offset *sin(map->a_z) + y_offset *cos(map->a_z);
// 			y_pers = (y_pers * cos(map->a_x) - z * sin(map->a_x));

// 			// printf("x=%f, x_pers=%f, y=%f, y_pers=%f\n", x, x_pers, y, y_pers);
// 			img_pix_put(img, x_pers + V_WIDTH/2, y_pers + V_HEIGHT/2, GRN_PIXEL);
// 			y++;
// 		}
// 		x++;
// 	}
// }

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	//render_rect(&data->img, (t_rect){V_WIDTH - 100, V_HEIGHT - 100, 100, 100, GRN_PIXEL});
    //render_rect(&data->img, (t_rect){0, 0, 20, 20, RED_PIXEL});
	//render_vline(&data->img, (t_rect){V_WIDTH/2, V_HEIGHT/2, 0, 300, GRN_PIXEL});
	
	//TRANSLATION(t_rect){row end of line, col start of line, }
	//render_hline(&data->img, (t_rect){600, 150, 0, 0, RED_PIXEL});

	//render_hline(&data->img, data->map);
	//render_vline(&data->img, &data->map);
	//draw_grid(&data->img, &data->map);
	//render_vline(&data->img, &data.map->rows.n_cols);

	static double last_a_z;
	static double last_a_x;
	if (data->img.mlx_img && (last_a_z != data->map.a_z || last_a_x != data->map.a_x))
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, V_WIDTH, V_HEIGHT);
	}
	perspectivate(&data->map);
	draw_lines(&data->img, &data->map);
	//draw_perspective_grid(&data->img, &data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	last_a_z = data->map.a_z;
	last_a_x = data->map.a_x;
	return(0);
}