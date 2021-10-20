/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:43:35 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 11:40:37 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

int	error_handling(t_vars vars)
{
	if (!check_size_window(vars))
		return (0);
	if (!check_rectangle(vars))
		return (0);
	if (!surrounded_wall(vars))
		return (0);
	if (!check_contain(vars))
		return (0);
	return (1);
}
