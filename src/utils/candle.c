/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:00:08 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/09 14:31:31 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_candle(t_game *game, t_img *img)
{
	static int	i = 0;
	static int	sign = 1;

	//	i = 0;
	// if (i > 0)
	// 	img->candle_img[i - 1]->instances[i - 1].enabled = false;
	mlx_image_to_window(game->mlx, img->candle_img[i], 450, 350);
	img->candle_img[i]->instances[i].z = 3;
	// i += sign;
	// if (i < 1 || i > 5)
	// 	sign *= -1;
	//si me cargo las tres lineas de abajo no peta
	i++;
	if (i == 6)
		i = 0;
}

int	ft_load_candle_text(t_game *game, t_img *img)
{
	img->candle_text[0] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela1.png");
	if (!img->candle_text[0])
		return (printf("NO TEXTURA DE VELA1\n"), 1);
	img->candle_text[1] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela2.png");
	if (!img->candle_text[1])
		return (printf("NO TEXTURA DE VELA2\n"), 1);
	img->candle_text[2] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela3.png");
	if (!img->candle_text[2])
		return (printf("NO TEXTURA DE VELA3\n"), 1);
	img->candle_text[3] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela4.png");
	if (!img->candle_text[3])
		return (printf("NO TEXTURA DE VELA4\n"), 1);
	img->candle_text[4] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela5.png");
	if (!img->candle_text[4])
		return (printf("NO TEXTURA DE VELA5\n"), 1);
	img->candle_text[5] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela6.png");
	if (!img->candle_text[5])
		return (printf("NO TEXTURA DE VELA6\n"), 1);
	printf("HE CARGADO LAS TEXTURAS\n");
	if (ft_cand_text_to_img(game, img) == 1)
		return (printf("HA FALLADO LAS IMAGENES\n"), 1);
	ft_delete_candle_text(img);
	printf("HE CARGADO LAS IMAGENES\n");
	return (0);
}

int	ft_cand_text_to_img(t_game *game, t_img *img)
{
	img->candle_img[0] = mlx_texture_to_image(game->mlx, img->candle_text[0]);
	if (!img->candle_img[0])
		return (printf("NO IMAGEN DE VELA1\n"), 1);
	img->candle_img[1] = mlx_texture_to_image(game->mlx, img->candle_text[1]);
	if (!img->candle_img[1])
		return (printf("NO IMAGEN DE VELA2\n"), 1);
	img->candle_img[2] = mlx_texture_to_image(game->mlx, img->candle_text[2]);
	if (!img->candle_img[2])
		return (printf("NO IMAGEN DE VELA3\n"), 1);
	img->candle_img[3] = mlx_texture_to_image(game->mlx, img->candle_text[3]);
	if (!img->candle_img[3])
		return (printf("NO IMAGEN DE VELA4\n"), 1);
	img->candle_img[4] = mlx_texture_to_image(game->mlx, img->candle_text[4]);
	if (!img->candle_img[4])
		return (printf("NO IMAGEN DE VELA5\n"), 1);
	img->candle_img[5] = mlx_texture_to_image(game->mlx, img->candle_text[5]);
	if (!img->candle_img[5])
		return (printf("NO IMAGEN DE VELA6\n"), 1);
	return (0);
}

void	ft_delete_candle_text(t_img *img)
{
	mlx_delete_texture(img->candle_text[0]);
	mlx_delete_texture(img->candle_text[1]);
	mlx_delete_texture(img->candle_text[2]);
	mlx_delete_texture(img->candle_text[3]);
	mlx_delete_texture(img->candle_text[4]);
	mlx_delete_texture(img->candle_text[5]);
	printf("HE BORRADO LAS TEXTURAS\n");
}
