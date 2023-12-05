/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/05 17:13:52 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void ft_get_corner(t_game *game)
{
	float	centre_x;
	float	centre_y;
	t_coord sup_left;
	t_coord sup_right;
	t_coord inf_left;
	t_coord inf_right;

	printf("LLEGO\n");
	sup_left.y = game->player->player_img->instances[0].y;
	sup_left.x = game->player->player_img->instances[0].x;
	printf("ft_get_corner: esquina superior izquierda: y: %i / x: %i\n", sup_left.y, sup_left.x);
	sup_right.y = game->player->player_img->instances[0].y;
	sup_right.x = game->player->player_img->instances[0].x + game->scene->tile;
	printf("ft_get_corner: esquina superior derecha: y: %i / x: %i\n", sup_right.y, sup_right.x);
	inf_left.y = game->player->player_img->instances[0].y + game->scene->tile;
	inf_left.x = game->player->player_img->instances[0].x;
	printf("ft_get_corner: esquina inferior izquierda: y: %i / x: %i\n", inf_left.y, inf_left.x);
	inf_right.y = game->player->player_img->instances[0].y + game->scene->tile;
	inf_right.x = game->player->player_img->instances[0].x + game->scene->tile;
	printf("ft_get_corner: esquina inferior derecha: y: %i / x: %i\n", inf_right.y, inf_right.x);
	centre_x = sup_left.x + game->scene->tile / 2;
	centre_y = sup_left.y + game->scene->tile / 2;
	printf("ft_get_corner: centro: y: %f / x: %f\n", centre_y, centre_x);
}

void	ft_init_player(t_player *player, t_game *game)
{
	player->mlx = game->mlx;
	player->player_img = game->scene->player;
	game->player->pos_map = malloc(sizeof(t_coord));
	*player->pos_map = ft_get_player_init_pos(game);
	printf("en ft_init_player: player_y: %i / player_x: %i\n", player->player_img->instances[0].y, player->player_img->instances[0].x);
	ft_get_corner(game);
	player->color = RED;
	player->mov_speed = 5 * game->mlx->delta_time; //pixeles
	player->rot_speed = 1.5 * game->mlx->delta_time; // 3 + (math.pi / 180) -> grados
}

t_coord	ft_get_player_init_pos(t_game *game)
{
	t_coord	pos;
	int		y;
	int		x;

	y = 0;
	while (game->scene->map[y])
	{
		x = 0;
		while (game->scene->map[y][x])
		{
			if (ft_strchr("NSEW", game->scene->map[y][x]))
			{
				pos.x = x;
				pos.y = y;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	ft_free_player(t_game *game)
{
	free(game->player->pos_map);
}
