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
	ft_init_map(info);
	ft_init_player(info->player, info);
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

int	ft_load_png(mlx_texture_t *ptr, char *path)
{
	ptr = NULL;
	ptr = mlx_load_png(path);
	if (!ptr)
		return (-1);
	return (0);
}

/* int	ft_load_homer(t_homer *homer, t_game *info)
{
	if (ft_load_png(homer->h0, "/Users/erivero-/Desktop/coll-cub3d/homer/0") == -1
	|| ft_load_png(homer->h1, "/Users/erivero-/Desktop/coll-cub3d/homer/1") == -1
	|| ft_load_png(homer->h2, "/Users/erivero-/Desktop/coll-cub3d/homer/2") == -1
	|| ft_load_png(homer->h3, "/Users/erivero-/Desktop/coll-cub3d/homer/3") == -1
	|| ft_load_png(homer->h4, "/Users/erivero-/Desktop/coll-cub3d/homer/4") == -1
	|| ft_load_png(homer->h5, "/Users/erivero-/Desktop/coll-cub3d/homer/5") == -1
	|| ft_load_png(homer->h6, "/Users/erivero-/Desktop/coll-cub3d/homer/6") == -1)
		return (-1);
	return (0);
} */

void	ft_load_homer(t_homer *homer, t_game *info)
{
	//	homer = malloc(sizeof(t_homer *));
//	homer->h6 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/6.png");
	homer->h6 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/6.png");
	if (!homer->h6)
		printf("a ver\n");
	if (homer->h6)
		printf("he%d\n", homer->h6->height);
	printf("todo bien\n");
	homer->h5 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/5.png");
	homer->h4 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/4.png");
	homer->h3 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/3.png");
	homer->h2 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/2.png");
	homer->h1 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/1.png");
	homer->h0 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/0.png");
/* 	if (!homer->h0 || !homer->h1 || !homer->h2 || !homer->h3 
	|| !homer->h0 ||  ) */
}

int	main(int ac, char **av)
{
	atexit(ft_leaks);
	int			fd;
	t_game		info;
	t_scene		scene;
	t_player	player;
	t_img		imgs;
	t_homer		homer;

	fd = ft_arg_check(ac, av);
	if (fd < 0)
		return (-1);
	if (ft_parse(&scene, fd, av[1], &imgs) != -1) //-> carga del mapa en memoria y checkeo de que esté correcto
	{
		info.scene = &scene;
		info.player = &player;
		info.imgs = &imgs;
		ft_load_homer(&homer, &info);
		info.homer = &homer;
		if (!info.homer->h0->height)
			printf("no hija no\n");
		ft_print_scene(&scene, DEBUG_COLOR);
		ft_set_window(&info);
		ft_init_game(&info);
		mlx_terminate(info.mlx);
	}
	ft_free_all(&info);
}
