#include "../../inc/cub3D.h"

void	ft_clean_map(t_map	*map)
{
	if (map->map)
		ft_arr_free(map->map);
	if (map->aux_map)
		ft_arr_free(map->aux_map);
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->f_color)
		free(map->f_color);
	if (map->c_color)
		free(map->c_color);
}

void	ft_clean(t_game	*game)
{
	if(game->map)
		ft_clean_map(game->map);
}