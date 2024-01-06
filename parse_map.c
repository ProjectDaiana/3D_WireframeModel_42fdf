# include "fdf.h"
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
		data->map.coords[row] = malloc((sizeof(t_coords)*col));
		col = 0;
		while (intarr[col] != NULL && intarr[col][0] != '\n')
		{
			data->map.coords[row][col].z = ft_atoi(intarr[col]);
			col++;
		}
		free_arr2D(intarr);
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
	data->map.a_x = 30.0/180 *PI;
	data->map.a_z = 30.0/180 *PI;

	i = 0;
	fd = open(filename, O_RDONLY);
	data->map.n_rows = count_rows(fd);
	data->map.coords = malloc ((sizeof(t_coords *)* data->map.n_rows));
	///PRINT NUM OF ROWS
	//printf("%d rows\n", data->map.n_rows);
	close(fd);
	//data->map.n_rows=malloc(sizeof(int)*data->map.n_rows);
	fd = open(filename, O_RDONLY);
	while(i < data->map.n_rows)
	{
		line_to_intarr(get_next_line(fd), data, i);
		i++;
	}
	//close(fd);
}