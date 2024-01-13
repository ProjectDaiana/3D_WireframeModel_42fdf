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
	//(void)*data;
    if (keysym == XK_Escape)
	{
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
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
		data->map.scale += 10;
	if (keysym == XK_KP_Subtract)
		data->map.scale -= 10;
    // printf("Keypress: %d\n", keysym);
	return(0);
}

int handle_leftclick(int click, t_img *img)
{

	if (click == 1)
	{
		printf("click: %d\n",click);
		img->mid = 2;
	}
	
	return(0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)*data;
    printf("Keyrelease: %d\n", keysym);
    return (0);
}