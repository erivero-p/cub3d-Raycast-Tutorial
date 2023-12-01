/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:07 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/01 14:15:38 by marirodr         ###   ########.fr       */
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
			mlx_put_pixel(game->canvas, x, y, BLUE); //aqui tendria que ir c_color en hexadecimal
			x++;
		}
		y++;
	}
	while (y < (h))
	{
		x = 0;
		while (x < w)
		{
			mlx_put_pixel(game->canvas, x, y, PINK);  //aqui tendria que ir f_color en hexadecimal
			x++;
		}
		y++;
	}
}

/*pintamos el "canvas" del minimapa. no se si esto en verdad esta funcion en
verdad puedo fusionarla con ft_paint_minimap()?*/

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
			mlx_put_pixel(game->scene->mini, x, y, WHITE); //x e y no se pueden pasar de los limites establecidos para la imagen
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

			// int t = y * scene->tile;
			// int z = x * scene->tile;

void	ft_paint_minimap(t_game *info, t_scene *scene)
{
	int	color;
	int	x;
	int	y;

	y = 0;
	while (scene->map[y])
	{
		x = 0;
		while (scene->map[y][x])
		{
			color = ft_get_color(scene->map, y, x);
			ft_fill_tile(info, x * scene->tile, y * scene->tile, color);
			//mlx_put_pixel(info->scene->mini, x * scene->tile, y * scene->tile, PINK); //esta linea sobra en verdad solo la tengo de referencia
			x++;
		}
		y++;
	}
	// ----ESTE BLOQUE DE CODIGO ES PARA SACAR LA ULTIMA LINEA LIMPIA
	// ---PONER ESTO MAS COOERENTE -> 1 BUCLE: h -> 2 BUCLE: w
	// printf("en ft_paint_minimap: y * scene->tile: %f / x * scene->tile: %f\n", y * scene->tile, x * scene->tile);
	// int w = (x * scene->tile) - 1;
	// int h = (y * scene->tile) - 1 - scene->tile;
	// int tmp = (y * scene->tile) - 1 - scene->tile;
	// printf("en ft_paint_minimap: w: %i / h: %d / mini_y: %f / mini_x: %f\n", w, h, scene->mini_y, scene->mini_x);
	// while (++w < scene->mini_x)
	// {
	// 	h = tmp;
	// 	while (++h < scene->mini_y)
	// 		mlx_put_pixel(info->scene->mini, w, h, PINK); //el color esta mal puesto a proposito para acordarme que este bloque de codigo puede dar problemas
	// }
}

int	ft_get_color(char **map, int y, int x)
{
	int	color;

	if (map[y][x] == '1')
		color = BLACK;
	else if (map[y][x] == '0')
	color = WHITE;
	else if (ft_strchr("NSEW", map[y][x])) //esto probablemente lo voy a tener que rendear despues del mapa y aparte?? o no porque son pixeles???
		color = RED;
	else
		color = GREEN; //este color es de pruebas en verdad no cuenta, mas bien que solo hace falta si no pintamos un background al minimapa
	return (color);
}

/*esta fucntion pinta los pixeles del mapa de iquierda a derecha de arriba
a abajo. pasamos tanto la posicion a pintar del mapa (y, x) por las dimensiones
del tile y establecemos como los maximos las dimensiones totales de mapa por
las dimensiones del tile. rellena celda a celda.
de 0 a 15 -> 15 a 30 -> 30 a 45 ->etc.
el eje horizontal si se va resetando pero el vertical tira palante como las gatas*/

void	ft_fill_tile(t_game *game, int x, int y, int color)
{
	int	tmp;

	tmp = x;
	//printf("ft_fill_tile: len_y: %i / len_x: %i\n", game->scene->len_y, game->scene->len_x);
	//printf("ft_fill_tile: y: %i / x: %i / scene->tile: %f\n", y, x, game->scene->tile);
	// printf("game->scene->tile * game->scene->len_x: %f\n", game->scene->tile * game->scene->len_x);
	// printf("game->scene->mini_x: %f / game->scene->mini_y: %f\n", game->scene->mini_x, game->scene->mini_y);
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
