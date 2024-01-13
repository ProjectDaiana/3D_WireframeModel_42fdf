#include <stdio.h>
#include "fdf.h"

int render(t_data *data)
{
	static double last_a_z;
	static double last_a_x;
	static int last_scale;

	if (data->win_ptr == NULL)
		return (1);

	if (data->img.mlx_img && (last_a_z != data->map.a_z || last_a_x != data->map.a_x))
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	}
	if (data->img.mlx_img && (last_scale != data->map.scale))
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	}
	perspectivate(&data->map);
	draw_lines(&data->img, &data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	last_a_z = data->map.a_z;
	last_a_x = data->map.a_x;
	return(0);
}

int main(int argc, char **argv)
{
	static t_data	data;
	static t_map	map;
	(void) argc;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }
	import_map(argv[1], &data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	//mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_mouse_hook(data.win_ptr, &handle_leftclick, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free_stuff(&map);
	free(data.mlx_ptr);
}