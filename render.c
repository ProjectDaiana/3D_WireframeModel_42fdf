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

int draw_grid(t_img *img, t_map *map)
{
	int x;
	int y;
	int zoom;
	int offset;
	
	x = 0;
	zoom = 20;
	offset = 100;

	while(x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			img_pix_put(img, x + offset*(x+1), y + offset*(y+1), RED_PIXEL);
			y++;
		}
		x++;
	}
	return(0);
}

void draw_perspective_grid(t_img *img, t_map *map)
{
	double x;
	double y;
	int z;
	double scale;
	double x_pers;
	double y_pers;
	double a;
	a = 30.0 / 180 * 3.141592653589;

	x = 0;
	scale = 10;

	while(x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			z = map->z_value[(int)x][(int)y];
			
			//This works with angle of 30
			// x_pers = (x *cos(a) -y *cos(a))*scale;
			// y_pers = (x *sin(a) + y *sin(a)-z)*scale;

			// Or this works
			// x_pers = (x * 1/sqrt(2) + y * (-1)/sqrt(2))*scale;
			// y_pers = (x * 1/sqrt(6) + y * 1/sqrt(6) - z)*scale;

			// This only rotates
			// x_pers = (x*cos(a) - y *sin(a))*scale;
			// y_pers = (x*sin(a) + y*cos(a))*scale;

			double x_offset = x - map->n_rows / 2;
            double y_offset = y - map->n_cols / 2;

			// Passing a 
			// x_pers = x *cos(a) - y *cos(a);
			// y_pers = (x *sin(a) + y *cos(a)) * cos(a) - z * sin(a);
			// x_pers = x_pers *scale;
			// y_pers = y_pers *scale;

			//y_pers = (y_pers * cos(a) - z * sin(a))*scale;

			// Passing arrow keys rotates
			x_pers = (-x_offset *cos(map->a_z) - y_offset *sin(map->a_z))*scale;
			y_pers = -x_offset *sin(map->a_z) + y_offset *cos(map->a_z);
			y_pers = (y_pers * cos(map->a_x) - z * sin(map->a_x))*scale;

			// printf("x=%f, x_pers=%f, y=%f, y_pers=%f\n", x, x_pers, y, y_pers);
			img_pix_put(img, x_pers + V_WIDTH/2, y_pers + V_HEIGHT/2, GRN_PIXEL);
			y++;
		}
		x++;
	}
}

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
	draw_perspective_grid(&data->img, &data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return(0);
}