#include "../../inc/cub3D.h"

void ft_init_pixel(t_coll *coll, int wall, t_game *info, int col, int frame)
{
	t_coord	pixel;
/* 	static int	frame = 0;

	if (col == 0)
		frame++; */
	coll->texture = NULL;
	if (coll->txt == 1) // E
		coll->texture = info->imgs->ea_text;
	else if (coll->txt == -1) // W
		coll->texture =  info->imgs->we_text;
	else if (coll->txt == 2) // S
		coll->texture =  info->imgs->so_text;
	else if (coll->txt == -2) // N
		coll->texture =  info->imgs->no_text;
	else
	{
		coll->texture = ft_homerizer(info, frame);
	//	coll->texture = info->imgs->no_text;
		coll->txt = -2; //hardcodeado
	}
	if (!coll->texture)
		exit(0);
	coll->wall = wall;
	coll->ratio = (float)coll->texture->height / coll->wall;
	if (coll->txt == 1 || coll->txt == -1) // si miré un y_cross
		coll->pixel.x = fmod(coll->collision.y, 1.0) * coll->texture->width; // * coll->ratio;
	else if (coll->txt == 2 || coll->txt == -2) // si miré un x_cross
		coll->pixel.x = fmod(coll->collision.x, 1.0) * coll->texture->width; // * coll->ratio;
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
		color = ft_get_pixel_color(coll->texture, (int)y, x, coll->texture->width);
		if (j < 0 || j > HEIGHT)
			break;
		mlx_put_pixel(info->scene->canvas, col, j, color);
		j++;
		y += coll->ratio;
	}
}

void	ft_draw_col(t_game	*info, float wall, int	col, t_coll *coll, int frame)
{
	int	j;
	int	top; //el pixel de arriba del todo del muro
	int	bot;

	top = HEIGHT / 2 - wall / 2;
	if (top < 0)
		top = 0;
	bot = top + wall;
	j = 0;
	ft_init_pixel(coll, wall, info, col, frame);
	while (j < HEIGHT)
	{
		if (j < top)
			mlx_put_pixel(info->scene->canvas, col, j, BLUE);
		else if (j > bot)
			mlx_put_pixel(info->scene->canvas, col, j, GREEN);
		j++;
	}
	ft_draw_wall(info, coll, col, top);
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
	static int	frame = 0;
	t_game	*info;
	float	scale;
	t_coll	coll;
	int		i;
	double	player_angle;
	double	rayangle;
	t_coord	mod; //me cabe esto por norminette?

	mod.x = 0;
	mod.y = 0;
	info = (t_game *)param;
	ft_redisplay(info);
	player_angle = ft_deg_to_rad(info->player->angle);
	i = 0;
	frame++;
	if (frame > 5)
		frame = 0;
	while (i < WIDTH)
	{
		rayangle = ft_rayangle(i, player_angle);
		coll = ft_ray_caster(info, rayangle, mod);
		scale = WALL_H / coll.distance;
		ft_draw_col(info, scale, i, &coll, frame); // (?)
		i++;
	}
//	printf("delta_time: %f\n", info->mlx->delta_time);
}
