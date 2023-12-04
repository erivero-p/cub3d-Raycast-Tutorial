/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/01 15:35:50 by erivero-         ###   ########.fr       */
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
//	info->scene->len_y = ft_arrlen(info->scene->map);
//	info->scene->len_x = ft_get_map_x(info);
	info->scene->tile = 15.0f; //de tile para minimap
	info->scene->mini_y = info->scene->len_y * info->scene->tile;  //anchura total minimapa con tiles de 15
	info->scene->mini_x = (info->scene->len_x - 1) * info->scene->tile;  //altura total minimap con tiles de 15; le restamos la longuitud de un tile para que no saque la ultima columnta (por la mierda de siempre de que los arrays empeizan en 0)

	// printf("%sft_init_map: tile: %f\n", GOOD, info->scene->tile);
	// printf("ft_init_map: len_y: %i\n", info->scene->len_y);
	// printf("ft_init_map: len_x: %i%s\n", info->scene->len_x, END);
	// printf("ft_init_map: mini_y: %f\n", info->scene->mini_y);
	// printf("ft_init_map: mini_x: %f\n", info->scene->mini_x);
	ft_paint_background(info, HEIGHT, WIDTH);
	ft_mini_background(info);
	ft_paint_minimap(info, info->scene);
	//no sé exactamente cómo pero tenemos que borrar el background y volver a pintarlo (todas la imagenes en general), cada vez que se haga un resize
}

	// printf("en ft_paint_minimap: y * scene->tile: %f / x * scene->tile: %f\n", y * scene->tile, x * scene->tile);
	// int t = (y * scene->tile) - 1;
	// int u = (x * scene->tile) - 16;
	// printf("en ft_paint_minimap: t: %i / u: %d / mini_y: %f / mini_x: %f\n", t, u, scene->mini_y, scene->mini_x);
	// while (++t < scene->mini_y)
	// {
	// 	u = 194;
	// 	while (++u < scene->mini_x)
	// 		mlx_put_pixel(info->scene->mini, t, u, PINK); //esta linea sobra en verdad solo la tengo de referencia
	// }