/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:20:33 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:28 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_draw_pixel(t_game *game)
{
	long unsigned int	color_pix;
	int	pixel_y;
	int	pixel_x;

	pixel_y = 0;
	pixel_x = 0;
	while (pixel_y < 64)
	{
		pixel_x = 0;
		while (pixel_x < 64)
		{
			color_pix = ft_get_pixel_color(game->imgs->ea_text, pixel_y, pixel_x);
			mlx_put_pixel(game->scene->canvas, pixel_x + 300, pixel_y + 300, color_pix);
			pixel_x++;
		}
		pixel_y++;
	}
}

unsigned long	ft_get_pixel_color(mlx_texture_t *texture, int y, int x)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	p;

	p = 4 * x + (4 * y * 64);
	r = texture->pixels[p];
	g = texture->pixels[p + 1];
	b = texture->pixels[p + 2];
	a = texture->pixels[p + 3];
	return (r << 24 | g << 16 | b << 8 | 0xFF); //a = 0xFF?
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
	game->scene->canvas->instances[0].z = 0;
}

void	ft_load_images(t_game *game)
{
	game->imgs->no_text = mlx_load_png(game->scene->no_path);
	if (!game->imgs->no_text)
		ft_error(IMAGE, NULL);
	game->imgs->so_text = mlx_load_png(game->scene->so_path);
	if (!game->imgs->so_text)
		ft_error(IMAGE, NULL);
	game->imgs->we_text = mlx_load_png(game->scene->we_path);
	if (!game->imgs->we_text)
		ft_error(IMAGE, NULL);
	game->imgs->ea_text = mlx_load_png(game->scene->ea_path);
	if (!game->imgs->we_text)
		ft_error(IMAGE, NULL);
}

void	ft_delete_text(t_game *game)
{
	mlx_delete_texture(game->imgs->no_text);
	mlx_delete_texture(game->imgs->so_text);
	mlx_delete_texture(game->imgs->we_text);
	mlx_delete_texture(game->imgs->ea_text);
}
