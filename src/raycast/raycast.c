#include "../../inc/cub3D.h"

void	ft_init_ray(t_ray *ray, t_game *info, double angle)
{
	int	sn;

	sn = 1;
//	ray->coll = false;
//	ray->origin.x = info->player->pos_map->x;
//	ray->origin.y = info->player->pos_map->y;
/* 	ray->origin.x = 3.5;
	ray->origin.y = 3.5; */
	ray->origin = ft_get_player_init_pos(info); //hardcodeado
	ray->origin.x += 0.5;
	ray->origin.y += 0.5;
	ray->angle =  angle * 180 / M_PI;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->sgn.x = 1;
	ray->sgn.y = 1;
	if (ray->dir.x < 0)
		ray->sgn.x *= -1;
	if (ray->dir.y < 0)
		ray->sgn.y *= -1;
	ray->x_cross.x = ray->sgn.y / tan(angle); //no sé si sgn.x o y pero bueno
	ray->x_cross.y = ray->sgn.y;
	ray->y_cross.x = ray->sgn.x;
	ray->y_cross.y = tan(angle);
}

/* bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info)
{
	char **map;
	int		j;
	int		i;

	map = info->scene->map;
//	printf("col_checker pos.x: %d, pos.y: %d\n", pos.x, pos.y);
	j = (int)pos.y; //+ (int)ray->sgn.y; //esto es para sumarle o restarle 1 en función de si mira arriba o abajo
	i = (int)pos.x; //+ (int)ray->sgn.x; //no sé hasta qué punto es necesario ahora mismo
//	printf("position checked: pos.x (%f), pos.y(%f), char (%c)\n", pos.x, pos.y, map[j][i]);
	if (map[j][i] == '1')
		return (true);
	return (false);
} */

bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info, char cross)
{
	char **map;
	int		j;
	int		i;

	map = info->scene->map;
//	printf("col_checker pos.x: %d, pos.y: %d\n", pos.x, pos.y);
	j = (int)pos.y; //+ (int)ray->sgn.y; //esto es para sumarle o restarle 1 en función de si mira arriba o abajo
	i = (int)pos.x; //+ (int)ray->sgn.x; //no sé hasta qué punto es necesario ahora mismo
	if (ray->sgn.y == -1 && cross == 'x')
		j--; //si mira arriba y estoy checkeando los cruces con x
	if (ray->sgn.x == -1 && cross == 'y')
		i--; //si mira a la izda y checkeo los y_crosses
//	printf("position checked: pos.x (%f), pos.y(%f), char (%c)\n", pos.x, pos.y, map[j][i]);
	if (i >= info->scene->len_x || j >= info->scene->len_y || i < 0 || j < 0)
		return (true); //esto para no salirme del mapa
	if (map[j][i] == '1')
		return (true);
	return (false);
}

t_coord	ft_first_step(t_coord origin, t_coord step, double angle, t_game *info)
{
	t_coord	pos;

	pos.y = (int)origin.y + step.y;
	pos.x = (int)origin.x + step.x;
	if (angle == 90 || angle == 270)
		pos.x = origin.x;
	if (angle == 0 || angle == 180)
		pos.y = origin.y;
/* 	if (pos.x >= info->scene->len_x)
		pos.x = info->scene->len_x - 1;
	if (pos.y >= info->scene->len_y)
		pos.y = info->scene->len_y - 1; */
	return (pos);
}

double	ft_cross_checker(t_ray *ray, t_coord step, t_game *info, char cross)
{
	t_coord	pos;
	t_coord	cateto;
	double	distance;

	pos = ft_first_step(ray->origin, step, ray->angle, info);
	while (1)
	{
		if (ft_coll_checker(pos, ray, info, cross))
		{
			ray->coll.x = pos.x;
			ray->coll.y = pos.y;
			break ;
		}
		pos.x += step.x;
		pos.y += step.y;
	}
	cateto.x = pos.x - ray->origin.x;
	cateto.y = pos.y - ray->origin.y;
	distance = sqrt(pow(cateto.x, 2) + pow(cateto.y, 2));
	return (distance);
}
void	ft_raydebug(t_ray *ray, char *col)
{
	static int i = 0;
	i++;
//	if (pos.x - (int)pos.x == 0)
	if (i == 1)
		printf("player pos (x,y): %f, %f\n", ray->origin.x, ray->origin.y);
	if (i == 1 || i == 3 || i % 100 == 0 || i == 1080 - 1)
	{
		printf("%s", col);
		printf("ray nº: %i (%fº)\n", i, ray->angle);
		printf("collision on (x, y): [%f][%f]\n", ray->coll.x, ray->coll.y);
		printf("%s", END);
	}
	if (i == 1080/2 + 1)
	{
		printf("%son central ray (%f);\n", WRONG, ray->angle);
		printf("collision on (x, y): [%f][%f]\n", ray->coll.x, ray->coll.y);
		printf("step sizes are: x: %f, y: %f\n", ray->x_cross.x, ray->x_cross.y);
	}
/* 	if (i > 448 && i < 452)
		printf("collision on (x, y): [%f][%f]\n", pos.x, pos.y); */
}
/* void	ft_ray_caster(t_game *info, t_ray *ray, float angle)
{
	ft_init_ray(ray, info, ft_deg_to_rad(angle));
//	ft_print_ray(&ray, "\033[95m"); //purple
	if (angle > 45 && angle < 135 || angle >= 225 && angle < 315)
		ray->len = ft_cross_checker(ray, ray->x_cross, info, 'x');
	else
		ray->len = ft_cross_checker(ray, ray->y_cross, info, 'y');
//	printf("len is: %f\n", len);
//	return (len);
	ft_raydebug(ray, DEBUG_COLOR);
} */
void	ft_ray_caster(t_game *info, t_ray *ray, float angle)
{
	double	xlen;
	double	ylen;
	t_coord	impact;

	ft_init_ray(ray, info, ft_deg_to_rad(angle));
	xlen = ft_cross_checker(ray, ray->x_cross, info, 'x');
	impact = ray->coll;
	ylen = ft_cross_checker(ray, ray->y_cross, info, 'y');
	if (xlen < ylen)
	{
		ray->len = xlen;
		ray->coll = impact; //para recuperar la colisión de x;
	}
	else
		ray->len = ylen;
//	printf("len is: %f\n", len);
//	return (len);
	ft_raydebug(ray, DEBUG_COLOR);
}
/* Me ha dicho yolanthe que lo de elegir de antemano en función del ángulo si checkear
los x_cross o los y_cross está muy bien pero que si el personaje está desplazado del centro
de la celda, no siempre se va a cumplir que la colisión esté antes en el eje correspondiente
Así que parece ser que siempre vamos a tener que calcular los dos y coger el menor */

/* void	ft_ray_tester(t_game *info)
{
	t_ray	ray;

	ft_ray_caster(info, &ray, 0);
	ft_print_ray(&ray, WRONG);
	ft_ray_caster(info, &ray, 90);
	ft_print_ray(&ray, DEBUG2);
	ft_ray_caster(info, &ray, 180);
	ft_print_ray(&ray, GOOD);
	ft_ray_caster(info, &ray, 270);
	ft_print_ray(&ray, DEBUG_COLOR);
} */
