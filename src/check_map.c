/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:23:00 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/24 18:17:30 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_object(char *line, t_map *map)
{
	while (*line != '\n')
	{
		if (*line == 'P')
		{
			if (map->player == 1)
			{
				write(1, "\nError\n: More than one player!\n", 32);
				free(line);
				exit(EXIT_FAILURE);
			}
			map->player = 1;
		}
		else if (*line == 'C')
			map->item++;
		else if (*line == 'E')
			map->exit = 1;
		line++;
	}
}

void	object_check(t_map map)
{
	if (map.player == 0)
	{
		write(1, "\nError\n: No player!\n", 21);
		exit(EXIT_FAILURE);
	}
	else if (map.item == 0)
	{
		write(1, "\nError\n: No item!\n", 19);
		exit(EXIT_FAILURE);
	}
	else if (map.exit == 0)
	{
		write(1, "\nError\n: No exit!\n", 19);
		exit(EXIT_FAILURE);
	}
}

void	init_object_to_zero(t_map *map)
{
	map->player = 0;
	map->item = 0;
	map->exit = 0;
}

void	check(int fd, t_vars *vars)
{
	char	*line;
	char	*prev;
	t_map	map;
	int		idx;

	idx = 1;
	init_object_to_zero(&map);
	line = get_next_line(fd);
	x_wall_check(line);
	prev = line;
	line = get_next_line(fd);
	while (line != NULL)
	{
		rectangle_check(line, &prev);
		find_object(line, &map);
		y_wall_check(line);
		line = get_next_line(fd);
		idx++;
	}
	x_wall_check(prev);
	vars->h = idx * 32;
	vars->w = (int)ft_strlen(prev) * 32;
	vars->item_cnt = map.item;
	free(prev);
	object_check(map);
}

void	check_map(char *filename, t_vars *vars)
{
	int	map;

	map = open(filename, O_RDONLY);
	open_check(map);
	check(map, vars);
	close(map);
}
