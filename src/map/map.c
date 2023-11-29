/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 12:25:45 by erivero-         ###   ########.fr       */
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

void	ft_paint_minimap(void *param)
{
	int	color;
	int	i;
	int	j;
	t_game *info;

	info = (t_game *)param;
	i = 0;
	while (info->scene->map[i])
	{
		j = 0;
		while (info->scene->map[i][j])
		{
			if (info->scene->map[i][j] == '1')
			{
				color = BLACK;
			}
			else if (info->scene->map[i][j] == '0')
				color = WHITE;
			else if (ft_strchr("NSEW", info->scene->map[i][j]))
				color = PINK;
			else if (ft_strchr(" \t", info->scene->map[i][j]))
				color = BLUE;
			info->scene->img = mlx_new_image(info->mlx, 200, 200);
			if (!info->scene->img)
				ft_error(IMAGE, NULL);
			if (mlx_image_to_window(info->mlx, info->scene->img, i, j) < 0)
				ft_error(IMAGE, NULL);
			mlx_put_pixel(info->scene->img, i, j, color);
		}
		i++;
	}
}

void	ft_init_map(t_game *info)
{
	info->scene->len_y = ft_arrlen(info->scene->map);
	//ft_printf("%sla y/altura del map es: %i%s\n", BLUE, info->scene->len_y, END);
	info->scene->len_x = ft_get_map_x(info);
	//ft_printf("%sla x/longuitud del map es: %i%s\n", BLUE, info->scene->len_x, END);
	//ft_paint_minimap(info);
}
