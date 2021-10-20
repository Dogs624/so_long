/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:11:38 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 11:43:50 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_collectible(t_vars *vars, int pos_y, int pos_x, t_pos current_pos)
{
	vars->map[current_pos.y][current_pos.x] = '0';
	vars->map[pos_y][pos_x] = 'P';
	printf("You've catch a collectible - %d left\n",
		nbr_collect_left(*vars));
	return (1);
}

int	on_exit(t_vars *vars)
{
	if (nbr_collect_left(*vars) == 0)
	{
		printf("You found the exit\n");
		return (2);
	}
	else
	{
		printf("%d collectibles left... Can't leave now !\n",
			nbr_collect_left(*vars));
		return (0);
	}
}

int	on_nothing(t_vars *vars, int pos_y, int pos_x, t_pos current_pos)
{
	vars->map[current_pos.y][current_pos.x] = '0';
	vars->map[pos_y][pos_x] = 'P';
	return (1);
}

int	on_wall(void)
{
	printf("There is a wall there !\n");
	return (0);
}
