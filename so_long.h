/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:28:20 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/24 18:15:38 by tayeo            ###   ########.fr       */
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
**	Struct for mlx data
*/
typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	char	*map;
	int		position;
	int		item_cnt;
	void	*wall;
	void	*exit;
	void	*player;
	void	*item;
	void	*ground;
	int		move_cnt;
	void	*num[10];
}				t_vars;

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
void	draw(t_vars *vars);
void	put_img(t_vars *vars, void *img, int idx);

void	move(int pos, t_vars *vars);
int		on_exit(t_vars *vars);
int		key(int keycode, t_vars *vars);

void	print_num(t_vars vars);

void	set_num(t_vars *vars);
void	set_image(t_vars *vars);
#endif
