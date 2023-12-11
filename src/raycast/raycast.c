#include "../../inc/cub3D.h"

ft_init_ray(t_ray *ray, double angle)
{
	ray->col = false;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->step.y = 1; //no es 1, es el alto de la casilla xd
}

void	ft_ray_caster(t_ray *ray)
{
	while (!ray->col)
	{

	}
}