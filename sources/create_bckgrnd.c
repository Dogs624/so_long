/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bckgrnd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:37:44 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/18 14:49:31 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_bckgrnd(t_vars vars)
{
	t_img	img;
	int		current_height;
	int		current_width;

	current_height = 0;
	img = create_image(vars, BACKGROUND_IMG);
	while (current_height < vars.win.height)
	{
		current_width = 0;
		while (current_width < vars.win.width)
		{
			mlx_put_image_to_window(vars.mlx, vars.win.win, img.img,
				current_width, current_height);
			current_width += img.width - 1;
		}
		current_height += img.height - 1;
	}
}
