#include "fdf.h"
#include "stdio.h"

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
/// Puts pix in window 
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
//}

// Puts pix in img
int render_vline(t_img *img, t_rect rect)
{
	int i;
	int j;
	
	i = 0;
	j = rect.x;
	while (i < rect.y)	
	{
		img_pix_put(img, j, i, rect.color + i);
		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color);
		i++;
	}
	return (0);
}

int render_hline(t_img *img, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	j = 0;
	while (j < rect.x)	
	{
		img_pix_put(img, j, i, rect.color + j);
		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, rect.color + j);
		j++;
	}
	return (0);
}

////// Background to window!!!!!!!!!!!!!!!!
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

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GRN_PIXEL});
    render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	render_vline(&data->img, (t_rect){WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0, 300, GRN_PIXEL});
	render_hline(&data->img, (t_rect){300, 150, 00, 0, BLU_PIXEL});
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	
	return(0);
}