/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 11:47:25 by marirodr         ###   ########.fr       */
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
void	ft_init(t_game *info);
int		ft_parse(t_game *info, int fd, char *file);
int		ft_arg_check(int ac, char **av);

//map_read.c
int		ft_parse_file(t_map *map);
//int		ft_parse_file(t_game *info);

//char_check.c
int		ft_char_check(char c);
int		ft_char_mapcheck(char **map);

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
void	ft_print_map(t_map *map);
void 	ft_print_matrix(char **matrix, int test);


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
void	ft_paint_minimap(void *param);

#endif