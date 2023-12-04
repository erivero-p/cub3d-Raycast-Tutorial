#include "../../inc/cub3D.h"

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

static int	ft_rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
/* toma los 3 enteros y los va desplazando a la izquierda para que el rojo ocupe la primera
posición, seguido del verde y del azul, y combinándolos con or en principio las funciones
de mlx deberían ser capaces de leerlo tal cual (o eso me gusta pensar xd)*/


int	ft_get_colour(char  **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ph_atoi(rgb[0]);
	g = ph_atoi(rgb[1]);
	b = ph_atoi(rgb[2]);

	if (r < 0 || r > 255 || g < 0 || g > 255
		|| b < 0 || b > 255)
		return (-1);
	return (ft_rgb_to_hex(r, g, b));
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
	ret = ft_get_colour(rgb);
	ft_free_double_pointer(rgb);
//	ft_printf("ret is: %i", ret);
	return (ret);
}