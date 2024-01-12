/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/12 14:00:37 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_get_map_x(t_game *info)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (info->scene->map[i])
	{
		if (ft_strlen(info->scene->map[i]) > max)
			max = ft_strlen(info->scene->map[i]);
		i++;
	}
	return (max);
}

void	ft_init_map(t_game *info)
{
	info->scene->tile = 10.0;
	info->scene->mini_y = info->scene->len_y * info->scene->tile;
	info->scene->mini_x = info->scene->len_x * info->scene->tile;
	info->scene->canvas = mlx_new_image(info->mlx, 2560, 1440);
	if (!info->scene->canvas)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(info->mlx, info->scene->canvas, 0, 0) < 0)
		ft_error(IMAGE, NULL);
}
