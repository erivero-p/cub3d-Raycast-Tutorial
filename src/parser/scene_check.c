#include "../../inc/cub3D.h"

int	ft_texture_check(t_scene *scene)
{
	if (ft_check_ext(scene->no_path, ".png") == -1)
		return (ft_error(EXT_PNG, NULL));
	if (ft_check_ext(scene->so_path, ".png") == -1)
		return (ft_error(EXT_PNG, NULL));
	if (ft_check_ext(scene->we_path, ".png") == -1)
		return (ft_error(EXT_PNG, NULL));
	if (ft_check_ext(scene->ea_path, ".png") == -1)
		return (ft_error(EXT_PNG, NULL));
	return (0);
}

int	ft_color_check(t_scene *scene) //está chiquito, es solo pa probar
{
	if (ft_strlen(scene->c_color) < 5 || ft_strlen(scene->c_color) > 11)
		return (ft_error(42, "elisa por dios termina ft_color_check"));
	if (ft_strlen(scene->f_color) < 5 || ft_strlen(scene->f_color) > 11)
		return (ft_error(42, "elisa por dios termina ft_color_check"));
	return (0);
}

int	ft_scene_check(t_scene *scene)
{
	if (ft_texture_check(scene) == -1 || ft_color_check(scene)
		|| ft_char_mapcheck(scene->map) == -1 || ft_wall_check(scene->map) == -1)
		return (-1);
	return (0);
}