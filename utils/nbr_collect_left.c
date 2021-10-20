/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_collect_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:15:22 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 11:45:48 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

int	nbr_collect_left(t_vars vars)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (i < vars.win.raw_height)
	{
		j = 0;
		while (j < vars.win.raw_width)
		{
			if (vars.map[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}
