/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:03:43 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 11:46:29 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

t_pos	get_pos_player(t_vars vars)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	while (i < vars.win.raw_height)
	{
		j = 0;
		while (j < vars.win.raw_width)
		{
			if (vars.map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}
