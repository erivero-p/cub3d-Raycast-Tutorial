#include "../../inc/cub3D.h"

static int	ft_texture_check(t_scene *scene)
{
	if (ft_check_ext(scene->no_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->so_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->we_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->ea_path, ".png") == -1)
		return (-1);
	return (0);
}

static int	ph_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-') //si es negativo
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num);

}
static int	ft_char_counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_color_check(char *color)
{
	int		i;
	int		cont;
	int		ret;
	char	**rgb;

	ret = 0;
	i = -1;

	if (ft_char_counter(color, ',') > 2)
		return (-1);
	rgb = ft_split(color, ',');
	if (ft_arrlen(rgb) != 3)
		ret = -1;
	if (ph_atoi(rgb[0]) < 0 || ph_atoi(rgb[0]) > 255)
		ret = -1;
	if (ph_atoi(rgb[1]) < 0 || ph_atoi(rgb[1]) > 255)
		ret = -1;
	if (ph_atoi(rgb[2]) < 0 || ph_atoi(rgb[2]) > 255)
		ret = -1;
	ft_free_double_pointer(rgb);
//	ft_printf("ret is: %i", ret);
	return (ret);
}

int	ft_scene_check(t_scene *scene)
{
	ft_print_scene(scene, DEBUG_COLOR);
	if (ft_texture_check(scene) == -1)
		return (ft_error(EXT_PNG, NULL));
	if (ft_color_check(scene->f_color)  == -1 || ft_color_check(scene->c_color) == -1)
		return (ft_error(COLOR, NULL));
	if (ft_char_mapcheck(scene->map) == -1)
		return (-1);
	if (ft_wall_check(scene->map, scene) == -1)
		return (ft_error(WALL, NULL));
	return (0);
}
