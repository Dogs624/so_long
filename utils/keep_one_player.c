/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_one_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:39:21 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 13:03:33 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

void	keep_one_player(t_vars *vars)
{
	int	found;
	int	i;
	int	j;

	i = 0;
	found = 0;
	while (i < vars->win.raw_height)
	{
		j = 0;
		while (j < vars->win.raw_width)
		{
			if (!found && vars->map[i][j] == 'P')
				found = 1;
			else if (found && vars->map[i][j] == 'P')
				vars->map[i][j] = '0';
			j++;
		}
		i++;
	}
}
