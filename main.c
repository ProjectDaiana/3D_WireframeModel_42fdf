#include <stdio.h>
#include "fdf.h"

///// Color
//#include <inttypes.h>

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }
/// Render
/// Here you want to send the pixel not to the window but to a buffer and then send it to the window. 

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

void line_to_intarr(char *str, t_line *line)
{
		char **intarr;
		int *z;
		int i;

		i = 0;
		intarr = ft_split(str, ' ');
		while (intarr[i] != NULL && intarr[i][0] != '\n')
			i++;
		line->n_cols = i;
		z = malloc(sizeof(int)*i);
		i = 0;
		while (intarr[i] != NULL && intarr[i][0] != '\n')
		{
		    z[i] = ft_atoi(intarr[i]);
			i++;
		}
		line->z_value = z;
}

int count_rows(int fd)
{
	int rows;

	rows = 0;
	while(get_next_line(fd))
	 	rows++;
	return(rows);
}

void import_map(char *str, t_data * data)
{
	(void) str;
	int fd;
	int i;

	i = 0;
	fd = open("./test_maps/3x3.fdf", O_RDONLY);
	data->map.n_rows = count_rows(fd);
	///PRINT NUM OF ROWS
	printf("%d rows\n", data->map.n_rows);
	close(fd);
	data->map.rows=malloc(sizeof(t_line)*data->map.n_rows);
	
	open("./test_maps/3x3.fdf", O_RDONLY);
	while(i < data->map.n_rows)
	{
		line_to_intarr(get_next_line(fd), &data->map.rows[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data	data;
	(void) argc;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);

	import_map(argv[1], &data);
	printf("Z value is: %d\n", data.map.rows[2].z_value[2]);

	printf("X value is: %d\n", data.map.rows[data.map.n_rows - 1].z_value[data.map.rows[data.map.n_rows - 1].n_cols - 1]);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}