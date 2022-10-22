/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:41:41 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/21 18:29:08 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	argument_check(int argc)
{
	if (argc != 2)
	{
		write(1, "\nArgument Error: Enter one argument!\n", 37);
		exit(EXIT_FAILURE);
	}
}

void	extension_check(char *str)
{
	size_t	l;

	l = ft_strlen(str);
	if (l < 4 || str[l - 1] != 'r' || str[l - 2] != 'e' \
	|| str[l - 3] != 'b' || str[l - 4] != '.')
	{
		write(1, "\nFile Error: Wrong extension, must end in .ber\n", 48);
		exit(EXIT_FAILURE);
	}
}

void	open_check(int fd)
{
	if (fd == -1)
	{
		write(1, "\nFile Error: Failed open\n", 25);
		exit(EXIT_FAILURE);
	}
}
