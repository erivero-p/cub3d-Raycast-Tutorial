#include "../../inc/cub3D.h"

void	ft_draw_col(t_game	*info, float scale, int	coll, int txt)
{
	int	j;
	int	top; //el pixel de arriba del todo del muro
	int	bot;
	int	wall; //altura del muro en píxeles?

	wall = scale;
	top = HEIGHT / 2 - wall / 2;
	bot = top + wall;
	//printf("top: %d / bot: %d\n", top, bot);
	j = 0;
	while (j < HEIGHT)
	{
		if (j <= 150 && coll <= 150)
			j = 150;
		if (j < top)
			mlx_put_pixel(info->scene->canvas, coll, j, BLUE);
		else if (j > bot)
			mlx_put_pixel(info->scene->canvas, coll, j, GREEN);
		else
		{
			if (txt == 1) // E
				mlx_put_pixel(info->scene->canvas, coll, j, PINK);
			if (txt == -1) // W
				mlx_put_pixel(info->scene->canvas, coll, j, BLACK);
			if (txt == 2) // S
				mlx_put_pixel(info->scene->canvas, coll, j, WHITE);
			if (txt == -2) // N
				mlx_put_pixel(info->scene->canvas, coll, j, RED);
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
		ft_draw_col(info, scale, i, coll.txt); // (?)
		i++;
	}
}
