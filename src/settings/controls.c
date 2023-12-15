/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/15 13:07:30 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/*checkear en todas las funciones si estoy pasando grados o radianes
debo usar player->angle directamente o usar variables temporales*/

void	ft_ws(t_player *player, double dir, t_game *game)
{
	// double res = (dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed);
	// printf("ft_ws: esta mierda que res : %f\n", res);
	// printf("ft_ws: esta mierda player->angle : %f\n", player->angle);
	// if (dir == 1.0)
	// 	printf("ESTOY PULSANDO S\n");
	// else if (dir == -1.0)
	// 	printf("ESTOY PULSANDO W\n");
	printf("instace.x: %d\n", player->player_img->instances[0].x);
	printf("instace.y: %d\n", player->player_img->instances[0].y);
	player->player_img->instances[0].y += dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed;
	player->player_img->instances[0].x += dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed;
	printf("instace.x: %d\n", player->player_img->instances[0].x);
	printf("instace.y: %d\n", player->player_img->instances[0].y);
	player->pos->x = (player->player_img->instances[0].x - 30) / game->scene->tile;
	player->pos->y = (player->player_img->instances[0].y - 30) / game->scene->tile;
	printf("x: %f\n", player->pos->x);
	printf("y: %f\n", player->pos->y);
	//printf("ft_ws: despues de mover player->angle : %f\n", player->angle);
}

void	ft_ad(t_player *player, double dir, double ang)
{
	double rot; //aux para no cambiar el angulo real del player
	// double res = (dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed) + ft_deg_to_rad(ang);
	// printf("ft_ad: esta mierda que res : %f\n", res);
	//printf("ft_ad: esta mierda player->angle : %f\n", player->angle);
	// if (dir == 1.0)
	// {
	// 	printf("ESTOY PULSANDO D\n");
	// 	rot = player->angle + ang;
	// }
	// else if (dir == -1.0)
	// {
	// 	printf("ESTOY PULSANDO A\n");
	// 	rot = player->angle - ang;
	// }
	//debería actualizar el angulo del jugador o no (player->angle += ang)??
	rot = player->angle + ang; //en grados
	//printf("ft_ad: esta mierda que rot : %f\n", rot);
	player->player_img->instances[0].x += cos(ft_deg_to_rad(rot)) * player->mov_speed;//ft_deg_to_rad(player->angle)
	player->player_img->instances[0].y += sin(ft_deg_to_rad(rot)) * player->mov_speed;
	//printf("ft_ad: despues de mover player->angle : %f\n", player->angle);
}

void	ft_rotate(t_player *player, double sign)
{
	float	ang;
	float	tile = 15.0f;
	int		x;
	int		y = 0;
	//printf("%sen ft_rotate: player->angle: %f%s\n", GOOD, player->angle, END);
	player->angle += sign * player->rot_speed;
	printf("%sen ft_rotate: player->angle: %f%s\n", WRONG, player->angle, END);
	if (player->angle < 0)
		player->angle += 360;
	if (player->angle >= 360)
		player->angle -= 360;
	//pruebas: cometar antes de subir
	//ang = ft_deg_to_rad(player->angle);
}
	// while (y < tile)
	// {
	// 	x = 0;
	// 	while (x < tile)
	// 	{
	// 		player->player_img->instances[0].x = cos(ang) * (x - tile / 2) - sin(ang) * (y - tile / 2) + tile / 2;
	// 		player->player_img->instances[0].y = sin(ang) * (x - tile / 2) + cos(ang) * (y - tile / 2) + tile / 2;
	// 		x++;
	// 	}
	// 	y++;
	// }
	// player->player_img->instances[0].x += sign * cos(ang) * 10;

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ws(game->player, 1.0, game);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ws(game->player, -1.0, game);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ad(game->player, -1.0, -90);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ad(game->player, 1.0, 90);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)) //MLX_REPEAT
		ft_rotate(game->player, -1.0);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_rotate(game->player, 1.0);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE) //mlx_press??
		mlx_close_window(game->mlx);
}
