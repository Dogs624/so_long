/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:05:48 by jvander-          #+#    #+#             */
/*   Updated: 2021/10/20 13:56:39 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sources/so_long.h"

static int	check_extension_file(char *file)
{
	char	*extension;

	extension = ft_substr(file, ft_strlen(file) - ft_strlen(EXTENSION_FILE),
			ft_strlen(EXTENSION_FILE));
	if (ft_strncmp(extension, EXTENSION_FILE, ft_strlen(extension)) != 0)
	{
		printf("Error\nThe file hasn't the .ber extension\n");
		free(extension);
		return (0);
	}
	free(extension);
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	fd;

	fd = -1;
	if (argc != 2)
	{
		printf("Error\nThere isn't good number of arguments\n");
		return (0);
	}
	if (!check_extension_file(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 1)
	{
		printf("Error\nCan't open the file\n");
		return (0);
	}
	close(fd);
	return (1);
}
