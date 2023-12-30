#include "fdf.h"
#include "stdio.h"

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
// /// Puts pix in window 
// int render_vline(t_data *data, t_rect rect)
// {
// 	int i;
// 	int j;
	
// 	if (data->win_ptr == NULL)
// 		return(1);
// 	i = 0;
// 	j = rect.x;
// 	while (i < rect.y)	
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color);
// 		i++;
// 	}
// 	return (0);
// }

/////////// Puts pix in img (not reading map)
// int render_vline(t_img *img, t_rect rect)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	j = rect.x;
// 	while (i < rect.y)	
// 	{
// 		img_pix_put(img, j, i, rect.color + i);
// 		i++;
// 	}
// 	return (0);
// }

// int render_hline(t_img *img, t_rect rect)
// {
// 	int i;
// 	int j;

// 	i = rect.y;
// 	j = 0;
// 	while (j < rect.x)	
// 	{
// 		img_pix_put(img, j, i, rect.color + j);
// 		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color + j);
// 		j++;
// 	}
// 	return (0);
// }
////////////////////

int render_hline(t_img *img, t_line *line)
{
	int x;
	int y;
	int zoom;
	int offset;

	x = 0;
	y = 0;
	zoom = 100;
	//offset = (v_width - img_width) / 2;
	offset = 100;
	while (x < line->n_cols*zoom)	
	{
		img_pix_put(img, x + offset, y + offset, GRN_PIXEL);
		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color + j);
		x++;
	}
	return (0);
}

// int render_vline(t_img *img, t_line *line, t_map *map)
// {
// 	int i;
// 	int j;
// 	int zoom;
	
// 	i = 0;
// 	j = rect.x;
// 	while (i < rect.y)	
// 	{
// 		img_pix_put(img, j, i, rect.color + i);
// 		i++;
// 	}
// 	return (0);
// }

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GRN_PIXEL});
    render_rect(&data->img, (t_rect){0, 0, 20, 20, RED_PIXEL});
	//render_vline(&data->img, (t_rect){WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0, 300, GRN_PIXEL});
	
	//TRANSLATION(t_rect){row end of line, col start of line, }
	//render_hline(&data->img, (t_rect){600, 150, 0, 0, RED_PIXEL});

	render_hline(&data->img, &data->map.rows[1]);
//	render_vline(&data->img, &data.map->rows.n_cols);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return(0);
}