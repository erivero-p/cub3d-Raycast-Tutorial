/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:31:35 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/12 14:02:29 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

int	ft_is_wall(char **map, int x, int y, t_scene *scene)
{
	if (y == 0 && map[y][x] > 32)
		return (1);
	if (y == scene->len_y - 1 && map[y][x] > 32)
		return (1);
	if (x == 0 && map[y][x] > 32)
		return (1);
	if (x == scene->len_x - 1 && map[y][x] > 32)
		return (1);
	if (y > 0 && map[y - 1][x] <= 32)
		return (1);
	if (y < scene->len_y - 1 && map[y + 1][x] <= 32)
		return (1);
	if (x > 0 && map[y][x - 1] <= 32)
		return (1);
	if (x < scene->len_x - 1 && map[y][x + 1] <= 32)
		return (1);
	return (0);
}

int	ft_wall_check(char **map, t_scene *scene)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] && y < scene->len_y)
	{
		x = 0;
		while (map[y][x] && x < scene->len_x)
		{
			while (map[y][x] > 0 && map[y][x] <= 32)
				x++;
			if (map[y][x] != 0 && ft_is_wall(map, x, y, scene) \
			&& map[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	return (1);
}

/*	Condiciones de ft_is_wall:
	if (y == 0 && map[y][x] > 32)
	si estoy arriba y hay algo
	if (y == scene->len_y - 1 && map[y][x] > 32)
	si estoy abajo y hay algo
	if (x == 0 && map[y][x] > 32)
	si estoy a la izquierda y hay algo
	if (x == scene->len_x - 1 && map[y][x] > 32)
	si estoy a la derecha y hay algo
	if (y > 0 && map[y - 1][x] <= 32)
	si arriba hay un espacio
	if (y < scene->len_y - 1 && map[y + 1][x] <= 32)
	si abajo hay un espacio
	if (x > 0 && map[y][x - 1] <= 32)
	si a la izquierda hay un espacio
	if (x < scene->len_x - 1 && map[y][x + 1] <= 32)
	si a la derecha hay un espacio */