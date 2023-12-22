#include "../../inc/cub3D.h"

void	ft_init_ray(t_ray *ray, t_game *info, double angle)
{
	int	sn;

	sn = 1;
//	ray->coll = false;
	ray->origin.x = info->player->pos->x;
	ray->origin.y = info->player->pos->y;
	ray->deltaang = ft_deg_to_rad(info->player->angle) - angle;
/* 	ray->origin.x = 3.5;
	ray->origin.y = 3.5; */
//	ray->origin = ft_get_player_init_pos(info); //hardcodeado
/* 	ray->origin.x += 0.5;
	ray->origin.y += 0.5; */
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
	ray->y_cross.y = tan(angle) * ray->sgn.x;
}

/* bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info, char cross)
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
} */
/* void ft_coll_caster(t_ray *ray, char cross, int *i, int *j)
{

} */

bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info, char cross)
{
	char **map;
	int		j;
	int		i;

	map = info->scene->map;
	j = (int)pos.y; //+ (int)ray->sgn.y; //esto es para sumarle o restarle 1 en función de si mira arriba o abajo
	i = (int)pos.x; //+ (int)ray->sgn.x; //no sé hasta qué punto es necesario ahora mismo
	if (cross == 'x' && ray->sgn.y == -1)
		j--;
	if (cross == 'y' && ray->sgn.x == -1)
		i--;	
/* 	printf("col_checker pos.x: %f, pos.y: %f\n", pos.x, pos.y);
	printf("casted pos.x: %d, pos.y: %d\n", i, j); */
	if (i >= info->scene->len_x || j >= info->scene->len_y || i < 0 || j < 0)
		return (true); //esto para no salirme del mapa
	if (map[j][i] == '1')
	{
		printf("casted collision on (i, j): %i, %i\n", i, j);
		return (true);
	}
	return (false);
}

/* t_coord	ft_first_step(t_ray *ray, t_coord step, double angle, t_game *info)
{
	t_coord	pos;
	t_coord	first;
	
	first.x = sqrt(pow(step.x, 2)) - fmod(ray->origin.x, 1.0);
	first.y = sqrt(pow(step.y, 2)) - fmod(ray->origin.y, 1.0);

//	printf("rest.x: %f, rest.y: %f\n", rest.x, rest.y);
	pos.y = (int)origin.y + step.y;
	pos.x = (int)origin.x + step.x;
	pos.x = ray->origin.x + (first.x * ray->sgn.x);
	pos.y = ray->origin.y + (first.y * ray->sgn.y);
	if (angle == 90 || angle == 270)
		pos.x = ray->origin.x;
	if (angle == 0 || angle == 180)
		pos.y = ray->origin.y;
//	printf("after 1st step: pos.x (%f), pos.y (%f)\n", pos.x, pos.y);
	return (pos);
} */
t_coord	ft_first_step(t_ray *ray, t_coord step, double angle, t_game *info)
{
	t_coord	pos;
	t_coord	first;
	
	first.x = sqrt(pow(step.x, 2)) - fmod(ray->origin.x, 1.0);
	first.y = sqrt(pow(step.y, 2)) - fmod(ray->origin.y, 1.0);

//	printf("rest.x: %f, rest.y: %f\n", rest.x, rest.y);
/* 	pos.y = (int)origin.y + step.y;
	pos.x = (int)origin.x + step.x; */
	pos.x = ray->origin.x + (first.x * ray->sgn.x);
	pos.y = ray->origin.y + (first.y * ray->sgn.y);
	if (angle == 90 || angle == 270)
		pos.x = ray->origin.x;
	if (angle == 0 || angle == 180)
		pos.y = ray->origin.y;
//	printf("after 1st step: pos.x (%f), pos.y (%f)\n", pos.x, pos.y);
	return (pos);
}

t_coll	ft_cross_checker(t_ray *ray, t_coord step, t_game *info, char cross)
{
	t_coord	pos;
	t_coord	cateto;
	t_coll	coll;
	double	distance;

	pos = ft_first_step(ray, step, ray->angle, info);
	while (1)
	{
		if (ft_coll_checker(pos, ray, info, cross))
		{
			coll.collision.x = pos.x;
			coll.collision.y = pos.y;
			if (cross == 'y')
				coll.txt = 1 * ray->sgn.x; //1 si es este -1 si es oeste
			else
				coll.txt = 2 * ray->sgn.y; //2 si es sur -2 si es norte
			break ;
		}
		pos.x += step.x;
		pos.y += step.y;
	}
 // printf("%scollision on: (%f, %f)%s\n", GOOD, pos.y, pos.x, END);
	coll.raylen = sqrt(pow(pos.x - ray->origin.x, 2) + pow(pos.y - ray->origin.y, 2));
	coll.distance = coll.raylen * cos(ray->deltaang);
	return (coll);
}
/* 	cateto.x = pos.x - ray->origin.x;
	cateto.y = pos.y - ray->origin.y; */


t_coll	ft_ray_caster(t_game *info, float angle)
{
/* 	double	xlen;
	double	ylen; */
	t_coll	x_coll;
	t_coll	y_coll;
	t_ray	ray; 
	int i;
	int j;

	ft_init_ray(&ray, info, ft_deg_to_rad(angle));
	x_coll = ft_cross_checker(&ray, ray.x_cross, info, 'x');
//	ft_printcoll(&x_coll, 'x');
	y_coll = ft_cross_checker(&ray, ray.y_cross, info, 'y');
//	ft_printcoll(&y_coll, 'y');
	if (x_coll.raylen < y_coll.raylen)
		return (x_coll);
	else
		return (y_coll);
}

char	ft_raycast_debug(t_game *info, float angle, char *col)
{
	t_coll	x_coll;
	t_coll	y_coll;
	t_ray	ray; 

	ft_init_ray(&ray, info, ft_deg_to_rad(angle));
	ft_print_ray(&ray, col);
	x_coll = ft_cross_checker(&ray, ray.x_cross, info, 'x');
	ft_printcoll(&x_coll, 'x', col);
	y_coll = ft_cross_checker(&ray, ray.y_cross, info, 'y');
	ft_printcoll(&y_coll, 'y', col);
	if (x_coll.raylen < y_coll.raylen)
		return ('x');
	else
		return ('y');
}

void	ft_ray_tester(t_game *info, double a1, double a2, double a3, double a4)
{
	t_ray	ray;

/* 	int	angle = 270 - 45; // Esto para encontrar el primer y_cross
	char c;

	while (c != 'y')
	{
		c = ft_raycast_debug(info, angle, WRONG);
		angle++;
	} 
	printf("Y cross found at: %d\n", angle);*/
	//printf("(5, 1): %c\n", info->scene->map[1][5]);
	printf("%c_cross chosen\n\n", ft_raycast_debug(info, 45, WRONG));
	printf("%c_cross chosen\n\n", ft_raycast_debug(info, 135, DEBUG2));
	printf("%c_cross chosen\n\n", ft_raycast_debug(info, 225, GOOD));
	printf("%c_cross chosen\n\n", ft_raycast_debug(info, 315, DEBUG_COLOR));
}