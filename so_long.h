/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:28:20 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/22 21:52:58 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2

/*
**	Struct for image
*/
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}				t_data;

/*
**	Struct for mlx data
*/
typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	char	*map;
	int		player;
	void	*img[5];
}				t_vars;

/*
**	Struct for xmp file, store filepath in path
**	set width and height with xpm_file_to_image
*/
typedef struct s_xpm {
	char	*path;
	int		width;
	int		height;
}				t_xpm;

/*
** Struct needed for map check
*/
typedef struct s_map {
	int	item;
	int	exit;
	int	player;
}				t_map;

void	find_object(char *line, t_map *map);
void	object_check(t_map map);
void	init_object_to_zero(t_map *map);

void	check(int fd, t_vars *vars);
void	check_map(char *filename, t_vars *vars);
void	x_wall_check(char *line);
void	y_wall_check(char *line);
void	rectangle_check(char *line, char **prev);
void	empty_check(char *line);

void	argument_check(int argc);
void	extension_check(char *str);
void	open_check(int fd);

void	save_map(char *filename, t_vars *vars);
void	draw(t_vars *vars, void **img);
void	put_img(t_vars *vars, void *img, int idx);
#endif
