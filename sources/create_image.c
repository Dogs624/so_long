/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:52:56 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/18 14:51:30 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	create_image(t_vars vars, char *path)
{
	t_img	img;

	img.img = mlx_png_file_to_image(vars.mlx, path, &img.width, &img.height);
	return (img);
}
