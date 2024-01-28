/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:17 by darotche          #+#    #+#             */
/*   Updated: 2024/01/28 19:46:01 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	line_to_coords(char *str, t_data *data, int row)
{
	char	**c;
	int		col;

	col = 0;
	c = ft_split(str, ' ');
	while (c[col] != NULL && c[col][0] != '\n')
		col++;
	data->map.n_cols = col;
	data->map.c[row] = malloc((sizeof(t_coords) * col));
	col = 0;
	while (c[col] != NULL && c[col][0] != '\n')
	{
		data->map.c[row][col].z = ft_atoi(c[col]);
		col++;
	}
	free_arr2D(c);
	return(0);
}

int	count_rows(int fd)
{
	int		rows;
	char	*tmp;

	rows = 0;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return(0);
	while (tmp)
	{	
		rows++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (rows);
}

char	*file_path (char *argv)
{
	char *filepath = ft_strjoin( "./test_maps/", argv);
	return (filepath);
}

void	import_map(char *file, t_data * data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if(fd ==-1)
	{
		printf(RED"Error opening file.\n"RESET);
		destroy_win_and_img(data);
	}
	data->map.a_x = 30.0/180 *PI;
	data->map.a_z = 30.0/180 *PI;
	data->map.scale = 30;
	data->map.n_rows = count_rows(fd);
	data->map.c = malloc ((sizeof(t_coords *)* data->map.n_rows));
	close(fd);
	fd = open(file, O_RDONLY);
	char **lines = malloc(sizeof(char *) * data->map.n_rows);
	while (i < data->map.n_rows)
	{
		lines[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	while(i < data->map.n_rows)
	{
		if(line_to_coords(lines[i], data, i) != 0)
			destroy_win_and_img(data);
		i++;
	}
	i = 0;
	while (i < data->map.n_rows)
	{
		free (lines[i]);
		i++;
	}
	free (lines);
	free (file);
}