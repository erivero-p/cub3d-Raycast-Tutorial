/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/04 14:10:24 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_init_player(t_player *player, t_game *game)
{
	game->player->pos_map = malloc(sizeof(t_coord));
	*player->pos_map = ft_get_player_pos(game);
	player->mlx = game->mlx;
	player->player_img = game->canvas;
	player->color = RED;
	printf("en ft_init_player: pos_map.x: %i / pos_map.y: %i\n", player->pos_map->x, player->pos_map->y);
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
