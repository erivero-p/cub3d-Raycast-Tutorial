#include "../inc/cub3D.h"

void	ft_leaks(void)
{
	system("leaks -q cub3D");
}
void ft_init_structs(t_game *info)
{
	info->map = malloc(sizeof(t_map *));
	if (!info->map) //con los malloc y toa la pesca
		return ;
	info->map->test = "socorro";
//	info->imgs (...)
}

int	main(int ac, char **av)
{
	atexit(ft_leaks);
	int	fd;
	t_game	info;

	fd = ft_arg_check(ac, av);
	ft_init_structs(&info);
	if (fd < 0)
		return (-1);
	ft_parse(&info, fd); //-> carga del mapa en memoria y checkeo de que esté correcto
	//	ft_game_handling();
	ft_clean(&info);
}
