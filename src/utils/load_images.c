/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:20:33 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/08 19:03:38 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_draw_pixel(t_game *game)
{
	int	pixel_y;
	int	pixel_x;

	pixel_y = 0;
	pixel_x = 0;
	game->imgs->size = 64;
	while (pixel_y < game->imgs->size)
	{
		pixel_x = 0;
		while (pixel_x < game->imgs->size)
		{
			game->imgs->color_pix = ft_get_pixel_color(game->imgs->no_text, pixel_y, pixel_x, game->imgs->size);
			mlx_put_pixel(game->scene->canvas, pixel_x + 300, pixel_y + 300, game->imgs->color_pix); //300 es la posicion donde se quiere dibujar, es decir la pared
			pixel_x++;
		}
		pixel_y++;
	}
}

unsigned long	ft_get_pixel_color(mlx_texture_t *texture, int y, int x, int size)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	p;

	p = 4 * x + (4 * y * size);
	if (p <= texture->height * texture->width * texture->bytes_per_pixel)
	{
		r = texture->pixels[p];
		g = texture->pixels[p + 1];
		b = texture->pixels[p + 2];
		a = texture->pixels[p + 3];
		return (r << 24 | g << 16 | b << 8 | 0xFF);
	}
	return (0);
}

void	ft_redisplay(t_game *game)
{
	if (game->scene->canvas)
		mlx_delete_image(game->mlx, game->scene->canvas);
	game->scene->canvas = mlx_new_image(game->mlx, 2560, 1440); //para poder rendear las imagenes, cómo crear un lienzp donde poder dibujar pixeles
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

void	ft_delete_text(t_game *game)
{
	if (game->imgs->no_text)
		mlx_delete_texture(game->imgs->no_text);
	if (game->imgs->so_text)
		mlx_delete_texture(game->imgs->so_text);
	if (game->imgs->we_text)
		mlx_delete_texture(game->imgs->we_text);
	if (game->imgs->ea_text)
		mlx_delete_texture(game->imgs->ea_text);
}
