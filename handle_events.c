/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:10:47 by darotche          #+#    #+#             */
/*   Updated: 2024/01/28 21:41:59 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	close_window(t_data *data)
{
	destroy_win_and_img(data);
	exit (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == XK_Left)
		data->map.a_z += 0.1;
	if (keysym == XK_Right)
		data->map.a_z -= 0.1;
	if (keysym == XK_Up)
		data->map.a_x += 0.1;
	if (keysym == XK_Down)
		data->map.a_x -= 0.1;
	if (keysym == XK_Down)
		data->map.a_x -= 0.1;
	if (keysym == XK_KP_Add)
		data->map.scale += 1;
	if (keysym == XK_KP_Subtract)
	{
		if (data->map.scale > 5)
			data->map.scale -= 0.5;
	}
	return (0);
}

int	handle_leftclick(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->map.click = !data->map.click;
		data->map.x_mouse_pos = x;
		data->map.y_mouse_pos = y;
	}
	return (0);
}

int	follow_mouse(t_data *data)
{
	static int	x_mouse;
	static int	y_mouse;

	if (!data->map.click)
		return (0);
	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &x_mouse, &y_mouse);
	if (data->map.x_mouse_pos > x_mouse)
		data->map.x_mouse_mov -= data->map.x_mouse_pos - x_mouse;
	else if (data->map.x_mouse_pos < x_mouse)
		data->map.x_mouse_mov += x_mouse - data->map.x_mouse_pos;
	if (data->map.y_mouse_pos > y_mouse)
		data->map.y_mouse_mov -= data->map.y_mouse_pos - y_mouse;
	else if (data->map.y_mouse_pos < y_mouse)
		data->map.y_mouse_mov += y_mouse - data->map.y_mouse_pos;
	data->map.x_mouse_pos = x_mouse;
	data->map.y_mouse_pos = y_mouse;
	return (0);
}
