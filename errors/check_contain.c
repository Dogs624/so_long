/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:31:35 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 13:31:29 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

static int	contain_exit(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.win.raw_height)
	{
		j = 0;
		while (j < vars.win.raw_width)
		{
			if (vars.map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	printf("Error\nThe map doesn't contain an exit!\n");
	return (0);
}

static int	contain_player(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.win.raw_height)
	{
		j = 0;
		while (j < vars.win.raw_width)
		{
			if (vars.map[i][j] == 'P')
				return (1);
			j++;
		}
		i++;
	}
	printf("Error\nThe map doesn't contain a player!\n");
	return (0);
}

static int	contain_collectible(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.win.raw_height)
	{
		j = 0;
		while (j < vars.win.raw_width)
		{
			if (vars.map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	printf("Error\nThe map doesn't contain a collectible!\n");
	return (0);
}

static int	contain_stranger(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.win.raw_height)
	{
		j = 0;
		while (j < vars.win.raw_width - 1)
		{
			if (vars.map[i][j] != '0' && vars.map[i][j] != '1'
				&& vars.map[i][j] != 'C' && vars.map[i][j] != 'P'
				&& vars.map[i][j] != 'E')
			{
				printf("Error\nThe map contains an unknown character!\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_contain(t_vars vars)
{
	if (contain_stranger(vars))
		return (0);
	if (!contain_exit(vars))
		return (0);
	if (!contain_player(vars))
		return (0);
	if (!contain_collectible(vars))
		return (0);
	return (1);
}
