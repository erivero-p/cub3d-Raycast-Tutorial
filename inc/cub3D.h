/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/24 11:59:23 by erivero-         ###   ########.fr       */
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
int	ft_read_file(t_game *info, int fd);
int	ft_char_mapcheck(char **map);
int	ft_wall_checker(char **map);

//wall_checker.c
int	ft_is_wall(char **map, int x, int y, int len);
int	ft_wall_checker(char **map);

//parse.c
void	ft_parse(t_game *info, int fd);
int		ft_arg_check(int ac, char **av);
int		ft_check_ext(char *str, char *ext);

//map_read.c
int		ft_save_info(char *ptr, char *line);
int		ft_read_info(t_map *map, char *line);
int		ft_get_map(int fd, t_map *map);
void	ft_print_map(t_map *map);
int		ft_read_file(t_game *info, int fd);

//char_checker.c
int	ft_char_mapcheck(char **map);

/*							UTILS							*/
int		ft_error(int err, char *str);
void	ft_clean(t_game	*game);



#endif