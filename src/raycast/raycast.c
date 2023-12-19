#include "../../inc/cub3D.h"

void	ft_init_ray(t_ray *ray, t_game *info, double angle)
{
	int	sn;

	sn = 1;
	ray->coll = false;
//	ray->origin.x = info->player->pos_map->x;
//	ray->origin.y = info->player->pos_map->y;
	ray->origin.x = 3.5;
	ray->origin.y = 3.5;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->sgn.x = 1;
	ray->sgn.y = 1;
	if (ray->dir.x < 0)
		ray->sgn.x *= -1;
	if (ray->dir.y < 0)
		ray->sgn.y *= -1;
	ray->x_cross.x = ray->sgn.x / tan(angle);
	ray->x_cross.y = ray->sgn.y;
	ray->y_cross.x = ray->sgn.x;
	ray->y_cross.y = tan(angle);
}

bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info)
{
	char **map;
	int		j;
	int		i;

	map = info->scene->map;
	coord.x = (int)pos.x;
	coord.y = (int)pos.y;
//	printf("coord.y = %d, coord.x = %d\n", pos.y, pos.x);
	if (ray->dir.x < 0) //si el coseno es negativo mira pa la izquierda, 
		x *= -1; //así que debo checkear la celda de la izda a la que estoy
	if(ray->dir.y < 0) //si el seno es negativo mira hacia arriba
		y *= -1; //así que debo checkear la celda de arriba
	// if (map[coord.y + y][coord.x + x] == '1')
	// 	return (true);
//	printf("col_checker pos.x: %d, pos.y: %d\n", pos.x, pos.y);
	j = (int)pos.y + (int)ray->sgn.y; //esto es para sumarle o restarle 1 en función de si mira arriba o abajo
	i = (int)pos.x + (int)ray->sgn.x; //no sé hasta qué punto es necesario ahora mismo
	if (map[j][i] == '1')
		return (true);
	return (false);
}

t_coord	ft_first_step(t_coord	origin, t_coord	step)
{
	t_coord	pos;

	if (step.x != 0)
		pos.x = (int)origin.x + step.x;
	else
		pos.x = origin.x;
	if (step.y != 0)
		pos.y = (int)origin.y + step.y;
	else
		pos.y = origin.y;
	return (pos);
}

double	ft_cross_checker(t_ray *ray, t_coord step, t_game *info)
{
	t_coord	pos;
	t_coord	cateto;
	double	distance;

	pos.x = ray->origin.x;
	pos.y = ray->origin.y;
//el primer paso que es más chiquito:
	// pos.x += (step.x - step.x % 1);
	// pos.y += (step.y - step.y % 1);
//	printf("%safter first step, pos.x: %d, pos.y: %d\n%s", WRONG, pos.x, pos.y, END);
	while (1)
	{
		printf("position checked: pos.x (%f), pos.y(%f)\n", pos.x, pos.y);
	pos = ft_first_step(ray->origin, step);
	while (1)
	{
		printf("position checked: pos.x (%d), pos.y(%d)\n", (int)pos.x, (int)pos.y);
		ray->coll = ft_coll_checker(pos, ray, info);
		if (ray->coll)
			break ;
		pos.x += step.x;
		pos.y += step.y;
	}
	printf("%scollision on: (%f, %f)%s\n", GOOD, pos.y, pos.x, END);
	cateto.x = pos.x - ray->origin.x;
	cateto.y = pos.y - ray->origin.y;
	distance = sqrt(pow(cateto.x, 2) + pow(cateto.y, 2));
	return (distance);
}

double	ft_ray_caster(t_game *info, float angle)
{
	double	len;
	t_ray	ray;

//	ft_init_ray(&ray, info, info->player->angle);
//	double	angle = 45;
	ft_init_ray(&ray, info, angle); // * M_PI / 180.0); //hard codeado, el rayo supuestamente mira al norte
	ft_print_ray(&ray, "\033[95m"); //purple
	if (angle > 45 && angle < 135 || angle > 225 && angle < 315)
		len = ft_cross_checker(&ray, ray.x_cross, info);
	else
	{
		printf("holi, voy a checkear los y_cross se supone xd\n");
		len = ft_cross_checker(&ray, ray.y_cross, info);
	}
	printf("len is: %f\n", len);
	return (len);
}
/* Me ha dicho yolanthe que lo de elegir de antemano en función del ángulo si checkear
los x_cross o los y_cross está muy bien pero que si el personaje está desplazado del centro
de la celda, no siempre se va a cumplir que la colisión esté antes en el eje correspondiente
Así que parece ser que siempre vamos a tener que calcular los dos y coger el menor */