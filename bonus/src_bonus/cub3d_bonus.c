/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:14:59 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/12 14:17:14 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D_bonus.h"

/* void	ft_leaks(void)
{
	system("leaks -q cub3D");
} */
void	ft_init_game(t_game *info)
{
	ft_init_player(info->player, info);
	ft_init_map(info);
	mlx_key_hook(info->mlx, &ft_controls, info);
/* 	if (BONUS == 1)
	{ */
	info->imgs->candle_img = NULL;
	mlx_mouse_hook(info->mlx, &ft_mouse, info);
/* 	} */
	mlx_loop_hook(info->mlx, &ft_loop_handler, info);
	mlx_loop(info->mlx);
}

int	ft_set_window(t_game *info)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!info->mlx)
		ft_error(WINDOW, NULL);
	if (ft_check_monitor(info->mlx) == 0)
		return (-1);
	mlx_set_window_limit(info->mlx, 500, 500, 2560, 1440);
	return (0);
}

	//atexit(ft_leaks);
int	main(int ac, char **av)
{
	int			fd;
	t_game		info;
	t_scene		scene;
	t_player	player;
	t_img		imgs;

	fd = ft_arg_check(ac, av);
	if (fd < 0)
		return (-1);
	if (ft_parse(&scene, fd, av[1], &imgs) != -1)
	{
		info.scene = &scene;
		info.player = &player;
		info.imgs = &imgs;
		if (ft_set_window(&info) != -1)
		{
			ft_init_game(&info);
			mlx_terminate(info.mlx);
		}
	}
	ft_clean_map(&info);
}
