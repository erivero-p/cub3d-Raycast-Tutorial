/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/27 18:48:33 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

		// while (line[0] == '\n')
		// {
		// 	free(line);
		// 	line = get_next_line(fd);
		// }

int	ft_len_file(int fd)
{
	char	*line;
	int	len;

	line = get_next_line(fd);
	if (!line)
		ft_error(EMPTY, NULL);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	printf("lineas del archivo: %i\n", len);
	close(fd);
	return (len);
}

t_map *ft_read_file(t_game *info, int fd, int len, char *file)
{
	char *line;
	int	i;

	i = 0;
	info->map->file = malloc(sizeof(char *) * len + 1);
	fd = open(file, O_RDONLY);
		line = get_next_line(fd);
	while (line)
	{
		// while (line[0] == '\n')
		// {
		// 	free(line);
		// 	line = get_next_line(fd);
		// }
		info->map->file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	return (info->map);
}

void	ft_parse(t_game *info, int fd, char *file)
{
	int	len;

	info->map = ft_init_map_struct(info);
	len = ft_len_file(fd);
	info->map = ft_read_file(info, fd, len, file);
	ft_parse_file(info->map);
	//ft_print_matrix(info->map->file);
	//ft_print_map(info->map);
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
