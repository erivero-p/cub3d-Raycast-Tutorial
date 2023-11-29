/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:39:06 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 12:54:26 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*info;

	info = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO W\n");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO S\n");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO A\n");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO D\n");
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO W\n");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO S\n");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO A\n");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		ft_printf("ESTOY PULSANDO D\n");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE) //mlx_press??
		mlx_close_window(info->mlx);
}
