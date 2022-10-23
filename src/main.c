/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:22:14 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/23 17:15:52 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(int pos, t_vars *vars)
{
	char	p;

	p = vars->map[pos];
	if (p != '1' && (p != 'E' || vars->item == 0))
	{
		put_img(vars, vars->img[2], vars->player); // overwrite with background image
		put_img(vars, vars->img[2], pos); // overwrite with background image
		put_img(vars, vars->img[1], pos);// put player image to position
		if (p == 'E') //if all items are collected and player reached exit
			exit(EXIT_SUCCESS); // end game
		else if (vp == 'C') // if there is a collectible at the position
			vars->item--; //reduce item count
		vars->map[vars->player] == '0';
		p == 'P';
		vars->player = pos;
	}
}

int	key(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == W)
		move(vars->player - (vars->w / 32), vars);
	else if (keycode == A)
		move(vars->player - 1, vars);
	else if (keycode == S)
		move(vars->player + (vars->w / 32), vars);
	else if (keycode == D)
		move(vars->player + 1, vars);
	return (0);
}

void	set_image(t_vars *vars, void *img[5])
{
	int	width;
	int	height;

	img[0] = mlx_xpm_file_to_image(vars->mlx, "./skull.xpm", &width, &height);
	img[1] = mlx_xpm_file_to_image(vars->mlx, "./brain.xpm", &width, &height);
	img[2] = mlx_xpm_file_to_image(vars->mlx, "./letter.xpm", &width, &height);
	img[3] = mlx_xpm_file_to_image(vars->mlx, "./scroll.xpm", &width, &height);
}

int	main(int argc, char **argv)
{
	int			map;
	t_vars		vars;
	//void		*img[5];

	argument_check(argc);
	extension_check(argv[1]);
	check_map(argv[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.w, vars.h, "so_long");
	set_image(&vars, vars.img);
	save_map(argv[1], &vars);
	map = open(argv[1], O_RDONLY);
	ft_printf("%s", vars.map);
	draw(&vars, vars.img);
	close(map);
	mlx_key_hook(vars.win, key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
