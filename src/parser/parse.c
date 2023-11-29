/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/28 19:01:51 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_len_file(int fd)
{
	char	*line;
	int		len;

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
	info->map->file = (char **)ft_calloc(sizeof(char *), len + 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		info->map->file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
}

void	ft_parse(t_game *info, int fd, char *file)
{
	int	len;

	ft_init_map_struct(info);
	len = ft_len_file(fd);
	ft_read_file(info, fd, len, file);
//	ft_print_matrix(info->map->file, 1);
	ft_parse_file(info);
//	ft_print_matrix(info->map->map, 2);
	ft_free_double_pointer(info->map->file);
}

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
