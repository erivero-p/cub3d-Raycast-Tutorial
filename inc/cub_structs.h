/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/10 16:31:31 by erivero-         ###   ########.fr       */
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
	mlx_texture_t		*candle_text[6];
	mlx_image_t			*candle_img;
	int					size;
	long unsigned int	color_pix;
}	t_img;

//f_color y c_color son los char * al color en rgb
//floor y ceiling son en hexadecimal
typedef struct s_scene
{
	char		**file;
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	int			floor;
	int			ceiling;
	int			counter;
	int			len_x;
	int			len_y;
	mlx_image_t	*canvas;
	mlx_image_t	*mini;
	float		tile;
	float		mini_x;
	float		mini_y;
}	t_scene;

typedef struct s_player
{
	t_coord		*pos;
	t_coord		*center;
	mlx_image_t	*player_img;
	mlx_image_t	*line_img;
	mlx_t		*mlx;
	int			color;
	double		mov_speed;
	double		rot_speed;
	int			angle; //(?)
	int			size;
}	t_player;

/*	angle: ángulo del rayo en grados
	deltaang: playerangle - rayangle (radianes) 
	dir: vector direccional del rayo
	x/y_cross: tamaño del paso a aumentar en busca de colisión
	sgn: signo según la dirección
	coll: punto de colisión real
	*/
typedef struct s_ray
{
	double	angle;
	double	deltaang;
	t_coord	origin;
	t_coord	dir;
	t_coord	x_cross;
	t_coord	y_cross;
	t_coord	sgn;
	t_coord	coll;
	double	len;
}	t_ray;

/*	txt: textura 1 E -1 W 2 S -2 N
	pixel: pixel donde empezar a pintar columna
	wall: tamaño de la pared
	ratio: relación textura / pared
 */
typedef struct s_coll
{
	t_coord			collision;
	double			raylen;
	double			distance;
	int				txt;
	mlx_texture_t	*texture;
	t_coord			pixel;
	int				wall;
	float			ratio;
}	t_coll;

typedef struct s_game
{
	mlx_t		*mlx;
	t_scene		*scene;
	t_img		*imgs;
	t_player	*player;
	t_ray		*ray;
}	t_game;

/* errores:
	ARG = error de argumentos
	EXT_CUB: extensión .cub
	FD:  al abrir archivo
	FORMAT: formato del archivo
	WALL,
	CHAR,
	EMPTY,
	PLAYER: 0 o más de 1 personaje
	EXT_PNG: extensión .png
	COLOR: formato rgb
	WINDOW: fallo al abrir la ventana
	IMAGE: fallo al cargar imagen */

typedef enum e_errors
{
	ARG = 1,
	EXT_CUB,
	FD,
	FORMAT,
	WALL,
	CHAR,
	EMPTY,
	PLAYER,
	EXT_PNG,
	COLOR,
	WINDOW,
	IMAGE,
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

//si BONUS no está definido porque no se ha usado
// la regla 'make bonus' al compilar se define como 0. 
//En caso contrario, entonces la definición en el Makefile tiene prioridad 
// y BONUS se define como 1.
# ifndef BONUS
#  define BONUS 0
# endif

#endif