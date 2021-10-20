/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:46:09 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/18 14:46:10 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(const char *s, int c)
{
	char	*char_s;
	char	char_c;
	int		i;

	i = 0;
	if (s == NULL)
		return (-1);
	char_c = (char) c;
	char_s = (char *) s;
	while (char_s[i])
	{
		if (char_s[i] == char_c)
			return (i);
		i++;
	}
	if (c == '\0' && char_s[i] == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	count;
	char	*new_str;

	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	count = 0;
	new_str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[count])
	{
		new_str[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count])
	{
		new_str[count + ft_strlen_gnl(s1)] = s2[count];
		count++;
	}
	new_str[count + ft_strlen_gnl(s1)] = '\0';
	free((char *) s1);
	return (new_str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	size;

	i = 0;
	if (ft_strlen_gnl(s) < start)
	{
		sub_str = ft_calloc(1, sizeof(char));
		if (sub_str == NULL)
			return (NULL);
		return (sub_str);
	}
	size = len;
	if (ft_strlen_gnl(s) < len)
		size = ft_strlen_gnl(s);
	sub_str = ft_calloc(size + 1, sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	while (s[start] && i < len)
		sub_str[i++] = s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (*(str + count))
		count++;
	return (count);
}
