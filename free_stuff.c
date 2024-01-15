#include "fdf.h"

void free_stuff(t_map *map)
{
	int i;

	i = 0;
	while(i < map->n_rows)
	{
			free(map->coords[i]);
			i++;
	}
free(map->coords);
}

void free_arr2D(char **arr2D)
{
	int i;

	i = 0;
	while (arr2D[i] != NULL && arr2D[i][0] != '\n')
		free(arr2D[i++]);
	free(arr2D);
}

// void free_gnl(int fd, t_data *data)
// {
// 	int i= 0;
// 	while (i < data->map.n_rows)
// 	{
// 	char *line = get_next_line(fd);
// 	line_to_coords(line, data, i);

// 	// Free the memory allocated by get_next_line
// 	free(line);
// 	i++;
// 	}
// }