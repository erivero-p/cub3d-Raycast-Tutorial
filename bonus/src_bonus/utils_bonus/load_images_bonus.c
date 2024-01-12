/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:20:33 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/12 14:02:29 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

void	ft_draw_pixel(t_game *game)
{
	int			y;
	int			x;
	mlx_image_t	*canvas;

	y = 0;
	x = 0;
	canvas = game->scene->canvas;
	game->imgs->size = 64;
	while (y < game->imgs->size)
	{
		x = 0;
		while (x < game->imgs->size)
		{
			game->imgs->color_pix = \
			ft_get_pixel_color(game->imgs->no_text, y, x, game->imgs->size);
			mlx_put_pixel(canvas, x + 300, y + 300, game->imgs->color_pix);
			x++;
		}
		y++;
	}
}

unsigned long	ft_get_pixel_color(mlx_texture_t *txt, int y, int x, int size)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	p;

	p = 4 * x + (4 * y * size);
	if (p <= txt->height * txt->width * txt->bytes_per_pixel)
	{
		r = txt->pixels[p];
		g = txt->pixels[p + 1];
		b = txt->pixels[p + 2];
		a = txt->pixels[p + 3];
		return (r << 24 | g << 16 | b << 8 | 0xFF);
	}
	return (0);
}

void	ft_redisplay(t_game *game)
{
	if (game->scene->canvas)
		mlx_delete_image(game->mlx, game->scene->canvas);
	game->scene->canvas = mlx_new_image(game->mlx, 2560, 1440);
	if (!game->scene->canvas)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(game->mlx, game->scene->canvas, 0, 0) < 0)
		ft_error(IMAGE, NULL);
	game->scene->canvas->instances[0].z = 1;
	game->scene->canvas->instances[0].z = 1;
}

int	ft_load_images(t_scene *scene, t_img *imgs)
{
	imgs->no_text = mlx_load_png(scene->no_path);
	if (!imgs->no_text)
	{
		ft_error(IMAGE, NULL);
		return (-1);
	}
	imgs->so_text = mlx_load_png(scene->so_path);
	if (!imgs->so_text)
	{
		ft_error(IMAGE, NULL);
		return (-1);
	}
	imgs->we_text = mlx_load_png(scene->we_path);
	if (!imgs->we_text)
	{
		ft_error(IMAGE, NULL);
		return (-1);
	}
	imgs->ea_text = mlx_load_png(scene->ea_path);
	if (!imgs->ea_text)
	{
		ft_error(IMAGE, NULL);
		return (-1);
	}
	return (0);
}
