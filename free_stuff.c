/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:54 by darotche          #+#    #+#             */
/*   Updated: 2024/01/26 18:39:20 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_stuff(t_data *data)
{
	int i;

	i = 0;
	while(i < data->map.n_rows)
	{
		free(data->map.c[i]);
		i++;
	}
	free(data->map.c);
	free(data->mlx_ptr);
}

void free_arr2D(char **arr2D)
{
	int i;

	i = 0;
	while (arr2D[i] != NULL && arr2D[i][0] != '\n')
		free(arr2D[i++]);
	free(arr2D);
}

int	free_gnl_buff(int fd, char *line)
{
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}