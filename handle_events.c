#include "fdf.h"
#include <stdio.h>

int	handle_no_event(void *data)
{
	(void)*data;
	return(0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	(void)*data;
    if (keysym == XK_Escape)
	{
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (keysym == XK_Left)
	{
		data->map.a_z += 0.1;
		printf("a_left: %f\n", data->map.a_z);
	}
	if (keysym == XK_Right)
	{
		data->map.a_z -= 0.1;
		printf("a_right: %f\n", data->map.a_z);
	}
	if (keysym == XK_Up)
	{
		data->map.a_x += 0.1;
		printf("a_up: %f\n", data->map.a_x);
	}
	if (keysym == XK_Down)
	{
		data->map.a_x -= 0.1;
		printf("a_down: %f\n", data->map.a_x);
	}
//    printf("Keypress: %d\n", keysym);
	return(0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)*data;
    printf("Keyrelease: %d\n", keysym);
    return (0);
}