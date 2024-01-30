/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:33 by darotche          #+#    #+#             */
/*   Updated: 2024/01/30 18:06:14 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_data *data)
{
	static double	last_a_z;
	static double	last_a_x;
	static int		last_scale;

	if (data->win_ptr == NULL)
		return (1);
	if (data->img.mlx_img && (last_a_z != data->map.a_z
			|| last_a_x != data->map.a_x))
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	}
	if (data->img.mlx_img && (last_scale != data->map.scale))
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	}
	convert_to_iso(&data->map, data);
	asign_colors(&data->map);
	draw_lines(&data->img, &data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	last_a_z = data->map.a_z;
	last_a_x = data->map.a_x;
	return (0);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	if (argc != 2)
	{
		ft_printf(RED"Wrong arguments. Insert ./fdf and map name.\n"WHT);
		exit(1);
	}
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	if (data.win_ptr == NULL)
		return (MLX_ERROR);
	import_map(file_name(argv[1]), &data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_mouse_hook(data.win_ptr, handle_leftclick, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_window, &data);
	mlx_loop(data.mlx_ptr);
	destroy_win_and_img(&data);
}
