/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surrounded_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:42:40 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 13:26:40 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

int	check_first_line(t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.win.raw_width - 1)
	{
		if (vars.map[0][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_last_line(t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.win.raw_width - 1)
	{
		if (vars.map[vars.win.raw_height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_first_col(t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.win.raw_height - 1)
	{
		if (vars.map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_last_col(t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.win.raw_height - 1)
	{
		if (vars.map[i][vars.win.raw_width - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	surrounded_wall(t_vars vars)
{
	if (!check_first_line(vars))
	{
		printf("Error\nThe map isn't surrounded by walls!\n");
		return (0);
	}
	if (!check_last_line(vars))
	{
		printf("Error\nThe map isn't surrounded by walls!\n");
		return (0);
	}
	if (!check_first_col(vars))
	{
		printf("Error\nThe map isn't surrounded by walls!\n");
		return (0);
	}
	if (!check_last_col(vars))
	{
		printf("Error\nThe map isn't surrounded by walls!\n");
		return (0);
	}
	return (1);
}
