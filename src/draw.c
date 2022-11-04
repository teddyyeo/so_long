/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:38:35 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/24 18:06:32 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_ground(t_vars *vars, void	*img)
{
	int	idx;
	int	jdx;

	idx = 0;
	while (idx < vars->h)
	{
		jdx = 0;
		while (jdx < vars->w - 32)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img, jdx, idx);
			jdx += 32;
		}
		idx += 32;
	}
}

void	save_map(char *filename, t_vars *vars)
{
	int		map;
	char	*line;

	vars->map = NULL;
	map = open(filename, O_RDONLY);
	open_check(map);
	line = get_next_line(map);
	while (line != NULL)
	{
		vars->map = gnl_ft_strjoin(vars->map, line, 1);
		free(line);
		line = get_next_line(map);
	}
	close(map);
}

void	put_img(t_vars *vars, void *img, int idx)
{
	int	x;
	int	y;

	x = (idx % (vars->w / 32)) * 32;
	y = (idx / (vars->w / 32)) * 32;
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void	draw(t_vars *vars)
{
	int	idx;

	idx = 0;
	draw_ground(vars, vars->ground);
	while (vars->map[idx])
	{
		if (vars->map[idx] == 'P')
		{
			put_img(vars, vars->player, idx);
			vars->position = idx;
		}
		else if (vars->map[idx] == 'C')
			put_img(vars, vars->item, idx);
		else if (vars->map[idx] == 'E')
			put_img(vars, vars->exit, idx);
		else if (vars->map[idx] == '1')
			put_img(vars, vars->wall, idx);
		idx++;
	}
}
