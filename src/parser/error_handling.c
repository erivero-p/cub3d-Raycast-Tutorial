#include "../../inc/cub3D.h"

static void ft_print_fileformat(char *str)
{
	ft_printf("%sError\nIncorrect file format%s\n", RED, END);
	if (*str)
		ft_printf("%s%s%s\n", RED, str, END);
	ft_printf("Please input a file as described below:\n");
	ft_printf("Floor, ceiling, north, south, east, and west \
		textures should appear at the beginning of the file, \
		separated by one or more newlines, and in any desired order.\n");
	ft_printf("The map should be the last element in the file.\n");
}

int	ft_error(int err, char *str)
{
	if (err == ARG)
		ft_printf("%sError\nWrong input%s\n", RED, END);
	if (err == EXT_CUB)
		ft_printf("%sError\nThe map file doesn't have \
			a valid extension. It must be .cub%s\n", RED, END);
	if (err == EXT_PNG)
		ft_printf("%sError\nThe texture file doesn't have \
			a valid extension. It must be .png%s\n", RED, END);
	if (err == FD)
		ft_printf("%sError\nProblem while opening file%s\n", RED, END);
	if (err == FORMAT)
		ft_print_fileformat(str);
	if (err == WALL)
		ft_printf("%sError\nThe map must be surrounded by walls%s\n", RED, END);
	if (err == CHAR)
		ft_printf("%sError\nThe map contains invalid characters%s\n", RED, END);
	if (err == EMPTY)
		ft_printf("%sError\nInvalid file, empty map%s\n", RED, END);
	if (err == PLAYER)
		ft_printf("%sError\nThe map more than one player position%s\n", RED, END);
	if (err == 42) // para mensaje personalizado
		ft_printf("%sError\n%s%s\n", RED, str, END);
	return (-1);
}

/* void	ft_print_map(t_map *map)
{
	int	i = -1;

	ft_printf("-------------------------------\n");
	ft_printf("NO PATH: %s\n", map->no_path);
	ft_printf("SO PATH: %s\n", map->so_path);
	ft_printf("WE PATH: %s\n", map->we_path);
	ft_printf("EA PATH: %s\n", map->ea_path);
	ft_printf("COLOR: F: %s\n", map->f_color);
	ft_printf("COLOR: C: %s\n", map->c_color);
	ft_printf("---------------MAP-------------\n");
	while (map->map[++i])
		ft_printf("%s\n", map->map[i]);
	ft_printf("-------------------------------\n");
} */

void	ft_print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("%i: %s", i,matrix[i]);
		i++;
	}
}
