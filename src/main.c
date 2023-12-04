/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:14:59 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/30 17:56:18 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_free_all(t_game *info)
{
	ft_clean_map(info);
/* 	ft_free_double_pointer(info->scene->map);
	free(info->scene->no_path);
	free(info->scene->so_path);
	free(info->scene->we_path);
	free(info->scene->ea_path);
	free(info->scene->f_color);
	free(info->scene->c_color);
	free(info->scene); */
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
	mlx_key_hook(info->mlx, &ft_controls, info);
	ft_init_map(info);
	//mlx_loop_hook(info->mlx, &ft_paint_minimap, info); //& or not, i dont know. 3 param: info ó mlx???
	//mlx_resize_hook(info->mlx, &ft_resize, info); //seg fault cuando intento agrandar
	mlx_loop(info->mlx);
}

/*para este punto deberia tener las texturas ya cargadas en
t_img para poder usarlas???*/

void	ft_set_window(t_game *info)
{
	info->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!info->mlx)
		ft_error(WINDOW, NULL);
	if (ft_check_monitor(info->mlx) == 0)
	{
		//free mierdas
		return ;
	}
	mlx_set_window_limit(info->mlx, 500, 500, 2560, 1440); // ponemos limites de la ventana, en prueba ahora mismo??, 2560, 1440 ->valores de pantalla completa
	info->canvas = mlx_new_image(info->mlx, 2560, 1440); //para poder rendear las imagenes, cómo crear un lienzp donde poder dibujar pixeles
	info->scene->img = info->canvas; //para pintar mapa como en otra capa?
	if (!info->canvas)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(info->mlx, info->canvas, 0, 0) == -1)
		ft_error(IMAGE, NULL);
	ft_init_game(info);
	mlx_terminate(info->mlx);
}

int	main(int ac, char **av)
{
	atexit(ft_leaks);
	int	fd;
	t_game	info;
	t_scene	scene;

	fd = ft_arg_check(ac, av);
	if (fd < 0)
		return (-1);
	if (ft_parse(&scene, fd, av[1]) != -1) //-> carga del mapa en memoria y checkeo de que esté correcto
	{
		info.scene = &scene;
		ft_set_window(&info); // le tendré que meter av[1]??
	}
	ft_free_all(&info);
}
