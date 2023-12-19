/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/18 11:32:28 by marirodr         ###   ########.fr       */
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

/* 	printf("%sft_init_map: tile: %f\n", GOOD, info->scene->tile);
	printf("ft_init_map: len_y: %i\n", info->scene->len_y);
	printf("ft_init_map: len_x: %i%s\n", info->scene->len_x, END);
	info->scene->canvas = mlx_new_image(info->mlx, 2560, 1440); //para poder rendear las imagenes, cómo crear un lienzp donde poder dibujar pixeles
	if (!info->scene->canvas)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(info->mlx, info->scene->canvas, 0, 0) == -1)
		ft_error(IMAGE, NULL);
	ft_paint_background(info, HEIGHT, WIDTH);
	ft_paint_minimap(info, info->scene);
	//no sé exactamente cómo pero tenemos que borrar el background y volver a pintarlo (todas la imagenes en general), cada vez que se haga un resize
}
