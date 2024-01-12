/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Der.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:32:00 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/12 14:00:25 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"
/*	ft_init_pixel decide qué textura cargar en función
	de la orientación(1 E, -1 W, 2 S, -2 N)
	y setea el primer pixel a tomar de esa textura:
	En x, será donde colisiona el rayo, si es una colisión
	transversal (x_cross), tomará el flotante en x
	si es colisión longitudinal (y_cross), tomará el flotante en y
	En ambos casos se multiplica por el ancho de la textura
	En y, será 0 salvo que la pared exceda el alto de la ventana  */

void	ft_init_pixel(t_coll *coll, int wall, t_game *info)
{
	t_coord	pixel;

	if (coll->txt == 1)
		coll->texture = info->imgs->ea_text;
	else if (coll->txt == -1)
		coll->texture = info->imgs->we_text;
	else if (coll->txt == 2)
		coll->texture = info->imgs->so_text;
	else if (coll->txt == -2)
		coll->texture = info->imgs->no_text;
	coll->wall = wall;
	coll->ratio = (float)coll->texture->height / coll->wall;
	if (coll->txt == 1 || coll->txt == -1)
		coll->pixel.x = fmod(coll->collision.y, 1.0) * coll->texture->width;
	else if (coll->txt == 2 || coll->txt == -2)
		coll->pixel.x = fmod(coll->collision.x, 1.0) * coll->texture->width;
	coll->pixel.y = 0;
	if (wall > HEIGHT)
		coll->pixel.y += (float)((wall - HEIGHT) / 2 * coll->ratio);
}

void	ft_draw_wall(t_game *info, t_coll *coll, int col, int j)
{
	unsigned long	color;
	float			y;
	int				x;

	y = coll->pixel.y;
	x = (int)coll->pixel.x;
	while ((int)y < coll->texture->height && j < HEIGHT / 2 + coll->wall / 2)
	{
		color = \
		ft_get_pixel_color(coll->texture, (int)y, x, coll->texture->width);
		if (j < 0 || j > HEIGHT)
			break ;
		mlx_put_pixel(info->scene->canvas, col, j, color);
		j++;
		y += coll->ratio;
	}
}

void	ft_draw_col(t_game	*info, float wall, int col, t_coll *coll)
{
	int	j;
	int	top;
	int	bot;

	top = HEIGHT / 2 - wall / 2;
	if (top < 0)
		top = 0;
	bot = top + wall;
	j = 0;
	ft_init_pixel(coll, wall, info);
	while (j < HEIGHT)
	{
		if (j < top)
			mlx_put_pixel(info->scene->canvas, col, j, info->scene->ceiling);
		else if (j > bot)
			mlx_put_pixel(info->scene->canvas, col, j, info->scene->floor);
		j++;
	}
	ft_draw_wall(info, coll, col, top);
}

double	ft_rayangle(int i, double angle)
{
	int		sine;
	int		cosine;
	double	rayangle;

	sine = (WIDTH / 2) / tan(ft_deg_to_rad(FOV / 2));
	if (i < WIDTH / 2)
	{
		cosine = WIDTH / 2 - i;
		rayangle = angle - atan2(cosine, sine);
	}
	else
	{
		cosine = i - WIDTH / 2;
		rayangle = angle + atan2(cosine, sine);
	}
	if (rayangle < 0)
		rayangle += (M_PI * 2);
	if (rayangle > M_PI * 2)
		rayangle -= (M_PI * 2);
	return (rayangle * 180.0 / M_PI);
}

void	ft_loop_handler(void *param)
{
	t_game	*info;
	t_coll	coll;
	int		i;
	double	player_angle;
	t_coord	mod;

	mod.x = 0;
	mod.y = 0;
	info = (t_game *)param;
	ft_redisplay(info);
	player_angle = ft_deg_to_rad(info->player->angle);
	i = 0;
	while (i < WIDTH)
	{
		coll = ft_ray_caster(info, ft_rayangle(i, player_angle), mod);
		ft_draw_col(info, WALL_H / coll.distance, i, &coll);
		i++;
	}
}
