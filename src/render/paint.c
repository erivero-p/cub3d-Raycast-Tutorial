/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:07 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/11 11:34:42 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_fill_tile(t_game *game, int x, int y, int color)
{
	int	tmp;

	tmp = x;
	while (y < game->scene->mini_y)
	{
		x = tmp;
		while (x < game->scene->mini_x)
		{
			mlx_put_pixel(game->scene->mini, x, y, color);
			x++;
		}
		y++;
	}
}

/*pintamos el minimapa en la ventana, establleiendo previamente las dimensiones
del tile (celda) que va a ocupar en la ventana cada caracter representado.
tal y como yo lo he hecho es: pinto un solo pixel del tile -esquina superior
izquierda para tener como la referencia.
y con esa referencia tenemos que rellenar el tile, que en nuestro caso va a
ser de 15x15. es decir nuestro primer tile es el 0,0 y sus pixeles son 15x15.
por tanto en la funcion ft_fill_tile le paso el valor en coordenadas del mapa
en la que nos encontramos por las dimensiones totales de los tiles, para asi
en un bucle ir pintando tile a tile el minimapa.*/
//mlx_put_pixel(info->scene->mini, x * scene->tile, y * scene->tile, PINK);
//esta linea sobra en verdad solo la tengo de referencia

void	ft_paint_minimap(t_game *info, char **map)
{
	int		x;
	int		y;
	int		color;
	float	tile;

	y = 0;
	tile = info->scene->tile;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				color = BLACK;
			else if (ft_strchr("NSEW0", map[y][x]))
				color = WHITE;
			else
				color = TRANSP;
			ft_fill_tile(info, x * tile, y * tile, color);
			x++;
		}
		y++;
	}
}
/*esta fucntion pinta los pixeles del mapa de iquierda a derecha de arriba
a abajo. pasamos tanto la posicion a pintar del mapa (y, x) por las dimensiones
del tile y establecemos como los maximos las dimensiones totales de mapa por
las dimensiones del tile. rellena celda a celda.
de 0 a 15 -> 15 a 30 -> 30 a 45 ->etc.
el eje horizontal si se va resetando pero el vertical tira palante como las
gatas*/

void	ft_set_minimap(t_game *info, t_scene *scene, int delete)
{
	int	center_x;
	int	center_y;

	if (delete == 1)
		mlx_delete_image(info->mlx, scene->mini);
	info->scene->mini = \
	mlx_new_image(info->mlx, info->scene->mini_x, info->scene->mini_y);
	if (!info->scene->mini)
		ft_error(IMAGE, NULL);
	center_x = 75 + info->player->size - (info->player->pos->x * scene->tile);
	center_y = 75 + info->player->size - (info->player->pos->y * scene->tile);
	if (mlx_image_to_window
		(info->mlx, info->scene->mini, center_x, center_y) < 0)
	{
		ft_error(IMAGE, NULL);
		return ;
	}
	ft_paint_minimap(info, scene->map);
	scene->mini->instances[0].z = 0;
}
//version jugador estatico -> 150 tamaño sin dibujar en canvas; 
// 2 para mitad; - 2.5  mitad del tamaño de la imagen para ajustarlo al centro

void	ft_render_player(t_game *game, t_scene *scene, t_player *player)
{
	t_coord	inital;
	int		y;
	int		x;

	inital = ft_get_player_init_pos(game);
	y = -1;
	player->player_img = mlx_new_image(game->mlx, player->size, player->size);
	if (!player->player_img || mlx_image_to_window
		(game->mlx, player->player_img, (150 / 2) + (player->size / 2), \
		(150 / 2) + (player->size / 2)) < 0)
		ft_error(IMAGE, NULL);
	while (++y < player->size)
	{
		x = -1;
		while (++x < player->size)
			mlx_put_pixel(player->player_img, x, y, RED);
	}
	player->player_img->instances[0].enabled = false;
	if (BONUS == 1)
	{
		player->player_img->instances[0].enabled = true;
		player->player_img->instances[0].z = 2;
	}
}
