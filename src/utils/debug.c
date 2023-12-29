#include "../../inc/cub3D.h"

void	ft_print_ray(t_ray *ray, char *col)
{
	printf("%s", col);
	printf("(%fº) ray parameters are:\n", ray->angle);
	printf("origin.x: %f, origin.y: %f\n", ray->origin.x, ray->origin.y);
	printf("dir.x: %f, dir.y: %f\n", ray->dir.x, ray->dir.y);
	printf("x_cross.x: %f, x_cross.y: %f\n", ray->x_cross.x, ray->x_cross.y);
	printf("y_cross.x: %f, y_cross.y: %f\n", ray->y_cross.x, ray->y_cross.y);
/* 	if (ray->len)
	{
		printf("collision found at (x, y): [%f][%f]", ray->coll.x, ray->coll.y);
		printf("ray len is: %f\n", ray->len);
	} */
	printf("%s\n", END);
}

void	ft_printcoll(t_coll *coll, char c, char *colour)
{
	printf("%s", colour);
	printf("%c_coll:\n", c);
	printf("collision at: %f, %f\n", coll->collision.x, coll->collision.y);
	printf("raylen is: %f\n", coll->raylen);
	printf("%s\n", END);

}
/* char	ft_raycast_debug(t_game *info, float angle, char *col)
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
} */

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

void ft_print_matrix(char **matrix, char *colour)
{
	ft_printf("%s", colour);
	int len = ft_arrlen(matrix);
	ft_printf("-------------\n");
	for (int j = 0; j < len + 1; j++) 
 	   printf("matrix[%d]:	\'%s\'\n", j, matrix[j]);
	ft_printf("-------------\n");
	ft_printf("%s", END);
}
//Para printear columnna y/o fila específicas de una matriz
void ft_xy_printer(char **map, int y, int x, char *colour)
{
	printf("%s", colour);
	if (y)
	{
		printf("[0123456789]\n");
		printf(" %s\n", map[y]);
	}
	if (x)
	{
		y = -1;
		while (map[++y])
			printf("[%i]: %c\n", y, map[y][x]);
	}
	printf("%s", END);
}

void	ft_print_scene(t_scene *scene, char *colour)
{
	int	i = -1;
	ft_printf("%s", colour);
	ft_printf("-------------------------------\n");
	if (scene->no_path)
		ft_printf("NO PATH: %s\n", scene->no_path);
	if (scene->so_path)
		ft_printf("SO PATH: %s\n", scene->so_path);
	if (scene->we_path)
		ft_printf("WE PATH: %s\n", scene->we_path);
	if (scene->ea_path)
		ft_printf("EA PATH: %s\n", scene->ea_path);
	if (scene->f_color)
		ft_printf("COLOR: F: %s\n", scene->f_color);
	if (scene->c_color)
		ft_printf("COLOR: C: %s\n", scene->c_color);
	ft_printf("---------------MAP-------------\n");
	if (scene->map)
		ft_print_matrix(scene->map, 0);
	ft_printf("-------------------------------\n");
	ft_printf("%s", END);
}