/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:04:02 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/24 18:13:04 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(int pos, t_vars *vars)
{
	char	p;

	p = vars->map[pos];
	if (p != '1' && (p != 'E' || vars->item_cnt == 0))
	{
		vars->move_cnt++;
		ft_printf("Move count: %d\n", vars->move_cnt);
		print_num(*vars);
		put_img(vars, vars->ground, vars->position);
		put_img(vars, vars->ground, pos);
		put_img(vars, vars->player, pos);
		if (p == 'E')
			exit(EXIT_SUCCESS);
		else if (p == 'C')
			vars->item_cnt--;
		vars->map[vars->position] = '0';
		vars->position = pos;
	}
}

int	on_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

int	key(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == W)
		move(vars->position - (vars->w / 32), vars);
	else if (keycode == A)
		move(vars->position - 1, vars);
	else if (keycode == S)
		move(vars->position + (vars->w / 32), vars);
	else if (keycode == D)
		move(vars->position + 1, vars);
	return (0);
}
