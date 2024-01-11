/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/10 16:20:13 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_ws(t_player *player, double dir, t_game *game, float angle)
{
	double	x_c;
	double	y_c;

	if (!ft_collision(game, angle))
	{
		player->pos->y += (dir * sin(ft_deg_to_rad(player->angle)) \
		* player->mov_speed) / game->scene->tile;
		player->pos->x += (dir * cos(ft_deg_to_rad(player->angle)) \
		* player->mov_speed) / game->scene->tile;
		ft_set_minimap(game, game->scene, 1);
	}
}

//rot: aux para no cambiar el angulo real del player. Está en grados
void	ft_ad(t_player *player, double dir, double ang, t_game *game)
{
	int		rot;
	double	y_c;
	double	x_c;

	rot = player->angle + ang;
	if (!ft_collision(game, ang))
	{
		player->pos->y += (sin(ft_deg_to_rad(rot)) \
		* player->mov_speed) / game->scene->tile;
		player->pos->x += (cos(ft_deg_to_rad(rot)) \
		* player->mov_speed) / game->scene->tile;
		ft_set_minimap(game, game->scene, 1);
	}
}

void	ft_rotate(t_player *player, double sign, t_game *game)
{
	float	ang;

	player->angle += sign * player->rot_speed;
	if (player->angle < 0)
		player->angle += 360;
	if (player->angle >= 360)
		player->angle = player->angle % 360;
}

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		ft_ws(game->player, 1.0, game, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		ft_ws(game->player, -1.0, game, 180);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		ft_ad(game->player, -1.0, 270, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		ft_ad(game->player, 1.0, 90, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_rotate(game->player, -1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_rotate(game->player, 1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
