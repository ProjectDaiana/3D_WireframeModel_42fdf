#include "fdf.h"

///// COLOR
//#include <inttypes.h>

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

/////////// IMPORT /////////////////////////////////////

int max_z(t_map *map)
{
	int x;
	int y;
	int max_z;

	x = 0;
	y = 0;
	max_z = map->coords[x][y].z;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (max_z < map->coords[x][y].z)
				max_z = map->coords[x][y].z;
			y++;
		}
		x++;
	}
	return (max_z);
}

int min_z(t_map *map)
{
	int x;
	int y;
	int min_z;

	x = 0;
	y = 0;
	min_z = map->coords[x][y].z;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (min_z > map->coords[x][y].z)
				min_z = map->coords[x][y].z;
			y++;
		}
		x++;
	}
	return (min_z);
}

int	gradient(int startcolor, int endcolor, int len, int i)
{
	double increment[3];
	int new[3];
	int newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
    increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
    increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;

    new[0] = (R(startcolor)) + round(i * increment[0]);
    new[1] = (G(startcolor)) + round(i * increment[1]);
    new[2] = (B(startcolor)) + round(i * increment[2]);

    newcolor = RGB(new[0], new[1], new[2]);

    return (newcolor);
}

void asign_colors(t_map *map)
{
	int x;
	int y;
	int startcolor = RGB(230, 215, 250);
	int midcolor = RGB(80, 20, 230);
	int endcolor = RGB(20, 0, 30);

	x = 0;
	while (x < map->n_rows)
	{
		y = 0;
		while (y < map->n_cols)
		{
			if (map->coords[x][y].z == max_z(map))
				map->coords[x][y].color = startcolor;
			else if (map->coords[x][y].z == min_z(map))
				map->coords[x][y].color = endcolor;
			else
				map->coords[x][y].color = midcolor;
			y++;
		}
		x++;
	}
}
