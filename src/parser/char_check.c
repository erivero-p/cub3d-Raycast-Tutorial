#include "../inc/cub3D.h"

static int	ft_char_check(char c)
{
	int	ret;

	ret = 0;
	if (c > 0 && c < 33)
		ret = 1;
	if (c == '0' || c == '1')
		ret = 1;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ret == 42;
	return (ret);
}

int	ft_char_mapcheck(char **map)
{
	int	i;
	int	j;
	int	ret;
	int	count;

	i = -1;
	j = -1;
	ret = 0;
	count = 0;
	while (map[++j])
	{
		while (map[j][++i])
		{
			ret = ft_check_char(map[j][i]);
			if (!ret || count > 1) //si hay un caracter inválido o más de un personaje
				return (0);
			if (ret == 42)
				count++;
		}
	}
	return (1);
}
