#include <stdio.h>
#include "fdf.h"

///// COLOR
//#include <inttypes.h>

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

/////////// IMPORT /////////////////////////////////////
void line_to_intarr(char *str, t_data *data, int row)
{
		char **intarr;
		int col;

		col = 0;
		intarr = ft_split(str, ' ');
		while (intarr[col] != NULL && intarr[col][0] != '\n')
			col++;
		data->map.n_cols = col;
		data->map.z_value[row] = malloc(sizeof(int)*col);
		col = 0;
		while (intarr[col] != NULL && intarr[col][0] != '\n')
		{
			data->map.z_value[row][col] = ft_atoi(intarr[col]);
			col++;
		}
}

int count_rows(int fd)
{
	int rows;

	rows = 0;
	while(get_next_line(fd))
	 	rows++;
	return(rows);
}

void import_map(char *filename, t_data * data)
{
	int fd;
	int i;

	i = 0;
	fd = open(filename, O_RDONLY);
	data->map.n_rows = count_rows(fd);
	data->map.z_value = malloc (sizeof(int *)* data->map.n_rows);
	///PRINT NUM OF ROWS
	//printf("%d rows\n", data->map.n_rows);
	//close(fd);
	//data->map.n_rows=malloc(sizeof(int)*data->map.n_rows);
	fd = open(filename, O_RDONLY);
	while(i < data->map.n_rows)
	{
		line_to_intarr(get_next_line(fd), data, i);
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
	data.win_ptr = mlx_new_window(data.mlx_ptr, V_WIDTH, V_HEIGHT, "fdf");
	if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, V_WIDTH, V_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);

	import_map(argv[1], &data);

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

	free(data.mlx_ptr);
}