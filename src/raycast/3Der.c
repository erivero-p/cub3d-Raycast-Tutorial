#include "../../inc/cub3D.h"

void ft_init_pixel(t_coll *coll, int wall, t_game *info)
{
	t_coord	pixel;

	if (coll->txt == 1 || coll->txt == -1) // si miré un y_cross
		coll->pixel.x = fmod(coll->collision.y, 1.0) * coll->texture->width; //es por el ancho de la textura en vdd
	else if (coll->txt == 2 || coll->txt == -2) // si miré un x_cross
		coll->pixel.x = fmod(coll->collision.x, 1.0) * coll->texture->width;
	coll->pixel.y = 0;
	if (wall > HEIGHT)
		coll->pixel.y += (wall - HEIGHT) / 2;
	if (coll->txt == 1) // E
		coll->texture = info->imgs->ea_text;
	if (coll->txt == -1) // W
		coll->texture =  info->imgs->we_text;
	if (coll->txt == 2) // S
		coll->texture =  info->imgs->so_text;
	if (coll->txt == -2) // N
		coll->texture =  info->imgs->no_text;
}

/* void ft_copy_texture_pixels(t_game *all, int i, int j, mlx_texture_t *texture, float pos_modifier)
{
	float scale = WALL_H / all->window->dist.projy;
	float scale_texture = texture->height / scale;
	float pos = fmod(pos_modifier, 1.0);
	pos = pos * texture->width;
	pos = pos - fmod(pos, 1.0);

	int n = (int)(scale_texture * (j - (HEIGHT / 2 - scale / 2)));
	int k = 0;
	while (k < texture->bytes_per_pixel)
	{
		all->window->g_img-> [WIDTH * j * 4 + (i) * 4 + k] =
			texture->pixels[texture->width * n * texture->bytes_per_pixel + (int)pos * texture->bytes_per_pixel + k];
		k++;
	}
} */

void	ft_draw_col(t_game	*info, float wall, int	col, t_coll *coll)
{
	int	j;
	int	top; //el pixel de arriba del todo del muro
	int	bot;

	top = HEIGHT / 2 - wall / 2;
	bot = top + wall;
	j = 0;

	ft_init_pixel(coll, wall, info);
	int x = col;
/* 	int	x = (int)coll->pixel.x;
	int	y = (int)coll->pixel.y; */
	int y = 0;
	while (j < HEIGHT)
	{
		if (j < top)
			mlx_put_pixel(info->scene->canvas, col, j, BLUE);
		else if (j > bot)
			mlx_put_pixel(info->scene->canvas, col, j, GREEN);
		if (j >= top && j <= bot)
		{
			unsigned long color = ft_get_pixel_color(coll->texture, y, x, coll->texture->width);
 //			if (color > 0)
			mlx_put_pixel(info->scene->canvas, col, j, color);
			y++;
		}
		j++;
	}
}

double	ft_rayangle(int	i, double angle)
{
	int	sine;
	int	cosine;
	double	rayangle;

	sine = (WIDTH / 2) / tan(ft_deg_to_rad(FOV / 2)); //esta es la distancia del personaje al plano de proyección
	if (i < WIDTH / 2) //si el rayo está a la izda del vector direccional del personaje
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

void	ft_3Der(void *param)
{
	t_game	*info;
	float	scale;
	t_coll	coll;
	int		i;
	double	player_angle;
	double	rayangle;

	info = (t_game *)param;
	ft_redisplay(info);
	player_angle = ft_deg_to_rad(info->player->angle);
	i = 0;

	while (i < WIDTH)
	{
		rayangle = ft_rayangle(i, player_angle);
		coll = ft_ray_caster(info, rayangle);
		scale = WALL_H / coll.distance;
		ft_draw_col(info, scale, i, &coll); // (?)
		i++;
	}
}
