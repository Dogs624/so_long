/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:46:12 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/18 14:48:08 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_gnl(char *buffer, char *buff_rem)
{
	if (buffer)
		free(buffer);
	if (buff_rem)
		free(buff_rem);
	return (NULL);
}

static char	*ft_cut(char **buf_rem, char *buffer)
{
	char	*to_ret;
	char	*tmp;

	if (ft_strchr_gnl(*buf_rem, '\n') > -1)
	{
		to_ret = ft_substr_gnl(*buf_rem, 0, ft_strchr_gnl(*buf_rem, '\n') + 1);
		if (!to_ret)
			return (ft_free_gnl(buffer, *buf_rem));
		tmp = *buf_rem;
		*buf_rem = ft_substr_gnl(tmp, ft_strchr_gnl(tmp, '\n') + 1,
				ft_strlen_gnl(tmp) - ft_strchr_gnl(tmp, '\n') + 1);
		free(tmp);
		if (!(*buf_rem))
		{
			free(to_ret);
			return (ft_free_gnl(buffer, *buf_rem));
		}
	}
	else
	{
		to_ret = *buf_rem;
		*buf_rem = NULL;
	}
	free(buffer);
	return (to_ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buff_rem;
	int			ret_read;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (ft_free_gnl(buffer, buff_rem));
	ret_read = 1;
	while (ret_read > 0 && ft_strchr_gnl(buff_rem, '\n') == -1)
	{
		ret_read = read(fd, buffer, BUFFER_SIZE);
		if (ret_read == -1)
			return (ft_free_gnl(buffer, buff_rem));
		buffer[ret_read] = '\0';
		if (ret_read)
			buff_rem = ft_strjoin_gnl(buff_rem, buffer);
		if (!buff_rem)
			return (ft_free_gnl(buffer, buff_rem));
	}
	if (buff_rem == NULL || buff_rem[0] == '\0')
		return (ft_free_gnl(buffer, buff_rem));
	return (ft_cut(&buff_rem, buffer));
}
