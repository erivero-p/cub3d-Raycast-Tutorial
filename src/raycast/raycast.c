#include "../../inc/cub3D.h"
#include <stdbool.h>

void 	ft_print_ray(t_ray *ray, char *col)
{
	printf("%s", col);
	if (!ray->coll)
	{
		printf("before collision, ray parameters are:\n");
		printf("origin.x: %d, origin.y: %d\n", ray->origin.x, ray->origin.y);
//		printf("dir.x: %f, dir.y: %f\n", ray->dir.x, ray->dir.y);
		printf("x_cross.x: %d, x_cross.y: %d\n", ray->x_cross.x, ray->x_cross.y);
		printf("y_cross.x: %d, y_cross.y: %d\n", ray->y_cross.x, ray->y_cross.y);
	}
	printf("%s", END);
}
void	ft_init_step(t_ray *ray, double angle)
{
	int	ver; //-1 arriba, 1 abajo
	int	hor; //-1 izda, 1 dcha

	ver = 1;
	hor = 1;
	if (cos(angle) < 0)
		hor = -1;
	if (sin(angle) < 0)
		ver = -1;
	ray->x_cross.x = hor / tan(angle);
	ray->x_cross.y = ver;
	ray->y_cross.x = hor;
	ray->y_cross.y = tan(angle);
}

void	ft_init_ray(t_ray *ray, t_game *info, double angle)
{
	int	sn;

	sn = 1;
	ray->coll = false;
//	ray->origin.x = info->player->pos_map->x;
//	ray->origin.y = info->player->pos_map->y;
	ray->origin.x = (double)3.5;
	ray->origin.y = (double)3.5;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ft_init_step(ray, angle);
/* 	printf("sin is: %f\n", sin(angle));
	printf("dir.y (sin) is: %f\n", ray->dir.y);
	printf("dir.x (cos) is: %f\n", ray->dir.x);
	ray->x_cross.x = 1 / tan(angle);
	ray->x_cross.y = 1; // (alto del info->scene->tile)
	ray->y_cross.x = 1; // (ancho del info->scene->tile)
	ray->y_cross.y = 1 / tan(angle);
	if (ray->dir.y < 0.000000)
	{
		printf("hola=??????\n");
		ray->x_cross.y *= -1;
	} */
}
bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info)
{
	t_coord	coord;
	char **map;
	int		x;
	int		y;
/* 	coord.x = (int)pos.x / info->scene->tile; 
	coord.y = (int)pos.y / info->scene->tile; 
	No sé si hace falta dividir pq no sé si a estas alturas la posición
	está en coordenadas o en píxeles xd */
	x = 1;
	y = 1;
	map = info->scene->map;
	coord.x = (int)pos.x;
	coord.y = (int)pos.y;
//	printf("coord.y = %d, coord.x = %d\n", pos.y, pos.x);
	if (ray->dir.x < 0) //si el coseno es negativo mira pa la izquierda, 
		x *= -1; //así que debo checkear la celda de la izda a la que estoy
	if(ray->dir.y < 0) //si el seno es negativo mira hacia arriba
		y *= -1; //así que debo checkear la celda de arriba
	if (map[coord.y + y][coord.x + x] == '1')
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
//	printf("%safter first step, pos.x: %d, pos.y: %d\n%s", WRONG, pos.x, pos.y, END);
	while (1)
	{
		printf("position checked: pos.x (%d), pos.y(%d)\n", pos.x, pos.y);
		ray->coll = ft_coll_checker(pos, ray, info);
		if (ray->coll)
			break ;
		pos.x += step.x;
		pos.y += step.y;
	}
	printf("%scollision on: (%d, %d)%s\n", GOOD, pos.y, pos.x, END);
	cateto.x = pos.x - ray->origin.x;
	cateto.y = pos.y - ray->origin.y;
	distance = sqrt(pow(cateto.x, 2) + pow(cateto.y, 2));
	return (distance);
}

double	ft_ray_caster(t_game *info)
{
	double	len;
	t_ray	ray;

//	ft_init_ray(&ray, info, info->player->angle);
	double	angle = 0;
	ft_init_ray(&ray, info, angle * M_PI / 180.0); //hard codeado, el pj supuestamente mira al norte
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