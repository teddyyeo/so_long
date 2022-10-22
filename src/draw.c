/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:38:35 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/22 20:45:26 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_wall(t_vars *vars, void *img)
{
	int		idx;

	idx = 0;
	while (idx < vars->h)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img, 0, idx);
		mlx_put_image_to_window(vars->mlx, vars->win, img, vars->w - 32, idx);
		idx += 32;
	}
	idx = 0;
	while (idx < vars->w)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img, idx, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, img, idx, vars->h - 32);
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
	ft_printf("(x, y) = (%d, %d)\n", x/32, y/32);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void	draw(t_vars *vars, void **img)
{
	int	idx;

	idx = 0;
	draw_wall(vars, img[0]);
	while (vars->map[idx])
	{
		if (vars->map[idx] == 'P')
		{
			put_img(vars, img[1], idx);
			vars->player = idx;
		}
		else if (vars->map[idx] == 'C')
			put_img(vars, img[2], idx);
		else if (vars->map[idx] == 'E')
			put_img(vars, img[3], idx);
		idx++;
	}
}
