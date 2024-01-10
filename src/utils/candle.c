/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:00:08 by erivero- De       #+#    #+#             */
/*   Updated: 2024/01/10 10:53:09 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_candle(t_game *game, t_img *img)
{
	static int		i = -5;
	static int		count = 0;
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

mlx_texture_t	*ft_load_candle_text(int frame)
{
	mlx_texture_t	*txt;

	txt = NULL;
	if (frame == 0)
		txt = mlx_load_png("./texturas/vela1.png");
	else if (frame == 1 || frame == -1)
		txt = mlx_load_png("./texturas/vela2.png");
	else if (frame == 2 || frame == -2)
		txt = mlx_load_png("./texturas/vela3.png");
	else if (frame == 3 || frame == -3)
		txt = mlx_load_png("./texturas/vela4.png");
	else if (frame == 4 || frame == -4)
		txt = mlx_load_png("./texturas/vela5.png");
	else if (frame == 5 || frame == -5)
		txt = mlx_load_png("./texturas/vela6.png");
	if (!txt)
		ft_error(IMAGE, NULL);
	return (txt);
}
