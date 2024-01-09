/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:00:08 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/09 16:54:31 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_candle(t_game *game, t_img *img)
{
	static int	i = -5;
	static int	count = 0;
	mlx_texture_t	*txt;

	txt = ft_load_candle_text(i);
	if (img->candle_img != NULL)
		mlx_delete_image(game->mlx, img->candle_img);
	img->candle_img = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	mlx_image_to_window(game->mlx, img->candle_img, 450, 300);
	img->candle_img->instances[0].z = 3;
	if (i == 5)
		i = -5;
	count++;
	if (count % 3 == 0)
		i++;
}

mlx_texture_t *ft_load_candle_text(int frame)
{
	mlx_texture_t *txt;

	txt = NULL;
	if (frame == 0)
		txt = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela1.png");
	else if (frame == 1 || frame == -1)
		txt = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela2.png");
	else if (frame == 2 || frame == -2)
		txt = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela3.png");
	else if (frame == 3 || frame == -3)
		txt = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela4.png");
	else if (frame == 4 || frame == -4)
		txt = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela5.png");
	else if (frame == 5 || frame == -5)
		txt = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela6.png");
	if (!txt)
		printf("NO TEXTURA VELA\n");
	return (txt);
}

// int	ft_load_candle_text(t_game *game, t_img *img)
// {
// 	img->candle_text[0] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela1.png");
// 	if (!img->candle_text[0])
// 		return (printf("NO TEXTURA DE VELA1\n"), 1);
// 	img->candle_text[1] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela2.png");
// 	if (!img->candle_text[1])
// 		return (printf("NO TEXTURA DE VELA2\n"), 1);
// 	img->candle_text[2] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela3.png");
// 	if (!img->candle_text[2])
// 		return (printf("NO TEXTURA DE VELA3\n"), 1);
// 	img->candle_text[3] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela4.png");
// 	if (!img->candle_text[3])
// 		return (printf("NO TEXTURA DE VELA4\n"), 1);
// 	img->candle_text[4] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela5.png");
// 	if (!img->candle_text[4])
// 		return (printf("NO TEXTURA DE VELA5\n"), 1);
// 	img->candle_text[5] = mlx_load_png("/Users/marirodr/cursus/cub3d/texturas/vela6.png");
// 	if (!img->candle_text[5])
// 		return (printf("NO TEXTURA DE VELA6\n"), 1);
// 	printf("HE CARGADO LAS TEXTURAS\n");
// 	// if (ft_cand_text_to_img(game, img) == 1)
// 	// 	return (printf("HA FALLADO LAS IMAGENES\n"), 1);
// 	// ft_delete_candle_text(img);
// 	// printf("HE CARGADO LAS IMAGENES\n");
// 	return (0);
// }

// int	ft_cand_text_to_img(t_game *game, t_img *img)
// {
// 	img->candle_img[0] = mlx_texture_to_image(game->mlx, img->candle_text[0]);
// 	if (!img->candle_img[0])
// 		return (printf("NO IMAGEN DE VELA1\n"), 1);
// 	img->candle_img[1] = mlx_texture_to_image(game->mlx, img->candle_text[1]);
// 	if (!img->candle_img[1])
// 		return (printf("NO IMAGEN DE VELA2\n"), 1);
// 	img->candle_img[2] = mlx_texture_to_image(game->mlx, img->candle_text[2]);
// 	if (!img->candle_img[2])
// 		return (printf("NO IMAGEN DE VELA3\n"), 1);
// 	img->candle_img[3] = mlx_texture_to_image(game->mlx, img->candle_text[3]);
// 	if (!img->candle_img[3])
// 		return (printf("NO IMAGEN DE VELA4\n"), 1);
// 	img->candle_img[4] = mlx_texture_to_image(game->mlx, img->candle_text[4]);
// 	if (!img->candle_img[4])
// 		return (printf("NO IMAGEN DE VELA5\n"), 1);
// 	img->candle_img[5] = mlx_texture_to_image(game->mlx, img->candle_text[5]);
// 	if (!img->candle_img[5])
// 		return (printf("NO IMAGEN DE VELA6\n"), 1);
// 	return (0);
// }

// void	ft_delete_candle_text(t_img *img)
// {
// 	mlx_delete_texture(img->candle_text[0]);
// 	mlx_delete_texture(img->candle_text[1]);
// 	mlx_delete_texture(img->candle_text[2]);
// 	mlx_delete_texture(img->candle_text[3]);
// 	mlx_delete_texture(img->candle_text[4]);
// 	mlx_delete_texture(img->candle_text[5]);
// 	printf("HE BORRADO LAS TEXTURAS\n");
// }
