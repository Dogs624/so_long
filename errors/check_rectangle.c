/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:23:08 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 11:40:21 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

int	check_rectangle(t_vars vars)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen(vars.map[0]);
	while (i < vars.win.raw_height)
	{
		if (i == vars.win.raw_height - 1)
			j = ft_strlen(vars.map[0]) - 1;
		if ((size_t)j != ft_strlen(vars.map[i]))
		{
			printf("Error\nThis is not a rectangular map!\n");
			return (0);
		}
		i++;
	}
	if (i == j)
	{
		printf("Error\nThis is not a rectangular map!\n");
		return (0);
	}
	return (1);
}
