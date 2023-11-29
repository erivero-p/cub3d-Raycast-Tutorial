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

int	ft_rgbcheck(char *color)
{
	int		len;
	int		ret;
	char	**rgb;

	ret = 0;
	rgb = ft_split(color, ',');
	len =  ft_arrlen(rgb);
	if (ft_arrlen(rgb) != 3)
		ret = -1;
	if (ph_atoi(rgb[0]) < 0 || ph_atoi(rgb[0]) > 255)
		ret = -1;
	if (ph_atoi(rgb[1]) < 0 || ph_atoi(rgb[1]) > 255)
		ret = -1;
	if (ph_atoi(rgb[2]) < 0 || ph_atoi(rgb[2]) > 255)
		ret = -1;
	ft_print_matrix(rgb, 22);
	ft_free_double_pointer(rgb);
	ft_printf("ret is: %i", ret);
	return (ret);
}
int	ft_color_check(t_scene *scene) //está chiquito, es solo pa probar
{
	if (ft_rgbcheck(scene->c_color) == -1)
		return (ft_error(COLOR, NULL));
	if (ft_rgbcheck(scene->f_color) == -1)
		return (ft_error(COLOR, NULL));
	return (0);
}

int	ft_scene_check(t_scene *scene)
{
	if (ft_texture_check(scene) == -1 || ft_color_check(scene))
	//	|| ft_char_mapcheck(scene->map) == -1 ) || ft_wall_check(scene->map) == -1)
		return (-1);
	return (0);
}