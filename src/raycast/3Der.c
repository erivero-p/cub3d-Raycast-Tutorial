#include "../../inc/cub3D.h"

float 	ft_scalator(t_game *info, float angle)
{
	float	scale;
	float	len; //distancia al plano de proyección. Es fija
	float	distance; //distancia real al rayo
	float	deltang; //ángulo entre el rayo y el vector de dirección

	len = (WIDTH / 2) / tan(ft_deg_to_rad(angle));
	deltang = info->player->angle - angle;
	distance = ft_raycaster(info, angle) * cos(ft_deg_to_rad(deltang));
	scale = WALL_H / distance * len;
	return (scale);
}

void	ft_draw_coll(t_game	*info, float scale, int	coll)
{
	int	j;
	int	top; //el pixel de arriba del todo del muro
	int	wall; //altura del muro en píxeles?

	wall = WALL_H / scale; //digo yo que la pared mide en píxeles su altura entre la escala
	top = HEIGHT / 2 - wall / 2;
	while (j < HEIGHT)
	{
		//cuando j sea top habrá que empezar a pintar muro
		//cuando j sea top + wall habrá que dejar de pintar muro
		j++;
	}
}

void	ft_3Der(t_game *info)
{
	float	angle;
	float	a;
	float	scale;
	int		i;
	int		j;

	angle = info->player->angle - (FOV / 2); //empezamos a lanzar desde -45 y hasta +45
	a = WIDTH / FOV; //lo que tengo que aumentar el ángulo en cada iteración
	i = 0;
	if (angle < 0)
		angle += 360;
	while (i < WIDTH)
	{
		scale = ft_scalator(info, angle);
		ft_draw_coll(info, scale, i); // (?)
		i++;
		angle += a;
		if (angle > 359)
			angle -= 360;
	}
}
