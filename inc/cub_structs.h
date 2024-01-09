/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/08 13:05:01 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_H
# define CUB_STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_img
{
	mlx_texture_t		*no_text;
	mlx_texture_t		*so_text;
	mlx_texture_t		*we_text;
	mlx_texture_t		*ea_text;
	int					size;
	long unsigned int	color_pix;
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
	int			floor; //color en hexadecimal
	int			ceiling; //color en hexadecimal
	int			counter;
	int			len_x;
	int			len_y;
	mlx_image_t	*canvas;
	mlx_image_t	*mini;
	float		tile; //dimension de la celda
	float		mini_x;
	float		mini_y;
}	t_scene;

typedef struct s_player
{
	t_coord		*pos;
	t_coord		*center;
	mlx_image_t	*player_img; //->para igualar a s_game->mlx 
	mlx_image_t	*line_img; //->para igualar a s_game->mlx 
	mlx_t		*mlx; //->para igualar a s_game->mlx
	int			color;
	double		mov_speed;
	double		rot_speed;
	float		angle; //(?)
	int			size;
}	t_player;

typedef	struct s_ray
{
//	bool	coll; //colisión
	double	angle; // en grados, rayangle
	double	deltaang; // en radianes, playerangle - rayangle
	t_coord	origin;
	t_coord	dir; //dirección del rayo
	t_coord	x_cross; //tamaño de cada paso a aumentar en busca de una colisión
	t_coord	y_cross; //tamaño de cada paso a aumentar en busca de una colisión
	t_coord	sgn; //para el signo según la dirección
	t_coord	coll; //punto de colisión real
	//int		txt; //textura: 1 E -1 W 2 S -2 N
	double	len;
}	t_ray;

typedef	struct	s_coll
{
	t_coord	collision; //punto de colisión real
	double	raylen;
	double	distance;
	int		txt; //texture: 1 E -1 W 2 S -2 N
	mlx_texture_t	*texture;
	t_coord	pixel; //el pixel en el que empiezo a cargar la textura
	int		wall;
	float	ratio;
}	t_coll;

/* typedef	struct	s_draw
{
	t_coord	pixel; //pixel inicial
	float	ratio; //relación de aspecto textura:muro
} */


typedef	struct s_homer
{
	mlx_texture_t *h0;
	mlx_texture_t *h1;
	mlx_texture_t *h2;
	mlx_texture_t *h3;
	mlx_texture_t *h4;
	mlx_texture_t *h5;
	mlx_texture_t *h6;
	mlx_texture_t *h7;
}	t_homer;

typedef struct s_game
{
	mlx_t		*mlx;
	t_scene		*scene;
	t_img		*imgs;
	t_player	*player;
	t_ray		*ray;
	t_homer		*homer;
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
	COLOR, //formato rgb
	WINDOW, //fallo al abrir la ventana
	IMAGE, //fallo al abrir la ventana
}		t_errors;

# define DEBUG_COLOR "\033[0;96m"
# define DEBUG2 "\033[95m"
# define GOOD "\033[0;32m"
# define WRONG "\033[0;31m"
# define END "\033[0m"

# define WIDTH 1080
# define HEIGHT 720
# define WALL_H 500 // altura del muro, puse eso por probar xd
# define WALL_W 500 // ancho del muro, puse eso por probar xd
# define FOV 90 // campo de visión

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define BLUE 0xADD8E6
# define PINK 0xFFC0CBFF
# define RED 0xFF0000FF
# define GREEN 0x007F007F
# define TRANSP 0xFF000000

//si BONUS no está definido porque no se ha usado la regla 'make bonus' al compilar se define como 0. En caso contrario, entonces la definición en el Makefile tiene prioridad y BONUS se define como 1.
# ifndef BONUS
#  define BONUS 0
# endif

#endif