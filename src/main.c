/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:14:59 by marirodr          #+#    #+#             */

/*   Updated: 2023/12/21 12:55:35 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_free_all(t_game *info)
{
	ft_clean_map(info);
	//ft_free_player(info);
	//ft_delete_text(info);
	//free las matrices y los paths de t_map
	//mlx_close_window(info->mlx); ??
	exit(0);
}

void	ft_leaks(void)
{
	system("leaks -q cub3D");
}

void	ft_init_game(t_game *info)
{
	ft_init_player(info->player, info);
	ft_init_map(info);
	//ft_draw_pixel(info);
	mlx_key_hook(info->mlx, &ft_controls, info);
	if (BONUS == 1)
		mlx_mouse_hook(info->mlx, &ft_mouse, info);
	mlx_loop_hook(info->mlx, &ft_3Der, info);
//	ft_ray_tester(info, 241, 242, 270, 298);
	mlx_loop(info->mlx);
}

/*para este punto deberia tener las texturas ya cargadas en
t_img para poder usarlas???*/

void	ft_set_window(t_game *info)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!info->mlx)
		ft_error(WINDOW, NULL);
	if (ft_check_monitor(info->mlx) == 0)
	{
		//free mierdas
		return ;
	}
	mlx_set_window_limit(info->mlx, 500, 500, 2560, 1440); // ponemos limites de la ventana, en prueba ahora mismo??, 2560, 1440 ->valores de pantalla completa
}

int	main(int ac, char **av)
{
	atexit(ft_leaks);
	int			fd;
	t_game		info;
	t_scene		scene;
	t_player	player;
	t_img		imgs;

	fd = ft_arg_check(ac, av);
	if (fd < 0)
		return (-1);
	if (ft_parse(&scene, fd, av[1], &imgs) != -1) //-> carga del mapa en memoria y checkeo de que esté correcto
	{
		info.scene = &scene;
		info.player = &player;
		info.imgs = &imgs;
		ft_print_scene(&scene, DEBUG_COLOR);
		ft_set_window(&info);
		ft_init_game(&info);
		mlx_terminate(info.mlx);
	}
	ft_free_all(&info);
}
