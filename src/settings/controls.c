/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/12 12:14:05 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_ws(t_player *player, double dir)
{
	double res = (dir * sin(player->angle) * 5.0);
	printf("esta mierda que : %f\n", res);
	// if (dir == 1.0)
	// 	printf("ESTOY PULSANDO S\n");
	// else if (dir == -1.0)
	// 	printf("ESTOY PULSANDO W\n");
	player->player_img->instances[0].y += dir * sin(player->angle) * 5.0;
}

void	ft_ad(t_player *player, double dir, double ang)
{
	double rot;
	double res = (dir * cos(player->angle) * 5.0) + ang;
	printf("esta mierda que : %f\n", res);
	// if (dir == 1.0)
	// {
	// 	printf("ESTOY PULSANDO D\n");
	// 	rot = player->angle + ang;
	// }
	// else if (dir == -1.0)
	// {
	// 	printf("ESTOY PULSANDO A\n");
	// 	rot = player->angle - ang;
	// }
	//debería actualizar el angulo del jugador o no (player->angle += ang)??
	rot = player->angle + ang;
	player->player_img->instances[0].x += cos(rot) * 5.0;
}

// void	ft_rotate(t_player *player, double sign)
// {
// 	player->angle += /*this.gira*/-1 * player->rot_speed; // lo segundo es la velocidad de giro
// }

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		ft_ws(game->player, 1.0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		ft_ws(game->player, -1.0);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		ft_ad(game->player, -1.0, (M_PI / 2) * -1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		ft_ad(game->player, 1.0, M_PI / 2);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO <-\n");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO ->\n");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE) //mlx_press??
		mlx_close_window(game->mlx);
}

void	ft_up(t_game *game)
{
	//if (game->player->player_img->instances[0].x + 5 == 530)
	//if (game->player->player_img->instances[0].x - 5 == 25)
	//if (game->player->player_img->instances[0].y + 5 == 230)
	if (game->player->player_img->instances[0].y - 5 == 25)
	{
		printf("NO PUEDES PASAR\n");
		return ;
	}
	//printf("INIT: player_img.intances.y: %i / player_img.intances.x: %i\n", game->player->player_img->instances[0].y, game->player->player_img->instances[0].x);
	//printf("deltaTime es: %f\n", game->mlx->delta_time);
	//game->player->player_img->instances[0].y -= 5; //5 pixeles hacia arriba -> desplazamiento sin giro
	game->player->player_img->instances[0].y += 1 * sin(game->player->angle) * 5; //toma el angulo en radianes, no en grados; 5 es la velocidad de mov
	//printf("player_img.intances.y: %i / player_img.intances.x: %i\n", game->player->player_img->instances[0].y, game->player->player_img->instances[0].x);
	game->player->angle += /*this.gira*/-1 * game->player->rot_speed; // lo segundo es la velocidad de giro
}
