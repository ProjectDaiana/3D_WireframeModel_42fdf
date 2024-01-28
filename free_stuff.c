/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:54 by darotche          #+#    #+#             */
/*   Updated: 2024/01/28 20:15:19 by darotche         ###   ########.fr       */
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
}

void free_arr2D(char **arr2D)
{
	int i;

	i = 0;
	while (arr2D[i] != NULL && arr2D[i][0] != '\n')
		free(arr2D[i++]);
	free(arr2D);
}

int destroy_win_and_img(t_data *data) 
{
    if (data->img.mlx_img != NULL) {
        mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
        data->img.mlx_img = NULL;
    }
    if (data->win_ptr != NULL) {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    if (data->mlx_ptr != NULL) {
        mlx_destroy_display(data->mlx_ptr);
        data->mlx_ptr = NULL;
    }
	free_stuff(data);
    exit(0);
}