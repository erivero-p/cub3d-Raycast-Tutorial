/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/27 16:31:28 by erivero-         ###   ########.fr       */
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
void	ft_parse(t_game *info, int fd, char *file);
int		ft_arg_check(int ac, char **av);

//map_read.c
int		ft_parse_file(t_map *map);

//char_check.c
int		ft_char_check(char c);
int		ft_char_mapcheck(char **map);

//format.c
int		ft_check_ext(char *str, char *ext);

/*							UTILS							*/
int		ft_error(int err, char *str);
void	ft_clean(t_game	*game);

//init.c
t_map   *ft_init_map_struct(t_game *info);

//error_handling.c
void	ft_print_map(t_map *map);
int     ft_error(int err, char *str);
void	ft_print_matrix(char **matrix);

/*							SETTINGS							*/
//window.c
int	ft_check_monitor(mlx_t *mlx);
void	ft_resize(void *param);

//controls.c
void	ft_controls(mlx_key_data_t keydata, void *param);

#endif