# include "fdf.h"

void line_to_coords(char *str, t_data *data, int row)
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
	{	
	 	rows++;
	}
	return(rows);
}

void import_map(char *filename, t_data * data)
{
	int fd;
	int i;
	data->map.a_x = 30.0/180 *PI;
	data->map.a_z = 30.0/180 *PI;
	data->map.scale = 30;

	i = 0;
	fd = open(filename, O_RDONLY);
	data->map.n_rows = count_rows(fd);
	data->map.coords = malloc ((sizeof(t_coords *)* data->map.n_rows));
	close(fd);
	fd = open(filename, O_RDONLY);
	char **lines = malloc(sizeof(char *) * data->map.n_rows);
	
	while (i < data->map.n_rows)
	{
		lines[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	while(i < data->map.n_rows)
	{
		line_to_coords(lines[i], data, i);
		i++;
	}
	i= 0;
	while (i < data->map.n_rows)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}