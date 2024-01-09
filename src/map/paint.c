/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:07 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/09 16:54:50 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/*con esta función pintamos el cielo y el suelo, habria que cambiar los colores
a los que nos pasan por el mapa. puede que en un futuro, a la hora de hacer un 
resize de la ventana haya que cambiar el WEIGHT y HEIGTH y pasarlos por para-
metro para que pueda redibujarse bien.*/

void	ft_paint_background(t_game *game, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < (h / 2))
	{
		x = 0;
		while (x < w)
		{
			mlx_put_pixel(game->scene->canvas, x, y, game->scene->ceiling); //aqui tendria que ir c_color en hexadecimal
			x++;
		}
		y++;
	}
	while (y < (h))
	{
		x = 0;
		while (x < w)
		{
			mlx_put_pixel(game->scene->canvas, x, y, game->scene->floor);  //aqui tendria que ir f_color en hexadecimal
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
//mlx_put_pixel(info->scene->mini, x * scene->tile, y * scene->tile, PINK); //esta linea sobra en verdad solo la tengo de referencia

void	ft_paint_minimap(t_game *info, t_scene *scene, int delete)
{
	int	color;
	int	x;
	int	y;
	int	center_x;
	int	center_y;

	if (delete == 1)
		mlx_delete_image(info->mlx, scene->mini);
	info->scene->mini = mlx_new_image(info->mlx, info->scene->mini_x, info->scene->mini_y); //limites de la imagen
	if (!info->scene->mini)
		ft_error(IMAGE, NULL);
	center_x = 75 + info->player->size - (info->player->pos->x * scene->tile); //a la mitad del hueco (centro) del minimap le restamos las coordenadas 
	center_y = 75 + info->player->size - (info->player->pos->y * scene->tile);
	if (mlx_image_to_window(info->mlx, info->scene->mini, center_x, center_y) < 0) // en que coordenadas carga la imagen
		ft_error(IMAGE, NULL);
	y = 0;
	while (scene->map[y])
	{
		x = 0;
		while (scene->map[y][x])
		{
			color = ft_get_color(scene->map, y, x);
			ft_fill_tile(info, x * scene->tile, y * scene->tile, color);
			x++;
		}
		y++;
	}
	scene->mini->instances[0].z = 0;
	//scene->mini->enabled = false;
}

int	ft_get_color(char **map, int y, int x)
{
	int	color;

	if (map[y][x] == '1')
		color = BLACK;
	else if (ft_strchr("NSEW0", map[y][x])) 
		color = WHITE;
	else
		color = TRANSP;
	return (color);
}

/*esta fucntion pinta los pixeles del mapa de iquierda a derecha de arriba
a abajo. pasamos tanto la posicion a pintar del mapa (y, x) por las dimensiones
del tile y establecemos como los maximos las dimensiones totales de mapa por
las dimensiones del tile. rellena celda a celda.
de 0 a 15 -> 15 a 30 -> 30 a 45 ->etc.
el eje horizontal si se va resetando pero el vertical tira palante como las
gatas*/

void	ft_fill_tile(t_game *game, int x, int y, int color)
{
	int	tmp;

	tmp = x;
	while (y < game->scene->mini_y)
	{
		x = tmp;
		while (x < game->scene->mini_x) //(game->scene->tile * game->scene->len_y)
		{
			mlx_put_pixel(game->scene->mini, x, y, color);
			x++;
		}
		y++;
	}
}

	//printf("ft_fill_tile: len_y: %i / len_x: %i\n", game->scene->len_y, game->scene->len_x);
	//printf("ft_fill_tile: y: %i / x: %i / scene->tile: %f\n", y, x, game->scene->tile);
	// printf("game->scene->tile * game->scene->len_x: %f\n", game->scene->tile * game->scene->len_x);
	// printf("game->scene->mini_x: %f / game->scene->mini_y: %f\n", game->scene->mini_x, game->scene->mini_y);

/*cambiar de archivo esta funcion -> player.c*/

void	ft_render_player(t_game *game, t_scene *scene, t_player *player)
{
	t_coord	inital;
	int		y;
	int		x;

	inital = ft_get_player_init_pos(game);
	y = 0;
	player->player_img = mlx_new_image(game->mlx, player->size, player->size);
	if (!player->player_img)
		ft_error(IMAGE, NULL);
	// if (mlx_image_to_window(game->mlx, player->player_img, (inital.x * scene->tile) + 30, (inital.y * scene->tile) + 30) < 0) //antigua ver
	// 	ft_error(IMAGE, NULL);
	if (mlx_image_to_window(game->mlx, player->player_img, (150 / 2) /* + 2.5 */, (150 / 2)/*  + 2.5 */) < 0) //version jugador estatico -> 150 tamaño sin dibujar en canvas; / 2 para mitad; - 2.5 el la mitad del tamaño de la imagen para ajustarlo al centro 
		ft_error(IMAGE, NULL);
	//printf("ft_render_player: player.size: %d\n", player->size); //comment
	while (y < player->size)
	{
		x = 0;
		while (x < player->size)
		{
			mlx_put_pixel(player->player_img, x, y, RED);
			x++;
		}
		y++;
	}
	player->player_img->instances[0].enabled = false;
	if (BONUS == 1)
	{
		player->player_img->instances[0].enabled = true;
		player->player_img->instances[0].z = 2;
	}
}

/*void draw_line(t_img *img, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_put_pixel(img, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_diagonal_square(t_img *img, int size, int color) {
    int half_size = size / 2;
    draw_line(img, 0, 0, half_size, half_size, color);  // Top-left to center
    draw_line(img, size - 1, 0, half_size, half_size, color);  // Top-right to center
    draw_line(img, 0, size - 1, half_size, half_size, color);  // Bottom-left to center
    draw_line(img, size - 1, size - 1, half_size, half_size, color);  // Bottom-right to center
}

// Usage:
draw_diagonal_square(player->player_img, player->size, RED);*/