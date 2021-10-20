/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:58:14 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 13:57:40 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_escape(t_vars *vars)
{
	ft_free(vars->map, vars->win.raw_height);
	mlx_destroy_window(vars->mlx, vars->win.win);
	exit (0);
}

int	close_window(t_vars *vars)
{
	ft_free(vars->map, vars->win.raw_height);
	exit (0);
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == 13)
		go_up(vars);
	else if (keycode == 0)
		go_left(vars);
	else if (keycode == 1)
		go_down(vars);
	else if (keycode == 2)
		go_right(vars);
	else if (keycode == 53)
		close_escape(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (!check_args(argc, argv))
		exit(0);
	vars = create_window(argv[1]);
	vars.map = create_map(argv[1], vars);
	keep_one_player(&vars);
	if (!error_handling(vars))
	{
		close_escape(&vars);
		ft_free(vars.map, vars.win.raw_height);
		exit (0);
	}
	create_bckgrnd(vars);
	create_visual_map(vars);
	mlx_hook(vars.win.win, 2, 1L >> 0, close_escape, &vars);
	mlx_hook(vars.win.win, 17, 0L, close_window, &vars);
	mlx_hook(vars.win.win, 2, 1L >> 0, move, &vars);
	mlx_loop(vars.mlx);
	ft_free(vars.map, vars.win.raw_height);
	exit (0);
}
