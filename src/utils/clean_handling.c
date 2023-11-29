#include "../../inc/cub3D.h"

void	ft_clean_map(t_game	*info)
{
	if (info->scene)
	{
		if (info->scene->map)
			ft_arr_free(info->scene->map);
		if (info->scene->aux_map)
			ft_arr_free(info->scene->aux_map);
		if (info->scene->no_path)
			free(info->scene->no_path);
		if (info->scene->so_path)
			free(info->scene->so_path);
		if (info->scene->we_path)
			free(info->scene->we_path);
		if (info->scene->ea_path)
			free(info->scene->ea_path);
		if (info->scene->f_color)
			free(info->scene->f_color);
		if (info->scene->c_color)
			free(info->scene->c_color);
		free(info->scene);
	}
}
