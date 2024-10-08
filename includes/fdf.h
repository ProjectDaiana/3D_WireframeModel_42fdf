/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darotche <darotche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:11:25 by darotche          #+#    #+#             */
/*   Updated: 2024/08/26 14:24:39 by darotche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH 1200
# define W_HEIGHT 860
# define MLX_ERROR 1
# define PI 3.141592653589

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define RESET "\033[0m"

# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_line
{
	int x1;
int y1;
    int x2;
    int y2;
    int color1;
    int color2;
} 	t_line;

typedef struct s_coords
{
	int	x_t;
	int	y_t;
	int	z;
	int	color;
}	t_coords;

typedef struct s_map
{
	int			n_cols;
	int			max_n_cols;
	int			n_rows;
	double		a_x;
	double		a_z;
	int			scale;
	bool		click;
	int			x_mouse_pos;
	int			y_mouse_pos;
	int			x_mouse_mov;
	int			y_mouse_mov;
	int			min_z;
	int			max_z;
	t_coords	**c;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_img	img;
	t_line line;
}	t_data;

int		handle_no_event(void *data);
int		handle_input(int keysym, t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, void *data);
int		handle_leftclick(int click, int x, int y, t_data *data);
int		follow_mouse(t_data *data);
int		close_window(t_data *data);
int		ft_printf(const char *format, ...);

void	*mlx_new_image(void *mlx_ptr, int width, int height);
void	img_pix_put(t_img *img, int x, int y, int color);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			int *size_line, int *endian);

char	*file_name(char *argv);
void	start_map(t_data *data, char *file);
void	import_map(char argv[1], t_data *data);
char	*get_next_line(int fd);

int		render(t_data *data);
int		line_to_coords(char *str, t_data *data, int row);
void	draw_lines(t_img *img, t_map *map, t_line *line );
void	convert_to_iso(t_map *map, t_data *data);

int		max_z(t_map *map);
int		min_z(t_map *map);
void	asign_colors(t_map *map, int s_color, int e_color);
int		rgb(int r, int g, int b);
int		gradient(int s_color, int e_color, int line_len, int i);

void	destroy_win_and_img(t_data *data);
void	free_lines(char **lines);
void	free_row(t_data *data);
void	free_array(char **array);

#endif