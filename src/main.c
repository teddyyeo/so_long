/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:22:14 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/22 21:55:43 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key(int keycode, t_vars *vars)
{
	int	new_pos;
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == W)
	{
		new_pos = vars->player - (vars->w / 32);
		ft_printf("pos: %d\n", new_pos);
		ft_printf("%c\n", vars->map[new_pos]);
		ft_printf("pos: %d\n", vars->player);
		put_img(vars, vars->img[1], new_pos);
		vars->player = new_pos;
	}
	else if (keycode == A)
	{
		new_pos = vars->player - 1;
	}
	else if (keycode == S)
	{
		new_pos = vars->player + (vars->w / 32);
	}
	else if (keycode == D)
	{
		new_pos = vars->player + 1;
	}
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
