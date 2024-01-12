/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:28:46 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/12 14:02:29 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

int	ft_check_ext(char *str, char *ext)
{
	int		i;
	char	*tmp;

	if (ft_strchr(str, '.') != 0)
	{
		i = ft_strlen(str);
		while (str[i] != '.')
			i--;
		tmp = &str[i];
		if (!ft_strncmp(tmp, ext, 4))
			return (0);
	}
	return (-1);
}

static int	ft_texture_check(t_scene *scene)
{
	if (ft_check_ext(scene->no_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->so_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->we_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->ea_path, ".png") == -1)
		return (-1);
	return (0);
}

int	ft_scene_check(t_scene *scene)
{
	if (ft_texture_check(scene) == -1)
		return (ft_error(EXT_PNG, NULL));
	scene->floor = ft_color_check(scene->f_color);
	scene->ceiling = ft_color_check(scene->c_color);
	if (scene->floor == -1 || scene->ceiling == -1)
		return (ft_error(COLOR, NULL));
	if (ft_char_mapcheck(scene->map) == -1)
		return (-1);
	if (ft_wall_check(scene->map, scene) == -1)
		return (ft_error(WALL, NULL));
	return (0);
}
