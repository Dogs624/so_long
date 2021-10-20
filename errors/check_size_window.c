/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:56:38 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/19 16:17:46 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

int	check_size_window(t_vars vars)
{
	int	size_x;
	int	size_y;

	mlx_get_screen_size(vars.mlx, &size_x, &size_y);
	if (vars.win.height >= size_y)
	{
		printf("Error\nThe size of the map is too big\n");
		return (0);
	}
	if (vars.win.width >= size_x)
	{
		printf("Error\nThe size of the map is too big\n");
		return (0);
	}
	return (1);
}
