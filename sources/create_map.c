/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:42:10 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 12:52:30 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(char *file, t_vars vars)
{
	char	*line;
	int		fd;
	char	**map;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= -1)
		return (NULL);
	map = ft_calloc(vars.win.raw_height + 1, sizeof(char *));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[vars.win.raw_height] = 0;
	close(fd);
	free(line);
	return (map);
}

static void	put_image(char c, t_vars vars, int width, int height)
{
	if (c == 'P')
		mlx_put_image_to_window(vars.mlx, vars.win.win,
			create_image(vars, PLAYER_IMG).img, width, height);
	else if (c == '1')
		mlx_put_image_to_window(vars.mlx, vars.win.win,
			create_image(vars, WALL_IMG).img, width, height);
	else if (c == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win.win,
			create_image(vars, EXIT_IMG).img, width, height);
	else if (c == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win.win,
			create_image(vars, COLLECT_IMG).img, width, height);
	else if (c == '0')
		mlx_put_image_to_window(vars.mlx, vars.win.win,
			create_image(vars, BACKGROUND_IMG).img, width, height);
}

void	create_visual_map(t_vars vars)
{
	int		i;
	int		j;
	int		current_width;
	int		current_height;

	i = 0;
	current_width = 0;
	current_height = 0;
	while (i < vars.win.raw_height)
	{
		j = 0;
		current_width = 0;
		while (j <= vars.win.raw_width)
		{
			put_image(vars.map[i][j], vars, current_width, current_height);
			current_width += MAP_SIZE;
			j++;
		}
		current_height += MAP_SIZE - 1;
		i++;
	}
}
