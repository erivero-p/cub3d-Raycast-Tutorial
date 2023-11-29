/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:14:59 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 11:44:46 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a) //para pruebas, quitar en futuro
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void *param)  //para pruebas, quitar en futuro
// {
// 	t_game *info;

// 	info = (t_game *)param;
// 	for (int32_t i = 0; i < (int32_t)info->test->width; ++i)
// 	{
// 		for (int32_t y = 0; y < (int32_t)info->test->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(info->test, i, y, color);
// 		}
// 	}
// }

void	ft_free_all(t_game *info)
{
	ft_free_double_pointer(info->scene->map);
	free(info->scene->no_path);
	free(info->scene->so_path);
	free(info->scene->we_path);
	free(info->scene->ea_path);
	free(info->scene->f_color);
	free(info->scene->c_color);
	free(info->scene);
	//free las matrices y los paths de t_scene
	//mlx_close_window(info->mlx); ??
	exit(0);
}

void	ft_leaks(void)
{
	system("leaks -q cub3D");
}

void	ft_init_game(t_game *info)
{
  lx_loop_hook(info->mlx, &ft_randomize, info); //& or not, i dont know. 3 param: info ó mlx???
	ft_init_map(info);
	//mlx_loop_hook(info->mlx, &ft_randomize, info); //& or not, i dont know. 3 param: info ó mlx???
	//mlx_loop_hook(info->mlx, &ft_paint_minimap, info); //& or not, i dont know. 3 param: info ó mlx???
	mlx_key_hook(info->mlx, &ft_controls, info);
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
	mlx_set_window_limit(info->mlx, 500, 500, 2560, 1440); // ponemos limites de la ventana, en prueba ahora mismo??
	info->test = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->map->img = info->test; //qué estoy haciendo aquí exactamente?
	if (!info->test)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(info->mlx, info->test, 0, 0) == -1)
		ft_error(IMAGE, NULL);
	ft_init_game(info);
	mlx_terminate(info->mlx);
}

int	main(int ac, char **av)
{
	atexit(ft_leaks);
	int	fd;
	t_game	info;

	fd = ft_arg_check(ac, av);
	if (fd < 0)
		return (-1);
	if (ft_parse(&info, fd, av[1]) != -1) //-> carga del mapa en memoria y checkeo de que esté correcto
	{
		ft_set_window(&info); // le tendré que meter av[1]??
	}
	ft_free_all(&info);
}
