#include "../../inc/cub3D.h"

void ft_print_matrix(char **matrix, int test)
{
	int len = ft_arrlen(matrix);
	ft_printf("-------------\n");
	ft_printf("test n: %i\n", test);
	for (int j = 0; j < len + 1; j++) 
 	   printf("info->map->file[%d]: %s\n", j, matrix[j]);
	ft_printf("-------------\n");
}

void	ft_print_map(t_map *map)
{
	int	i = -1;

	ft_printf("-------------------------------\n");
	if (map->no_path)
		ft_printf("NO PATH: %s\n", map->no_path);
	if (map->so_path)
		ft_printf("SO PATH: %s\n", map->so_path);
	if (map->we_path)
		ft_printf("WE PATH: %s\n", map->we_path);
	if (map->ea_path)
		ft_printf("EA PATH: %s\n", map->ea_path);
	if (map->f_color)
		ft_printf("COLOR: F: %s\n", map->f_color);
	if (map->c_color)
		ft_printf("COLOR: C: %s\n", map->c_color);
	ft_printf("---------------MAP-------------\n");
	if (map->map)
		ft_print_matrix(map->map, 0);
	ft_printf("-------------------------------\n");
}