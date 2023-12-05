/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/05 11:52:56 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

	//player->player_img = game->canvas; //se mueve el canvas
	//player->player_img = game->scene->img; //se mueve el canvas
	//player->player_img = game->scene->mini; //se mueve el minimapa

void	ft_init_player(t_player *player, t_game *game)
{
	game->player->pos_map = malloc(sizeof(t_coord));
	*player->pos_map = ft_get_player_pos(game);
	player->mlx = game->mlx;
	player->player_img = game->scene->mini;
	player->color = RED;
	player->mov_speed = 3 * game->mlx->delta_time; //pixeles
	player->rot_speed = 1.5 * game->mlx->delta_time; // 3 + (math.pi / 180) -> grados
	//printf("en ft_init_player: pos_map.x: %i / pos_map.y: %i\n", player->pos_map->x, player->pos_map->y);
}

t_coord	ft_get_player_pos(t_game *game)
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
