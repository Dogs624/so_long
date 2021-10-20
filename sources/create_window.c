/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:45:08 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 11:30:01 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	create_window(char *file)
{
	t_vars	vars;
	int		width;
	int		height;

	width = get_width_map(file);
	height = get_height_map(file);
	vars.mlx = mlx_init();
	vars.win.win = mlx_new_window(vars.mlx, (width - 1) * MAP_SIZE,
			height * (MAP_SIZE - 1), "so_long");
	vars.win.width = (width - 1) * MAP_SIZE;
	vars.win.height = height * (MAP_SIZE - 1);
	vars.win.raw_height = height;
	vars.win.raw_width = width;
	vars.nbr_mov = 0;
	return (vars);
}
