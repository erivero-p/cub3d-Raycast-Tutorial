/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/05 17:15:30 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*info;

	info = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		ft_up(info);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		ft_down(info);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		ft_left(info);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		ft_right(info);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO FLECHA ARRIBA\n");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO FLECHA ABAJO\n");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO <-\n");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO ->\n");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE) //mlx_press??
		mlx_close_window(info->mlx);
}

void	ft_up(t_game *game)
{
	printf("ESTOY PULSANDO W\n"); //image->instances[0].y -= 5;
	if (game->player->player_img->instances[0].y - 5 == 25)
	{
		printf("NO PUEDES PASAR\n"); //image->instances[0].y -= 5;
		return ;
	}
	//printf("INIT: player_img.intances.y: %i / player_img.intances.x: %i\n", game->player->player_img->instances[0].y, game->player->player_img->instances[0].x);
	game->player->player_img->instances[0].y -= (5 * game->mlx->delta_time); //5 pixeles hacia arriba
	//printf("player_img.intances.y: %i / player_img.intances.x: %i\n", game->player->player_img->instances[0].y, game->player->player_img->instances[0].x);
}

void	ft_down(t_game *game)
{
	if (game->player->player_img->instances[0].y + 5 == 230)
	{
		printf("NO PUEDES PASAR\n"); //image->instances[0].y -= 5;
		return ;
	}
	printf("ESTOY PULSANDO S\n");
	game->player->player_img->instances[0].y += 5;
}

void	ft_left(t_game *game)
{
	if (game->player->player_img->instances[0].x - 5 == 25)
	{
		printf("NO PUEDES PASAR\n"); //image->instances[0].y -= 5;
		return ;
	}
	printf("ESTOY PULSANDO A\n");
	game->player->player_img->instances[0].x -= 5;
}

void	ft_right(t_game *game)
{
	if (game->player->player_img->instances[0].x + 5 == 530)
	{
		printf("NO PUEDES PASAR\n"); //image->instances[0].y -= 5;
		return ;
	}
	printf("ESTOY PULSANDO D\n");
	game->player->player_img->instances[0].x += 5;
}
