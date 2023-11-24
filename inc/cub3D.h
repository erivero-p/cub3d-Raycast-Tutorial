/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/24 16:31:48 by marirodr         ###   ########.fr       */
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

#endif