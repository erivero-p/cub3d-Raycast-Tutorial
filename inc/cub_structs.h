/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 13:08:41 by marirodr         ###   ########.fr       */
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

typedef struct s_scene
{
	char		**file;
	char		**map;
	char		**aux_map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	int			counter;
	int			len_x;
	int			len_y;
	mlx_image_t	*img;
	float		limit;
	float		w;
	float		h;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_scene		*scene;
	t_img		*imgs;
	mlx_image_t	*canvas; //esta mierda es solo para testear
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
	WINDOW, //fallo al abrir la ventana
	IMAGE, //fallo al abrir la ventana
}		t_errors;

# define CYAN "\033[0;96m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"

# define WIDTH 1080
# define HEIGHT 720

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define BLUE 0xADD8E6
# define PINK 0xFFC0CBFF

#endif