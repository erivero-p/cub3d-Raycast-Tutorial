#include "../../inc/cub3D.h"

void	ft_clean_map(t_game	*info)
{
	if (info->map)
	{
		if (info->map->map)
			ft_arr_free(info->map->map);
		if (info->map->aux_map)
			ft_arr_free(info->map->aux_map);
		if (info->map->no_path)
			free(info->map->no_path);
		if (info->map->so_path)
			free(info->map->so_path);
		if (info->map->we_path)
			free(info->map->we_path);
		if (info->map->ea_path)
			free(info->map->ea_path);
		if (info->map->f_color)
			free(info->map->f_color);
		if (info->map->c_color)
			free(info->map->c_color);
		free(info->map);
	}
}
