/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:14:36 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/21 17:51:47 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	x_wall_check(char *line)
{
	empty_check(line);
	while (*line != '\n')
	{
		if (*line != '1')
		{
			write(1, "\nMap Error: Vertical wall is breached!\n", 39);
			free(line);
			exit(EXIT_FAILURE);
		}
		line++;
	}
}

void	y_wall_check(char *line)
{
	if (*line != '1' || line[ft_strlen(line) - 2] != '1')
	{
		write(1, "\nMap Error: Horizontal wall is breached!\n", 41);
		free(line);
		exit(EXIT_FAILURE);
	}
}

void	rectangle_check(char *line, char **prev)
{
	if (ft_strlen(line) != ft_strlen(*prev))
	{
		write(1, "\nMap Error: Not rectangle!\n", 28);
		free(line);
		free(*prev);
		exit(EXIT_FAILURE);
	}
	free(*prev);
	*prev = line;
}

void	empty_check(char *line)
{
	if (line == NULL)
	{
		write(1, "\nMap Error: Line is empty!\n", 28);
		exit(EXIT_FAILURE);
	}
}
