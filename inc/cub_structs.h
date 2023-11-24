/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/24 16:14:15 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_H
# define CUB_STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	mlx_texture_t	*no_text;
	mlx_texture_t	*so_text;
	mlx_texture_t	*we_text;
	mlx_texture_t	*ea_text;
	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*we_img;
	mlx_image_t		*ea_img;
}	t_img;

typedef struct s_map
{
	char	**file;
	char	**map;
	char	**aux_map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_color;
	char	*c_color;
	int		counter;
}	t_map;

typedef struct s_game
{
	mlx_t	*mlx;
	t_map	*map;
	t_img	*imgs;
}	t_game;

typedef enum e_errors
{
	ARG = 1,
	EXT_CUB, //extensión .cub
	FD, // al abrir archivo
	FORMAT, //formato del archivo
	WALL,
	CHAR,
	EMPTY,
	PLAYER, //más de uno
	EXT_PNG, //extensión .png
	
}		t_errors;

# define BLUE "\033[0;96m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"

#endif