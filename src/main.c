#include "../inc/cub3D.h"

void ft_free_all(t_game *info)
{
	free(info->map);
}

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
	ft_parse(&info, fd, av[1]); //-> carga del mapa en memoria y checkeo de que esté correcto
	ft_free_all(&info);
}
