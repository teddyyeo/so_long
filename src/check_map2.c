/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:14:36 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/24 18:18:13 by tayeo            ###   ########.fr       */
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
			write(1, "\nError\n: Vertical wall is breached!\n", 36);
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
		write(1, "\nError\n: Horizontal wall is breached!\n", 38);
		free(line);
		exit(EXIT_FAILURE);
	}
}

void	rectangle_check(char *line, char **prev)
{
	if (ft_strlen(line) != ft_strlen(*prev))
	{
		write(1, "\nError\n: Not rectangle!\n", 25);
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
		write(1, "\nError\n: Line is empty!\n", 25);
		exit(EXIT_FAILURE);
	}
}
