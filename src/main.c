#include "../inc/cub3D.h"

void	ft_leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int ac, char **av)
{
	atexit(ft_leaks);
	int	fd;
	t_game	info;

	fd = ft_arg_check(ac, av);
	if (fd < 0)
		return (-1);
	ft_parse(&info, fd); //-> carga del mapa en memoria y checkeo de que esté correcto
	//	ft_game_handling();
	ft_clean(&info);
}
