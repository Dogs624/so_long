/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:41:17 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/08 07:43:01 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, char const *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		begin_count;
	int		end_count;

	if (s1 == NULL || set == NULL)
		return (NULL);
	begin_count = 0;
	end_count = ft_strlen(s1) - 1;
	while (s1[begin_count] && ft_isset(s1[begin_count], set))
		begin_count++;
	while (s1[end_count] && end_count > begin_count
		&& ft_isset(s1[end_count], set))
		end_count--;
	new_str = ft_substr(s1, begin_count, end_count - begin_count + 1);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}
