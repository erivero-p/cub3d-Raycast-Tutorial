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

void	ft_paint_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < (HEIGHT / 2))
	{
		y = 0;
		while (y < WIDTH)
		{
			mlx_put_pixel(game->canvas, y, x, BLUE); //aqui tendria que ir c_color en hexadecimal
			y++;
		}
		x++;
	}
	while (x < (HEIGHT))
	{
		y = 0;
		while (y < WIDTH)
		{
			mlx_put_pixel(game->canvas, y, x, PINK);  //aqui tendria que ir f_color en hexadecimal
			y++;
		}
		x++;
	}
}

int	ft_get_color(char **map, int x, int y)
{
	int	color;

	if (map[x][y] == '1')
		color = BLACK;
	else if (map[x][y] == '0')
		color = WHITE;
	else if (ft_strchr("NSEW", map[x][y])) //esto lo voy a tener que rendear despues del mapa y aparte
		color = RED;
	else
		color = GREEN; //este color es de pruebas en verdad no cuenta, mas bien que solo hace falta si no pintamos un background al minimapa
	return (color);
}

// void	ft_draw_tile(mlx_image_t *canvas, int x, int y, int color, int width, int height)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			mlx_put_pixel(canvas, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	ft_mini_background(t_game *game)
{
	int	x;
	int	y;

	game->scene->mini = mlx_new_image(game->mlx, game->scene->mini_x, game->scene->mini_y); //limites de la imagen
	if (!game->scene->mini)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(game->mlx, game->scene->mini, 30, 30) < 0) // en que coordenadas carga la imagen
		ft_error(IMAGE, NULL);
	y = 0;
	while (y < game->scene->mini_y)
	{
		x = 0;
		while (x < game->scene->mini_x)
		{
			mlx_put_pixel(game->scene->mini, x, y, WHITE); //x e y no se pueden pasar de los limites estableidos para la imagen
			x++;
		}
		y++;
	}
}
void	ft_fill_tile(t_game *game, int y, int x, int color)
{
	int	tmp;

	tmp = y;
	//printf("ft_fill_tile: len_x: %i / len_y: %i\n", game->scene->len_x, game->scene->len_y);
	//printf("ft_fill_tile: x: %i / aux: %i / y: %i / auz: %i / scene->tile: %f\n", x, aux, y, auy, game->scene->tile);
	while (x < (game->scene->tile * game->scene->len_y))
	{
		//printf("ft_fill_tile: x: %i / y: %i / scene->tile: %f\n", x, y, game->scene->tile);
		y = tmp;
		while (y < (game->scene->tile * game->scene->len_x))
		{
			mlx_put_pixel(game->scene->mini, y, x, color);
			y++;
		}
		x++;
	}
}

void	ft_paint_minimap(t_game *info, t_scene *scene)
{
	int	color;
	int	y;
	int	x;

	x = 0;
	while (scene->map[x])
	{
		y = 0;
		while (scene->map[x][y])
		{
			color = ft_get_color(scene->map, x, y);
			int t = y * scene->tile;
			int z = x * scene->tile;
			//ft_printf("en ft_paint_minimap: t: %i / z: %i\n", t, z);
			mlx_put_pixel(info->scene->mini, y * scene->tile, x * scene->tile, color);
			ft_fill_tile(info, t, z, color);
			y++;
		}
		x++;
	}
}

void	ft_init_map(t_game *info)
{
//	info->scene->len_y = ft_arrlen(info->scene->map);
//	info->scene->len_x = ft_get_map_x(info);
	info->scene->tile = 15.0f; //de tile para minimap
	info->scene->mini_y = info->scene->len_y * info->scene->tile;  //anchura total minimapa con tiles de 15
	info->scene->mini_x = info->scene->len_x * info->scene->tile;  //altura total minimap con tiles de 15
	// printf("%sft_init_map: tile: %f\n", GOOD, info->scene->tile);
	// printf("ft_init_map: len_y: %i\n", info->scene->len_y);
	// printf("ft_init_map: len_x: %i%s\n", info->scene->len_x, END);
	// printf("ft_init_map: mini_y: %f\n", info->scene->mini_y);
	// printf("ft_init_map: mini_x: %f\n", info->scene->mini_x);
	ft_paint_background(info);
	ft_mini_background(info);
	ft_paint_minimap(info, info->scene);
	//no sé exactamente cómo pero tenemos que borrar el background y volver a pintarlo (todas la imagenes en general), cada vez que se haga un resize
}
