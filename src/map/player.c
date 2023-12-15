/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:52:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/15 13:06:42 by marirodr         ###   ########.fr       */
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
	printf("ft_get_corner: esquina superior izquierda: y: %f / x: %f\n", sup_left.y, sup_left.x);
	sup_right.y = game->player->player_img->instances[0].y;
	sup_right.x = game->player->player_img->instances[0].x + game->scene->tile;
	printf("ft_get_corner: esquina superior derecha: y: %f / x: %f\n", sup_right.y, sup_right.x);
	inf_left.y = game->player->player_img->instances[0].y + game->scene->tile;
	inf_left.x = game->player->player_img->instances[0].x;
	printf("ft_get_corner: esquina inferior izquierda: y: %f / x: %f\n", inf_left.y, inf_left.x);
	inf_right.y = game->player->player_img->instances[0].y + game->scene->tile;
	inf_right.x = game->player->player_img->instances[0].x + game->scene->tile;
	printf("ft_get_corner: esquina inferior derecha: y: %f / x: %f\n", inf_right.y, inf_right.x);
	centre_x = sup_left.x + game->scene->tile / 2;
	centre_y = sup_left.y + game->scene->tile / 2;
	printf("ft_get_corner: centro: y: %f / x: %f\n", centre_y, centre_x);
}

//sale el angulo de inicio en radianes directamente

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
	player->player_img = game->scene->player;
	game->player->pos = malloc(sizeof(t_coord));
	*player->pos = ft_get_player_init_pos(game);
	printf("en ft_init_player: player_y: %d / player_x: %d\n", player->player_img->instances[0].y, player->player_img->instances[0].x);
	printf("en ft_init_player: player.pos.y: %f / player.pos.x: %f\n", player->pos->y, player->pos->x);
	//ft_get_corner(game);
	player->color = RED;
	player->mov_speed = 5.0; //pixeles
	//la velocidad de giro son cuantos grados va a girar y tenemos que hacer la conversion a radianes -> game->mlx->delta_time
	player->rot_speed = 5.0; //multiplicar por * (M_PI / 180) -> pi/180 conversion a radianes -> game->mlx->delta_time
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
