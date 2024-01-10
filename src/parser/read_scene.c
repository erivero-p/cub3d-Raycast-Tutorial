/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:18:10 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/10 11:27:51 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

char	*ft_cpy_info(char *line, char *path)
{
	while (*line > 0 && *line < 33)
		line++;
	if (path != NULL)
		free(path);
	while (*line && *line > 32)
		line++;
	return (ft_strtrim(line, "\n 	"));
}
/* 	while (*line > 0 && *line < 33)
		line++; */

int	ft_save_info(t_scene *scene, char *line)
{
	static int	count = 0;
	char		*tmp;

	tmp = ft_strtrim(line, "   	");
	if (!ft_strncmp(tmp, "NO ", 3) || !ft_strncmp(tmp, "NO	", 3))
		scene->no_path = ft_cpy_info(line, scene->no_path);
	else if (!ft_strncmp(tmp, "SO ", 3) || !ft_strncmp(tmp, "SO	", 3))
		scene->so_path = ft_cpy_info(line, scene->so_path);
	else if (!ft_strncmp(tmp, "WE ", 3) || !ft_strncmp(tmp, "WE	", 3))
		scene->we_path = ft_cpy_info(line, scene->we_path);
	else if (!ft_strncmp(tmp, "EA ", 3) || !ft_strncmp(tmp, "EA	", 3))
		scene->ea_path = ft_cpy_info(line, scene->ea_path);
	else if (!ft_strncmp(tmp, "F ", 2) || !ft_strncmp(tmp, "F	", 3))
		scene->f_color = ft_cpy_info(line, scene->f_color);
	else if (!ft_strncmp(tmp, "C ", 2) || !ft_strncmp(tmp, "C	", 3))
		scene->c_color = ft_cpy_info(line, scene->c_color);
	else
		return (free(tmp), 1);
	count++;
	if (count > 6)
		return (free(tmp),
			ft_error(FORMAT, "Each parameter can't appear more than once"));
	return (free(tmp), 0);
}

int	ft_get_max_len(char **matrix, int j)
{
	int	max;
	int	len;

	max = 0;
	len = 0;
	while (matrix[j])
	{
		len = ft_strlen(matrix[j]);
		if (len > max && matrix[j][len - 1] == 10)
			max = len - 1;
		else if (len > max)
			max = len;
		j++;
	}
	return (max);
}

int	ft_get_map(char **file, t_scene *scene, int j)
{
	int		len;
	char	**cpy;

	if (!(scene->no_path && scene->so_path && scene->we_path
			&& scene->ea_path && scene->f_color && scene->c_color))
		return (ft_error(FORMAT, "All six parameter must be above the map"));
	len = 0;
	while (file[j + len])
		len++;
	scene->len_y = len;
	scene->len_x = ft_get_max_len(file, j);
	scene->map = ft_get_spaced_map(file, j, len, scene->len_x);
	return (0);
}

int	ft_parse_file(t_scene *scene)
{
	int	j;
	int	i;
	int	ret;

	j = -1;
	ret = 0;
	while (scene->file[j] && scene->file[++j])
	{
		i = 0;
		while (scene->file[j][0] == 10)
			j++;
		ret = ft_save_info(scene, scene->file[j]);
		if (ret == 1)
			break ;
		if (ret == -1)
		{
			exit(0); //este exit puede estar enmascarando leaks. Pdte quitar y comprobar en 42
			return (-1);
		}
	}
	ret = ft_get_map(scene->file, scene, j);
	return (ret);
}
