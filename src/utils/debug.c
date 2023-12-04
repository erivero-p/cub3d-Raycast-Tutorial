#include "../../inc/cub3D.h"

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