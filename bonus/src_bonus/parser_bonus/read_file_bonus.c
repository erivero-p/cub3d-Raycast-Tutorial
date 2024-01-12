/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:17:06 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/12 14:02:29 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

int	ft_len_file(int fd)
{
	char	*line;
	int		len;

	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ft_error(EMPTY, NULL));
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

void	ft_read_file(t_scene *scene, int fd, int len, char *file)
{
	char	*line;
	int		i;

	i = 0;
	scene->file = (char **)ft_calloc(sizeof(char *), len + 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		scene->file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
}

//	ft_print_matrix(scene->file, DEBUG_COLOR);