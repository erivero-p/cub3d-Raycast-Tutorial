/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 11:43:07 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_len_file(int fd)
{
	char	*line;
	int		len;

	len = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error(EMPTY, NULL);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

void	ft_read_file(t_game *info, int fd, int len, char *file)
{
	char	*line;
	int		i;

	i = 0;
	info->scene->file = (char **)ft_calloc(sizeof(char *), len + 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		info->scene->file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
}

int	ft_parse(t_game *info, int fd, char *file)
{
	int	len;

	ft_init_scene_struct(info);
	len = ft_len_file(fd);
	if (len <= 0)
		return (-1);
	ft_read_file(info, fd, len, file);
	if (ft_parse_file(info->scene) == -1)
		return (ft_free_double_pointer(info->scene->file), -1); //tb podemos liberar **file al final junto con lo demás y ea
	return (ft_free_double_pointer(info->scene->file), 0);
}
//	ft_print_matrix(info->scene->file, 1);
//	ft_print_matrix(info->scene->map, 2);

int	ft_arg_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_error(ARG, NULL));
	if (ft_check_ext(av[1], ".cub") == -1)
		return (ft_error(EXT_CUB, NULL));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(FD, NULL));
	return (fd);
}
