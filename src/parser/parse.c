/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/11 10:13:40 by erivero-         ###   ########.fr       */
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
	scene->night = NULL;
	scene->len_x = -1;
	scene->len_y = -1;
}

int	ft_parse(t_scene *scene, int fd, char *file, t_img *img)
{
	int	len;

	ft_init_scene(scene);
	len = ft_len_file(fd);
	if (len <= 0)
		return (-1);
	ft_read_file(scene, fd, len, file);
	if (ft_parse_file(scene) == -1)
		return (ft_free_double_pointer(scene->file), -1);
	if (ft_scene_check(scene) == -1)
		return (ft_free_double_pointer(scene->file), -1);
	if (ft_load_images(scene, img) == -1)
		return (ft_free_double_pointer(scene->file), -1);
	return (ft_free_double_pointer(scene->file), 0);
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
