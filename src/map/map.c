/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 12:50:14 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_get_map_x(t_game *info)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (info->map->map[i])
	{
		if (ft_strlen(info->map->map[i]) > max)
			max = ft_strlen(info->map->map[i]);
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
	while (info->map->map[i])
	{
		j = 0;
		while (info->map->map[i][j])
		{
			if (info->map->map[i][j] == '1')
			{
				color = BLACK;
			}
			else if (info->map->map[i][j] == '0')
				color = WHITE;
			else if (ft_strchr("NSEW", info->map->map[i][j]))
				color = PINK;
			else if (ft_strchr(" \t", info->map->map[i][j]))
				color = BLUE;
			info->map->img = mlx_new_image(info->mlx, 200, 200);
			if (!info->map->img)
				ft_error(IMAGE, NULL);
			if (mlx_image_to_window(info->mlx, info->map->img, i, j) < 0)
				ft_error(IMAGE, NULL);
			mlx_put_pixel(info->map->img, i, j, color);
		}
		i++;
	}
}

void	ft_paint_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (HEIGHT / 2))
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(game->canvas, j, i, BLUE);
			j++;
		}
		i++;
	}
	while (i < (HEIGHT))
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(game->canvas, j, i, PINK);
			j++;
		}
		i++;
	}
}

void	ft_init_map(t_game *info)
{
	info->map->len_y = ft_arrlen(info->map->map);
	//ft_printf("%sla y/altura del map es: %i%s\n", BLUE, info->map->len_y, END);
	info->map->len_x = ft_get_map_x(info);
	info->map->limit = 30; //why?
	info->map->w = info->map->len_y * info->map->limit;  //why?
	info->map->h = info->map->len_x * info->map->limit;  //why?
	//ft_printf("%sla x/longuitud del map es: %i%s\n", BLUE, info->map->len_x, END);
	//ft_paint_minimap(info);
	ft_paint_background(info);
}
