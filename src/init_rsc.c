/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rsc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:10:46 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/24 18:11:07 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_num(t_vars *vars)
{
	int	w;
	int	h;

	vars->num[0] = mlx_xpm_file_to_image(vars->mlx, "num/0.xpm", &w, &h);
	vars->num[1] = mlx_xpm_file_to_image(vars->mlx, "num/1.xpm", &w, &h);
	vars->num[2] = mlx_xpm_file_to_image(vars->mlx, "num/2.xpm", &w, &h);
	vars->num[3] = mlx_xpm_file_to_image(vars->mlx, "num/3.xpm", &w, &h);
	vars->num[4] = mlx_xpm_file_to_image(vars->mlx, "num/4.xpm", &w, &h);
	vars->num[5] = mlx_xpm_file_to_image(vars->mlx, "num/5.xpm", &w, &h);
	vars->num[6] = mlx_xpm_file_to_image(vars->mlx, "num/6.xpm", &w, &h);
	vars->num[7] = mlx_xpm_file_to_image(vars->mlx, "num/7.xpm", &w, &h);
	vars->num[8] = mlx_xpm_file_to_image(vars->mlx, "num/8.xpm", &w, &h);
	vars->num[9] = mlx_xpm_file_to_image(vars->mlx, "num/9.xpm", &w, &h);
}

void	set_image(t_vars *vars)
{
	int	w;
	int	h;

	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./wall.xpm", &w, &h);
	vars->player = mlx_xpm_file_to_image(vars->mlx, "./player.xpm", &w, &h);
	vars->item = mlx_xpm_file_to_image(vars->mlx, "./item.xpm", &w, &h);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./exit.xpm", &w, &h);
	vars->ground = mlx_xpm_file_to_image(vars->mlx, "./background.xpm", &w, &h);
}
