#include "../../inc/cub3D.h"

void 	ft_print_ray(t_ray *ray, char *col)
{
	printf("%s", col);
	printf("(%fº) ray parameters are:\n", ray->angle);
	printf("origin.x: %f, origin.y: %f\n", ray->origin.x, ray->origin.y);
	printf("dir.x: %f, dir.y: %f\n", ray->dir.x, ray->dir.y);
	printf("x_cross.x: %f, x_cross.y: %f\n", ray->x_cross.x, ray->x_cross.y);
	printf("y_cross.x: %f, y_cross.y: %f\n", ray->y_cross.x, ray->y_cross.y);
	if (ray->len)
	{
		printf("collision found at (x, y): [%f][%f]", ray->coll.x, ray->coll.y);
		printf("ray len is: %f\n", ray->len);
	}
	printf("%s\n", END);
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