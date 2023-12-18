/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:38:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/18 11:24:29 by marirodr         ###   ########.fr       */
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

void	ft_resize(void *param)
{
	t_game	*info;
	int		w;
	int		h;

	info = (t_game *)param;
	if (w < WIDTH || h < HEIGHT)
		mlx_set_setting(MLX_STRETCH_IMAGE, true); //MLX_FULLSCREEN, MLX_MAXIMICED ???
	mlx_delete_image(info->mlx, info->scene->canvas);
	//mlx_get_window_pos(info->mlx, &w, &h); // wtf?
	info->scene->canvas = mlx_new_image(info->mlx, 20, 20); //estos valores todavia no se muy bien como van, no se hacer proporcional ahora mismo
	if (!info->scene->canvas)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(info->mlx, info->scene->canvas, 20, 20) == -1) //estos valores todavia no se muy bien como van
		ft_error(IMAGE, NULL);
}
