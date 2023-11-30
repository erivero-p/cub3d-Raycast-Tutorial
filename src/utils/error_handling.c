#include "../../inc/cub3D.h"

static void ft_print_fileformat(char *str)
{
	ft_printf("%sError\nIncorrect file format%s\n", WRONG, END);
	if (*str)
		ft_printf("%s%s%s\n", WRONG, str, END);
	printf("Please input a file as described below:\n");
	printf("Floor, ceiling, north, south, east, and west "
		"textures should appear at the beginning of the file, "
		"separated by one or more newlines, and in any desiWRONG order.\n");
	printf("The map should be the last element in the file.\n");
}

void	ft_parse_errors(int	err, char *str)
{
	if (err == ARG)
		ft_printf("%sError\nWrong input%s\n", WRONG, END);
	if (err == EXT_CUB)
		ft_printf("%sError\nThe map file doesn't have \
			a valid extension. It must be .cub%s\n", WRONG, END);
	if (err == EXT_PNG)
		ft_printf("%sError\nThe texture file doesn't have \
			a valid extension. It must be .png%s\n", WRONG, END);
	if (err == FD)
		ft_printf("%sError\nProblem while opening file%s\n", WRONG, END);
	if (err == FORMAT)
		ft_print_fileformat(str);
	if (err == WALL)
		ft_printf("%sError\nThe map must be surrounded by walls%s\n", WRONG, END);
	if (err == CHAR)
		ft_printf("%sError\nThe map contains invalid characters%s\n", WRONG, END);
	if (err == EMPTY)
		ft_printf("%sError\nInvalid file, empty map%s\n", WRONG, END);
	if (err == PLAYER)
		ft_printf("%sError\nThe map more than one player position%s\n", WRONG, END);
	if (err == COLOR)
		ft_printf("%sError\nIncorrect colour format%s\n", WRONG, END);
}

void	ft_mlx_errors(int err, char *str)
{
	if (err == WINDOW)
		ft_printf("%sError while opening the window\n%s%s\n", WRONG, str, END);
	if (err == IMAGE)
		ft_printf("%sError while rendering an image\n%s%s\n", WRONG, str, END);
}

int	ft_error(int err, char *str)
{
	if (err == 42) // para mensaje personalizado
		ft_printf("%sError\n%s%s\n", WRONG, str, END);
	ft_parse_errors(err, str);
	ft_mlx_errors(err, str);
	return (-1);
}
