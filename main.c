#include <stdio.h>
#include "fdf.h"

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
	

	//printf("Z value is: %d\n", data.map.rows[2].z_value[2]);
	//printf("X value is: %d\n", data.map.rows[data.map.n_rows - 1].z_value[data.map.rows[data.map.n_rows - 1].n_cols - 1]);
	// for (int i = 0; i < data.map.n_cols; i++)
	// {
	// 	for (int j = 0; j < data.map.n_rows; j++)
	// 		printf("x=%d y=%d z=%d\n", i, j, data.map.z_value[i][j]);
	// }

	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free_stuff(&map);
	free(data.mlx_ptr);
}