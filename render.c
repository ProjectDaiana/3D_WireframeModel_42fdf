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
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
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

///////////////// DRAW
// void	img_pix_put(t_img *img, int x, int y, int color)
// {
//     char    *pixel;

//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
//     *(int *)pixel = color;
// }

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

int draw_dots(t_img *img, t_map *map)
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

void rotate45(t_img *img, t_map *map)
{
	double x;
	double y;
	int z;
	double offset;
	double a;
	double scale;

	// a = 3.141592653589 / 4.0;
	a = 30;
	a = a / 180 * 3.141592653589;
	//correction = 2 / 180 * 3.141592653589;
	// a = 2/3 * 3.14159;
	scale = 50;
	x = 0;
	double x45;
	double y45;
	offset = 300;
	
	while(x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			z = map->z_value[(int)x][(int)y];
			
			//This works with angle of 30
			x45 = (x *cos(a) -y *cos(a))*scale;
			y45 = (x *sin(a) + y *sin(a)-z)*scale;

			// Or this works
			// x45 = (x * 1/sqrt(2) + y * (-1)/sqrt(2))*scale;
			// y45 = (x * 1/sqrt(6) + y * 1/sqrt(6) - z)*scale;

			// This only rotates
			// x45 = (x*cos(a) - y *sin(a))*scale;
			// y45 = (x*sin(a) + y*cos(a))*scale;


			
			printf("x=%f, x45=%f, y=%f, y45=%f\n", x, x45, y, y45);
			img_pix_put(img, x45+ offset, y45+ offset, GRN_PIXEL);
			y++;
		}
		x++;
	}
}

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	//render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GRN_PIXEL});
    //render_rect(&data->img, (t_rect){0, 0, 20, 20, RED_PIXEL});
	//render_vline(&data->img, (t_rect){WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0, 300, GRN_PIXEL});
	
	//TRANSLATION(t_rect){row end of line, col start of line, }
	//render_hline(&data->img, (t_rect){600, 150, 0, 0, RED_PIXEL});

	//render_hline(&data->img, data->map);
	//render_vline(&data->img, &data->map);
	//draw_dots(&data->img, &data->map);
	//render_vline(&data->img, &data.map->rows.n_cols);
	
	rotate45(&data->img, &data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return(0);
}