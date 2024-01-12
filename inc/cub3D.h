/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/12 11:15:06 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "cub_structs.h"
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

/*							PARSE							*/

//parse.c
int				ft_parse(t_scene *scene, int fd, char *file, t_img *img);
int				ft_arg_check(int ac, char **av);

//read_file.c
int				ft_len_file(int fd);
void			ft_read_file(t_scene *scene, int fd, int len, char *file);

//read_scene.c
int				ft_parse_file(t_scene *scene);

//get_map.c
char			**ft_get_spaced_map(char **arr, int start, int len, int max);

//scene_check.c
int				ft_check_ext(char *str, char *ext);
int				ft_scene_check(t_scene *scene);

//colour_handle.c
int				ft_color_check(char *color);

//char_check.c
int				ft_char_check(char c);
int				ft_char_mapcheck(char **map);

//ft_wall_checker.c
int				ft_wall_check(char **map, t_scene *scene);

/*							UTILS							*/

//window.c
int				ft_check_monitor(mlx_t *mlx);
void			ft_mouse(mouse_key_t k, action_t act,
					modifier_key_t mod, void *param);

//controls.c
void			ft_controls(mlx_key_data_t keydata, void *param);
void			ft_ws(t_player *player, double dir, t_game *game, float angle);
void			ft_ad(t_player *player, double dir, double ang, t_game *game);
void			ft_rotate(t_player *player, double sign, t_game *game);

//error_handling.c							
int				ft_error(int err, char *str);

//clean_handling.c
void			ft_clean_map(t_game	*info);

//load_images
int				ft_load_images(t_scene *scene, t_img *imgs);
void			ft_redisplay(t_game *game);
void			ft_draw_pixel(t_game *game);
unsigned long	ft_get_pixel_color(mlx_texture_t *texture,
					int y, int x, int size);

//candle.c
void			ft_candle(t_game *game, t_img *img);
mlx_texture_t	*ft_load_candle_text(int frame);
void			ft_night(t_game *game);

/*							RENDER							*/
//map.c
void			ft_init_map(t_game *info);
int				ft_get_map_x(t_game *info);

//paint.c
void			ft_set_minimap(t_game *info, t_scene *scene, int delete);
void			ft_fill_tile(t_game *game, int y, int x, int color);
void			ft_render_player(t_game *game, t_scene *scn, t_player *plyer);

//player.c
void			ft_init_player(t_player *player, t_game *game);
t_coord			ft_get_player_init_pos(t_game *game);
double			ft_deg_to_rad(double deg);

//raycast.c
t_coll			ft_ray_caster(t_game *info, float angle, t_coord mod);

//3Der.c
void			ft_loop_handler(void *param);

//collision.c
bool			ft_collision(t_game *info, float angle);

#endif