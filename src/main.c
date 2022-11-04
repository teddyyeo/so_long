/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:22:14 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/24 18:15:00 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_num(t_vars vars)
{
	int		digit[3];
	void	*n[3];

	digit[0] = vars.move_cnt % 10;
	digit[1] = vars.move_cnt / 10 % 10;
	digit[2] = vars.move_cnt / 100 % 10;
	n[0] = vars.num[digit[0]];
	n[1] = vars.num[digit[1]];
	n[2] = vars.num[digit[2]];
	mlx_put_image_to_window(vars.mlx, vars.win, n[2], 0, vars.h);
	mlx_put_image_to_window(vars.mlx, vars.win, n[1], 84, vars.h);
	mlx_put_image_to_window(vars.mlx, vars.win, n[0], 168, vars.h);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	vars.move_cnt = 0;
	argument_check(argc);
	extension_check(argv[1]);
	check_map(argv[1], &vars);
	vars.mlx = mlx_init();
	if (vars.w < 84 * 3 + 32)
		vars.win = mlx_new_window(vars.mlx, 84 * 3, vars.h + 84, "SL");
	else
		vars.win = mlx_new_window(vars.mlx, vars.w - 32, vars.h + 84, "SL");
	set_image(&vars);
	set_num(&vars);
	save_map(argv[1], &vars);
	draw(&vars);
	mlx_hook(vars.win, 2, 0, key, &vars);
	mlx_hook(vars.win, 17, 0, on_exit, &vars);
	print_num(vars);
	mlx_loop(vars.mlx);
	return (0);
}
