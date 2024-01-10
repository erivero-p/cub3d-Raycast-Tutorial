/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:38:03 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/10 11:57:55 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_check_monitor(mlx_t *mlx)
{
	int32_t	w;
	int32_t	h;

	mlx_get_monitor_size(0, &w, &h);
	if (w < WIDTH || h < HEIGHT)
	{
		ft_printf("monitor invalido\n");
		mlx_terminate(mlx);
		return (0);
	}
	return (1);
}

void	ft_mouse(mouse_key_t k, action_t act, modifier_key_t mod, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	k = 0;
	act = 0;
	mod = 0;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	if (x <= WIDTH / 2)
	{
		if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
			ft_rotate(game->player, -1.0, game);
	}
	else
	{
		if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
			ft_rotate(game->player, 1.0, game);
	}
}

	//mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);