/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/08 13:51:23 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_ws(t_player *player, double dir, t_game *game)
{
	double	y_c;
	double	x_c;

	printf("------------------------\n");
	printf("%sANTES: player.pos.x: %f\n", DEBUG2, player->pos->x);
	printf("ANTES: player.pos.y: %f\n%s", player->pos->y, END);
	player->pos->y += (dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed) / game->scene->tile;
	player->pos->x += (dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed) / game->scene->tile;
	printf("%sDESPUES: player.pos.x: %f\n", DEBUG2, player->pos->x);
	printf("DESPUES: player.pos.y: %f\n%s", player->pos->y, END);
	ft_paint_minimap(game, game->scene, 1);
}

/*void	ft_ad(t_player *player, double dir, double ang, t_game *game)
{
	double	x_c;
	double	y_c;
	int	rot; //aux para no cambiar el angulo real del player

	rot = player->angle + ang; //en grados
	printf("ft_ad: esta mierda que rot : %d\n", rot);
	printf("%sANTESen ft_rotate: player->angle: %d%s\n", GOOD, player->angle, END);
	printf("instace.x: %d\n", player->player_img->instances[0].x);
	printf("instace.y: %d\n", player->player_img->instances[0].y);
	if (rot < 0)
		rot += 360;
	if (rot >= 360)
		rot = rot % 360;
	printf("%sANTESen ft_rotate: player->angle: %d%s\n", GOOD, player->angle, END);
	y_c = player->player_img->instances[0].y + 0.5 + (sin(ft_deg_to_rad(rot)) * player->mov_speed);
	x_c = player->player_img->instances[0].x + 0.5 + (cos(ft_deg_to_rad(rot)) * player->mov_speed);
	printf("calculo en x: %f\n", dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed);
	printf("calculo en y: %f\n", dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed);
	printf("x_c: %f\n", x_c);
	printf("y_c: %f\n", y_c);
	if (!ft_left_collision(game, y_c, x_c - 1) && !ft_right_collision(game, y_c, x_c))
	{
		player->player_img->instances[0].x = x_c;//ft_deg_to_rad(player->angle)
		player->player_img->instances[0].y = y_c;
		// printf("%sinstace.x: %d\n", DEBUG_COLOR, player->player_img->instances[0].x);
		// printf("instace.y: %d\n%s", player->player_img->instances[0].y, END);
		player->pos->x = (player->player_img->instances[0].x - 30) / game->scene->tile;
		player->pos->y = (player->player_img->instances[0].y - 30) / game->scene->tile;
		// printf("%sDESPUESen ft_rotate: player->angle: %d%s\n", WRONG, player->angle, END);
	}
}*/

void	ft_ad(t_player *player, double dir, double ang, t_game *game)
{
	int	rot; //aux para no cambiar el angulo real del player
	double	y_c;
	double	x_c;

	printf("------------------------\n");
	rot = player->angle + ang; //en grados
	printf("ft_ad: esta mierda que rot : %d\n", rot);
	printf("%sANTESen ft_rotate: player->angle: %d%s\n", GOOD, player->angle, END);
	printf("%sANTES: player.pos.x: %f\n", DEBUG2, player->pos->x);
	printf("ANTES: player.pos.y: %f\n%s", player->pos->y, END);
	player->pos->y += (sin(ft_deg_to_rad(rot)) * player->mov_speed) / game->scene->tile;
	player->pos->x += (cos(ft_deg_to_rad(rot)) * player->mov_speed) / game->scene->tile;
	printf("%sDESPUES: player.pos.x: %f\n", DEBUG2, player->pos->x);
	printf("DESPUES: player.pos.y: %f\n%s", player->pos->y, END);
	ft_paint_minimap(game, game->scene, 1);
}

void	ft_rotate(t_player *player, double sign, t_game *game)
{
	float	ang;
	// printf("%sANTESen ft_rotate: player->angle: %d%s\n", GOOD, player->angle, END);
	player->angle += sign * player->rot_speed;
	// printf("%sDESPUESen ft_rotate: player->angle: %d%s\n", WRONG, player->angle, END);
	if (player->angle < 0)
		player->angle += 360;
	if (player->angle >= 360)
		player->angle = player->angle % 360;
	printf("%sDESPUESen ft_rotate: player->angle: %d%s\n", WRONG, player->angle, END);
}

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		ft_ws(game->player, 1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		ft_ws(game->player, -1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		ft_ad(game->player, -1.0, -90, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		ft_ad(game->player, 1.0, 90, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_rotate(game->player, -1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_rotate(game->player, 1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
