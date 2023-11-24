#include "../../inc/cub3D.h"

static void ft_print_fileformat()
{
	ft_printf("%sError\nIncorrect file format%s\n", RED, END);
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
	if (err == EXT)
		ft_printf("%sError\nThe map file doesn't have \
			a valid extension. It must be .cub%s\n", RED, END);
	if (err == FD)
		ft_printf("%sError\nProblem while opening file%s\n", RED, END);
	if (err == FORMAT)
		ft_print_fileformat();
	if (err == WALL)
		ft_printf("%sError\nThe map must be surrounded by walls%s\n", RED, END);
	if (err == CHAR)
		ft_printf("%sError\nThe map contains invalid characters%s\n", RED, END);
	if (err == PLAYER)
		ft_printf("%sError\nThe map more than one player position%s\n", RED, END);
	if (err == 42) // para mensaje personalizado
		ft_printf("%sError\n%s%s\n", RED, str, END);
	return (-1);
}
