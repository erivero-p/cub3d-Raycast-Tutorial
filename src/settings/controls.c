/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/18 17:10:09 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// void	ft_check_collision(t_game *game, int y, int x)
// {
// 	if (game->scene->map[(int)player->pos->y][(int)player->pos->x] == '1')
// 		printf("%sME ENCUENTRO MURO%s\n", GOOD, END);
// }

	//colision bruta
	// int	x_coll;
	// int	y_coll;
	// y_coll = ((player->player_img->instances[0].y + (dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed) - 30) / game->scene->tile);
	// x_coll = ((player->player_img->instances[0].x + (dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed) - 30) / game->scene->tile);
	// printf("y_coll: %d\n", y_coll);
	// printf("x_coll: %d\n", x_coll);
	// if (game->scene->map[y_coll][x_coll] == '1')
	// {
	// 	printf("%sNO PUEDES PASAR%s\n", GOOD, END);
	// 	//return ;
	// }
void	ft_ws(t_player *player, double dir, t_game *game)
{
	// double res = (dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed);
	// printf("ft_ws: esta mierda que res : %f\n", res);
	// printf("ft_ws: esta mierda player->angle : %f\n", player->angle);
	t_coord aux;

	*player->center = ft_get_center(game);
	aux = *player->center;
	aux.y += ((dir) * sin(ft_deg_to_rad(player->angle)) * player->mov_speed);
	aux.x += ((dir) * cos(ft_deg_to_rad(player->angle)) * player->mov_speed);
	printf("despues mov aux.x: %f\n", aux.x);
	printf("despues mov aux.y: %f\n", aux.y);
	if (dir == 1.0)
		aux.y = aux.y - 7.5;
	else if (dir == -1.0)
		aux.y = aux.y + 2.5;
	aux.y = (aux.y - 30) / 15;
	aux.x = (aux.x - 30) / 15;
	printf("aux.x en tiles: %f\n", aux.x);
	printf("aux.y en tiles: %f\n", aux.y);
	if (game->scene->map[(int)aux.y][(int)aux.x] == '1')
	{
		printf("%sNO PUEDES PASAR%s\n", WRONG, END);
		return ;
	}
	//printf("despues mov instace.x: %d\n", player->player_img->instances[0].x);
	//printf("despues mov instace.y: %d\n", player->player_img->instances[0].y);
	player->player_img->instances[0].y += dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed;
	player->player_img->instances[0].x += dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed;
	//printf("instace.x: %d\n", player->player_img->instances[0].x);
	//printf("instace.y: %d\n", player->player_img->instances[0].y);
	player->pos->x = (player->player_img->instances[0].x - 30) / game->scene->tile;
	player->pos->y = (player->player_img->instances[0].y - 30) / game->scene->tile;
	printf("pos->x en tiles: %f\n", player->pos->x);
	printf("pos->y en tiles: %f\n", player->pos->y);
	*player->center = ft_get_center(game);
	printf("--------------\n");
	//printf("ft_ws: despues de mover player->angle : %f\n", player->angle);
}

void	ft_ad(t_player *player, double dir, double ang, t_game *game)
{
	double rot; //aux para no cambiar el angulo real del player
	rot = player->angle + ang; //en grados
	//printf("ft_ad: esta mierda que rot : %f\n", rot);
	t_coord aux;

	*player->center = ft_get_center(game);
	aux = *player->center;
	aux.y += (sin(ft_deg_to_rad(rot)) * player->mov_speed);
	aux.x += (cos(ft_deg_to_rad(rot)) * player->mov_speed);
	printf("despues mov aux.x: %f\n", aux.x);
	printf("despues mov aux.y: %f\n", aux.y);
	if (dir == 1.0)
		aux.x = aux.x + 2.5;
	else if (dir == -1.0)
		aux.x = aux.x - 7.5;
	aux.y = (aux.y - 30) / 15;
	aux.x = (aux.x - 30) / 15;
	printf("aux.x en tiles: %f\n", aux.x);
	printf("aux.y en tiles: %f\n", aux.y);
	if (game->scene->map[(int)aux.y][(int)aux.x] == '1')
	{
		printf("%sNO PUEDES PASAR%s\n", WRONG, END);
		return ;
	}
	player->player_img->instances[0].x += cos(ft_deg_to_rad(rot)) * player->mov_speed;//ft_deg_to_rad(player->angle)
	player->player_img->instances[0].y += sin(ft_deg_to_rad(rot)) * player->mov_speed;
	//printf("ft_ad: despues de mover player->angle : %f\n", player->angle);
	player->pos->x = (player->player_img->instances[0].x - 30) / game->scene->tile;
	player->pos->y = (player->player_img->instances[0].y - 30) / game->scene->tile;
	printf("x: %f\n", player->pos->x);
	printf("y: %f\n", player->pos->y);
	if (game->scene->map[(int)player->pos->y][(int)player->pos->x] == '1')
		printf("%sME ENCUENTRO MURO%s\n", GOOD, END);
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
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ws(game->player, 1.0, game);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ws(game->player, -1.0, game);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ad(game->player, -1.0, -90, game);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_ad(game->player, 1.0, 90, game);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)) //MLX_REPEAT
		ft_rotate(game->player, -1.0, game);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_rotate(game->player, 1.0, game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE) //mlx_press??
		mlx_close_window(game->mlx);
}
