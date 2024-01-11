/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:03 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/11 11:22:20 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

double	ft_get_player_angle(t_scene *scene)
{
	int	y;
	int	x;

	y = 0;
	while (scene->map[y])
	{
		x = 0;
		while (scene->map[y][x])
		{
			if (scene->map[y][x] == 'E')
				return (0.0);
			if (scene->map[y][x] == 'S')
				return (90.0);
			if (scene->map[y][x] == 'W')
				return (180.0);
			if (scene->map[y][x] == 'N')
				return (270.0);
			x++;
		}
		y++;
	}
	return (-1);
	return (-1);
}

void	ft_init_player(t_player *player, t_game *game)
{
	player->mlx = game->mlx;
	player->size = 5;
	ft_render_player(game, game->scene, game->player);
	game->player->pos = malloc(sizeof(t_coord));
	*player->pos = ft_get_player_init_pos(game);
	player->color = RED;
	player->mov_speed = 0.5;
	player->rot_speed = 2.0;
	player->angle = ft_get_player_angle(game->scene);
	player->mov_speed = 0.5;
	player->rot_speed = 2.0;
	player->angle = ft_get_player_angle(game->scene);
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
	pos.x += 0.5;
	pos.y += 0.5;
	return (pos);
}

double	ft_deg_to_rad(double deg)
{
	double	rad;

	rad = deg * (M_PI / 180.0);
	return (rad);
}

/* void	ft_free_player(t_game *game)
{
	free(game->player->pos);
} */
