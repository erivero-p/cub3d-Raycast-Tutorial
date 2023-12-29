/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:38:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/28 18:30:43 by marirodr         ###   ########.fr       */
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
