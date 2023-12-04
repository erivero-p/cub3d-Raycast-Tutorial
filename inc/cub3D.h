/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/04 10:26:23 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "cub_structs.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*							PARSE							*/

//parse.c
int		ft_parse(t_scene *scene, int fd, char *file);
int		ft_arg_check(int ac, char **av);

//read_file.c
int		ft_len_file(int fd);
void	ft_read_file(t_scene *scene, int fd, int len, char *file);

//read_scene.c
int		ft_parse_file(t_scene *scene);

//get_map.c
char **ft_get_spaced_map(char **arr, int start, int len, int max);

//scene_check.c
int		ft_scene_check(t_scene *scene);
//colour_handle.c
int		ft_color_check(char *color);


//char_check.c
int		ft_char_check(char c);
int		ft_char_mapcheck(char **map);

//ft_wall_checker.c
int	ft_wall_check(char **map, t_scene *scene);

//format.c
int		ft_check_ext(char *str, char *ext);

/*							UTILS							*/
//error_handling.c							
int		ft_error(int err, char *str);

//clean_handling.c
void	ft_clean_map(t_game	*info);


//init.c
void   ft_init_map_struct(t_game *info);

//error_handling.c
int     ft_error(int err, char *str);

//debug.c
void	ft_print_scene(t_scene *scene, char *colour);
void 	ft_print_matrix(char **matrix, char *colour);


/*							SETTINGS							*/
//window.c
int	    ft_check_monitor(mlx_t *mlx);
void	ft_resize(void *param);

//controls.c
void	ft_controls(mlx_key_data_t keydata, void *param);

/*							MAP							*/
//map.c
void	ft_init_map(t_game *info);
int     ft_get_map_x(t_game *info);
void	ft_paint_minimap(t_game *info, t_scene *scene);

#endif