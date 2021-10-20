/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:25:36 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/05 09:09:09 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*char_dst;
	const char	*char_src;
	size_t		i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	char_dst = (char *)dst;
	char_src = (char *) src;
	while (i < n)
	{
		char_dst[i] = char_src[i];
		if ((unsigned char) c == (unsigned char) char_src[i])
			return (&dst[++i]);
		i++;
	}
	return (NULL);
}
