/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/05 13:24:05 by marirodr         ###   ########.fr       */
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
	info->scene->tile = 15.0f; //de tile para minimap
	info->scene->mini_y = info->scene->len_y * info->scene->tile;  //anchura total minimapa con tiles de 15
	info->scene->mini_x = info->scene->len_x * info->scene->tile;  //altura total minimap con tiles de 15; le restamos la longuitud de un tile para que no saque la ultima columnta (por la mierda de siempre de que los arrays empeizan en 0)

	printf("%sft_init_map: tile: %f\n", GOOD, info->scene->tile);
	printf("ft_init_map: len_y: %i\n", info->scene->len_y);
	printf("ft_init_map: len_x: %i%s\n", info->scene->len_x, END);
	ft_paint_background(info, HEIGHT, WIDTH);
	ft_mini_background(info);
	ft_paint_minimap(info, info->scene);
	//no sé exactamente cómo pero tenemos que borrar el background y volver a pintarlo (todas la imagenes en general), cada vez que se haga un resize
		//pruebas
	info->test = mlx_new_image(info->mlx, 15, 15);
	if (!info->test)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(info->mlx, info->test, 60 + 30, 150 + 30) == -1)
		ft_error(IMAGE, NULL);
	//ft_fill_tile(info, 0, 0, RED, info->test);
	t_coord inital = ft_get_player_pos(info);
	printf("ft_init_map: inital.y: %i / inital.x: %i\n", inital.y, inital.x);
	printf("ft_init_map: inital.y + 15: %i / inital.x + 15: %i\n", inital.y * 15, inital.x * 15);
	int y = 0;
	int x;
	while (y < 15)
	{
		x = 0;
		while (x < 15) //(info->scene->tile * info->scene->len_y)
		{
			mlx_put_pixel(info->test, x, y, RED);
			x++;
		}
		y++;
	}
}
	//ft_fill_tile(info, 0, 0, RED, info->test);
	// t_coord inital = ft_get_player_pos(info);
	// printf("ft_init_map: inital.y: %i / inital.x: %i\n", inital.y, inital.x);
	// printf("ft_init_map: inital.y + 15: %i / inital.x + 15: %i\n", inital.y + 15, inital.x + 15);
	// int tmp = inital.x;
	// while (inital.y < (inital.y + 15))
	// {
	// 	inital.x = tmp;
	// 	while (inital.x < (inital.x + 15)) //(info->scene->tile * info->scene->len_y)
	// 	{
	// 		mlx_put_pixel(info->test, inital.x, inital.y, RED);
	// 		inital.x++;
	// 	}
	// 	inital.y++;
	// }
	//mierdas de debugeo
	// printf("ft_init_map: mini_y: %f\n", info->scene->mini_y);
	// printf("ft_init_map: mini_x: %f\n", info->scene->mini_x);