/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:17 by darotche          #+#    #+#             */
/*   Updated: 2024/02/04 22:11:37 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_to_coords(char *str, t_data *data, int row)
{
	char	**split_str;
	int		col;

	col = 0;
	split_str = ft_split(str, ' ');
	while (split_str[col] != NULL && split_str[col][0] != '\n')
		col++;
	data->map.n_cols = col;
	data->map.c[row] = ft_calloc(col + 1, sizeof(t_coords));
	col = 0;
	while (split_str[col] != NULL && split_str[col][0] != '\n')
	{
		data->map.c[row][col].z = ft_atoi(split_str[col]);
		col++;
	}
	if (col >= data->map.max_n_cols)
		data->map.max_n_cols = col;
	else if (col < data->map.max_n_cols)
	{
		ft_printf(RED"Can not read map. Exiting program.\n"WHT);
		free_array(split_str);
		return (1);
	}
	free_array(split_str);
	return (0);
}

int	count_rows(int fd)
{
	int		rows;
	char	*tmp;

	rows = 0;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (0);
	while (tmp)
	{
		rows++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (rows);
}

char	*file_name(char *argv)
{
	char	*filename;

	filename = ft_strjoin("./test_maps/", argv);
	return (filename);
}

void	start_map(t_data *data, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED"Wrong file.\n"WHT);
		free(file);
		destroy_win_and_img(data);
	}
	data->map.a_x = 30.0 / 180 * PI;
	data->map.a_z = 30.0 / 180 * PI;
	data->map.scale = 10;
	data->map.n_rows = count_rows(fd);
	data->map.c = ft_calloc (data->map.n_rows + 1, (sizeof(t_coords *)));
	close(fd);
}

void	import_map(char *file, t_data *data)
{
	int		fd;
	int		i;
	char	**lines;

	i = 0;
	start_map(data, file);
	fd = open(file, O_RDONLY);
	lines = ft_calloc(data->map.n_rows + 1, sizeof(char *));
	while (i < data->map.n_rows)
	{
		lines[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < data->map.n_rows)
	{	
		if (line_to_coords(lines[i], data, i) != 0)
		{
			destroy_win_and_img(data);
			int j = 0;
			while(lines[j])
				free (lines[j++]);
			free (lines);
			free(file);
			exit (0);
		}
		i++;
	}
	
		// int read_lines = line_to_coords(lines[i], data, i);
		// if (read_lines != 0)
		// {
		// 	//printf("read lines %d\n",read_lines);
		// 	destroy_win_and_img(data);
		// 	int j = 0;
		// 	while(lines[j])
		// 		free (lines[j++]);
		// 	free (lines);
		// 	free(file);
		// 	exit (0);
		// }
		// i++;
	i = 0;
	while (i < data->map.n_rows)
		free (lines[i++]);
	free (lines);
	free (file);
}
