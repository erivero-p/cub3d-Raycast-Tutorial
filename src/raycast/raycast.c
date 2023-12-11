#include "../../inc/cub3D.h"
#include <stdbool.h>

void 	ft_print_ray(t_ray *ray)
{
	if (!ray->coll)
	{
		printf("before collision, ray parameters are:\n");
		printf("origin.x: %d, origin.y: %d\n", ray->origin.x, ray->origin.y);
		printf("dir.x: %d, dir.y: %d\n", ray->dir.x, ray->dir.y);
		printf("x_cross.x: %d, x_cross.y: %d\n", ray->x_cross.x, ray->x_cross.y);
		printf("y_cross.x: %d, y_cross.y: %d\n", ray->y_cross.x, ray->y_cross.y);
	}
}

void	ft_init_ray(t_ray *ray, t_game *info, double angle)
{
	ray->coll = false;
//	ray->origin.x = info->player->pos_map->x;
//	ray->origin.y = info->player->pos_map->y;
	ray->origin.x = (double)3.5;
	ray->origin.y = (double)2.5;
	ft_printf("holi?\n");
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->x_cross.x = 1 / tan(angle);
	ray->x_cross.y = 1; // (alto del info->scene->tile)
	ray->y_cross.x = 1; // (ancho del info->scene->tile)
	ray->y_cross.y = 1 / tan(angle);
}
bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info)
{
	t_coord	coord;
	char **map;
/* 	coord.x = (int)pos.x / info->scene->tile; 
	coord.y = (int)pos.y / info->scene->tile; 
	No sé si hace falta dividir pq no sé si a estas alturas la posición
	está en coordenadas o en píxeles xd */
	map = info->scene->map;
	if (ray->dir.x < 0) //si el coseno es negativo mira pa la izquierda
		coord.x -= 1;
	if(ray->dir.y > 0) //si el seno es negativo mira hacia arriba
		coord.y -= 1;
	if (map[coord.y][coord.x] == '1')
		return (true);
	return (false);
}

double	ft_cross_checker(t_ray *ray, t_coord step, t_game *info)
{
	t_coord	pos;
	t_coord	cateto;
	double	distance;

	pos.x = ray->origin.x;
	pos.y = ray->origin.y;
//el primer paso que es más chiquito:
	pos.x += (step.x - step.x % 1);
	pos.y += (step.y - step.y % 1);
	while (1)
	{
		ray->coll = ft_coll_checker(pos, ray, info);
		if (ray->coll)
			break ;
		pos.x += step.x;
		pos.y += step.y;
	}
	printf("collision on: (%d, %d)\n", pos.y, pos.x);
	cateto.x = pos.x - ray->origin.x;
	cateto.y = pos.y - ray->origin.y;
	distance = sqrt(pow(cateto.x, 2) + pow(cateto.y, 2));
	return (distance);
}

double	ft_ray_caster(t_game *info)
{
	double	x_len;
	double	y_len;
	t_ray	ray;

//	ft_init_ray(&ray, info, info->player->angle);
	ft_init_ray(&ray, info, 270 * M_PI / 180.0); //hard codeado, el pj supuestamente mira al norte (270º a radianes)
	ft_print_ray(&ray);
	x_len = ft_cross_checker(&ray, ray.x_cross, info);
	y_len = ft_cross_checker(&ray, ray.y_cross, info);
	if (x_len < y_len)
		return (x_len);
	else
		return (y_len);
}