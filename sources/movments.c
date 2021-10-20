/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:16:15 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 11:45:13 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_vars *vars)
{
	t_pos	current_pos;
	int		res;

	res = 0;
	current_pos = get_pos_player(*vars);
	if (vars->map[current_pos.y - 1][current_pos.x] == '1')
		res = on_wall();
	else if (vars->map[current_pos.y - 1][current_pos.x] == 'C')
		res = on_collectible(vars, current_pos.y - 1,
				current_pos.x, current_pos);
	else if (vars->map[current_pos.y - 1][current_pos.x] == 'E')
		res = on_exit(vars);
	else
		res = on_nothing(vars, current_pos.y - 1, current_pos.x, current_pos);
	if (res)
	{
		create_visual_map(*vars);
		vars->nbr_mov++;
		printf("nbr moves = %d\n", vars->nbr_mov);
		if (res == 2)
			close_escape(vars);
	}
}

void	go_down(t_vars *vars)
{
	t_pos	current_pos;
	int		res;

	res = 0;
	current_pos = get_pos_player(*vars);
	if (vars->map[current_pos.y + 1][current_pos.x] == '1')
		res = on_wall();
	else if (vars->map[current_pos.y + 1][current_pos.x] == 'C')
		res = on_collectible(vars, current_pos.y + 1,
				current_pos.x, current_pos);
	else if (vars->map[current_pos.y + 1][current_pos.x] == 'E')
		res = on_exit(vars);
	else
		res = on_nothing(vars, current_pos.y + 1, current_pos.x, current_pos);
	if (res)
	{
		create_visual_map(*vars);
		vars->nbr_mov++;
		printf("number moves = %d\n", vars->nbr_mov);
		if (res == 2)
			close_escape(vars);
	}
}

void	go_left(t_vars *vars)
{
	t_pos	current_pos;
	int		res;

	res = 0;
	current_pos = get_pos_player(*vars);
	if (vars->map[current_pos.y][current_pos.x - 1] == '1')
		res = on_wall();
	else if (vars->map[current_pos.y][current_pos.x - 1] == 'C')
		res = on_collectible(vars, current_pos.y,
				current_pos.x - 1, current_pos);
	else if (vars->map[current_pos.y][current_pos.x - 1] == 'E')
		res = on_exit(vars);
	else
		res = on_nothing(vars, current_pos.y, current_pos.x - 1, current_pos);
	if (res)
	{
		create_visual_map(*vars);
		vars->nbr_mov++;
		printf("nbr moves = %d\n", vars->nbr_mov);
		if (res == 2)
			close_escape(vars);
	}
}

void	go_right(t_vars *vars)
{
	t_pos	current_pos;
	int		res;

	res = 0;
	current_pos = get_pos_player(*vars);
	if (vars->map[current_pos.y][current_pos.x + 1] == '1')
		res = on_wall();
	else if (vars->map[current_pos.y][current_pos.x + 1] == 'C')
		res = on_collectible(vars, current_pos.y,
				current_pos.x + 1, current_pos);
	else if (vars->map[current_pos.y][current_pos.x + 1] == 'E')
		res = on_exit(vars);
	else
		res = on_nothing(vars, current_pos.y, current_pos.x + 1, current_pos);
	if (res)
	{
		create_visual_map(*vars);
		vars->nbr_mov++;
		printf("nbr moves = %d\n", vars->nbr_mov);
		if (res == 2)
			close_escape(vars);
	}
}
