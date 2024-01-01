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
//    printf("Keypress: %d\n", keysym);
	return(0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)*data;
    printf("Keyrelease: %d\n", keysym);
    return (0);
}