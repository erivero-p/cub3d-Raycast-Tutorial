/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:20:33 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/20 12:03:17 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
