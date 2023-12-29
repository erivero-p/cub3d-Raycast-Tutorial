/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/29 12:41:25 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_coord	ft_get_center(t_game *game)
{
	t_coord	center;

	center.x = game->player->player_img->instances[0].x + game->scene->tile / 2;
	center.y = game->player->player_img->instances[0].y + game->scene->tile / 2;
	printf("ft_get_corner: centro: y: %f / x: %f\n", center.y, center.x);
	return (center);
}

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
	return (-1); //esto es pa que se calle el compilador porque realmente nunca llegaría aqui
}

void	ft_init_player(t_player *player, t_game *game)
{
	player->mlx = game->mlx;
	player->size = 5;
	ft_render_player(game, game->scene, game->player);
	game->player->pos = malloc(sizeof(t_coord));
	*player->pos = ft_get_player_init_pos(game);
	printf("en ft_init_player: player_y: %d / player_x: %d\n", player->player_img->instances[0].y, player->player_img->instances[0].x);
	printf("en ft_init_player: player.pos.y: %f / player.pos.x: %f\n", player->pos->y, player->pos->x);
	game->player->center = malloc(sizeof(t_coord));
	*player->center = ft_get_center(game);
	player->color = RED;
	player->mov_speed = 1.0; //pixeles
	//la velocidad de giro son cuantos grados va a girar y tenemos que hacer la conversion a radianes -> game->mlx->delta_time
	player->rot_speed = 3.0; //multiplicar por * (M_PI / 180) -> pi/180 conversion a radianes -> game->mlx->delta_time
	player->angle = ft_get_player_angle(game->scene); //en grados
	printf("en ft_init_player: angle: %f\n", player->angle);
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

void	ft_free_player(t_game *game)
{
	free(game->player->pos);
}
