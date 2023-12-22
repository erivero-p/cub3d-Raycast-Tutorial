/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/22 11:20:49 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

	//colision bruta
	// y_coll = ((player->player_img->instances[0].y + (dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed) - 30) / game->scene->tile);
	// x_coll = ((player->player_img->instances[0].x + (dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed) - 30) / game->scene->tile);
void	ft_ws(t_player *player, double dir, t_game *game)
{
	int	x_c;
	int	y_c;

	y_c = player->player_img->instances[0].y + (dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed);
	x_c = player->player_img->instances[0].x + (dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed);
	if (!ft_frontal_collision(game, y_c, x_c) && !ft_back_collision(game, y_c, x_c))
	{
		//printf("despues mov instace.x: %d\n", player->player_img->instances[0].x);
		//printf("despues mov instace.y: %d\n", player->player_img->instances[0].y);
		player->player_img->instances[0].y += dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed;
		player->player_img->instances[0].x += dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed;
		//printf("instace.x: %d\n", player->player_img->instances[0].x);
		//printf("instace.y: %d\n", player->player_img->instances[0].y);
		player->pos->x = (player->player_img->instances[0].x - 30) / game->scene->tile;
		player->pos->y = (player->player_img->instances[0].y - 30) / game->scene->tile;
	}
	//printf("ft_ws: despues de mover player->angle : %f\n", player->angle);
}

void	ft_ad(t_player *player, double dir, double ang, t_game *game)
{
	int	x_c;
	int	y_c;
	double	rot; //aux para no cambiar el angulo real del player

	rot = player->angle + ang; //en grados
	//printf("ft_ad: esta mierda que rot : %f\n", rot);
	y_c = player->player_img->instances[0].y + (sin(ft_deg_to_rad(rot)) * player->mov_speed);
	x_c = player->player_img->instances[0].x + (cos(ft_deg_to_rad(rot)) * player->mov_speed);
	if (!ft_left_collision(game, y_c, x_c) && !ft_right_collision(game, y_c, x_c))
	{
		player->player_img->instances[0].x += cos(ft_deg_to_rad(rot)) * player->mov_speed;//ft_deg_to_rad(player->angle)
		player->player_img->instances[0].y += sin(ft_deg_to_rad(rot)) * player->mov_speed;
		//printf("ft_ad: despues de mover player->angle : %f\n", player->angle);
		player->pos->x = (player->player_img->instances[0].x - 30) / game->scene->tile;
		player->pos->y = (player->player_img->instances[0].y - 30) / game->scene->tile;
	}
}

void	ft_rotate(t_player *player, double sign, t_game *game)
{
	float	ang;
	//printf("%sen ft_rotate: player->angle: %f%s\n", GOOD, player->angle, END);
	player->angle += sign * player->rot_speed;
	printf("%sen ft_rotate: player->angle: %f%s\n", WRONG, player->angle, END);
	if (player->angle < 0)
		player->angle += 360;
	if (player->angle >= 360)
		player->angle -= 360;
}

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		printf("BUSCANDO SEG FALUT2\n");
		ft_ws(game->player, 1.0, game);
	}
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

	// game = (t_game *)param;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	// 	ft_ws(game->player, 1.0, game);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	// 	ft_ws(game->player, -1.0, game);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	// 	ft_ad(game->player, -1.0, -90, game);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	// 	ft_ad(game->player, 1.0, 90, game);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	// 	ft_rotate(game->player, -1.0, game);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	// 	ft_rotate(game->player, 1.0, game);
	// if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(game->mlx);