#include "../../inc/cub3D.h"

float 	ft_scalator_supremexd()
{
	float	scale;
	float	distance;

	distance = (WIDTH / 2) / tan(45); //45 hay que pasarlo a radianes pero bueno xd
	scale = TILE / ft_raycaster() * distance;//el alto del tile está sin definir
	return (scale);
}

void	ft_fantastic_3Der(t_game *info)
{
	float	angle;
	float	a;
	float	scale;
	int		i;
	int		j;

	angle = info->player->angle - 45; //empezamos a lanzar desde -45 y hasra +45
	a = 1080 / 90; //lo que tengo que aumentar el ángulo en cada iteración
	i = 0;
	if (angle < 0)
		angle += 360;
	while (i < 1080)
	{
		scale = ft_scalator_supremexd();
		i++;
		angle += a;
		if (angle > 359)
			angle -= 360;
	}
}
