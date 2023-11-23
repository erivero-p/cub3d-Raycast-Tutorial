#include "../inc/cub3D.h"

int	main(int ac, char *av)
{
	int	fd;
//	t_game	info;

	if (ac != 2)
	{
		ft_printf("\033[0;31mError\n Wrong arguments\033");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033[0;31mError\n Problem while opening file\033");
		return (-1);
	}
//	ft_map_handling(); -> carga del mapa en memoria y checkeo de que esté correcto
//	ft_game_handling();
	close(fd);
}
