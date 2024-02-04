/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:54 by darotche          #+#    #+#             */
/*   Updated: 2024/02/04 14:01:17 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_row(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.n_rows)
	{
		free(data->map.c[i]);
		i++;
	}
	free(data->map.c);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void	destroy_win_and_img(t_data *data)
{
	if (data->img.mlx_img != NULL)
	{
		mlx_destroy_image (data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = NULL;
	}
	if (data->win_ptr != NULL)
	{
		mlx_destroy_window (data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	free_row(data);
	return ;
}
