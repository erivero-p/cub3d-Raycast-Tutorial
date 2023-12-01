/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/01 12:35:52 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_init_scene(t_scene *scene)
{
	scene->no_path = NULL;
	scene->so_path = NULL;
	scene->we_path = NULL;
	scene->ea_path = NULL;
	scene->f_color = NULL;
	scene->c_color = NULL;
	scene->file = NULL;
	scene->map = NULL;
	scene->aux_map = NULL;
	scene->len_x = -1;
	scene->len_y = -1;
/* 	scene->limit = -1;
	scene->w = -1;
	scene->h = -1; */
}

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
//		scene->file[i] = ft_strtrim(line, "\n");
//		ft_printf("ft_read_file saved: \'%s\'\n", scene->file[i]);
		scene->file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
//	ft_print_matrix(scene->file, DEBUG_COLOR);
	free(line);
}

int	ft_parse(t_scene *scene, int fd, char *file)
{
	int	len;

	ft_init_scene(scene);
	len = ft_len_file(fd);
	if (len <= 0)
		return (-1);
	ft_read_file(scene, fd, len, file);
	if (ft_parse_file(scene) == -1)
		return (ft_free_double_pointer(scene->file), -1); //tb podemos liberar **file al final junto con lo demás y ea
	if (ft_scene_check(scene) == -1)
		return (ft_free_double_pointer(scene->file), -1);
	return (ft_free_double_pointer(scene->file), 0);
}
//	ft_print_matrix(scene->file, 1);
//	ft_print_matrix(scene->map, 2);

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
