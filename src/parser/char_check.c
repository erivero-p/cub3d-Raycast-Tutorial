#include "../../inc/cub3D.h"

static int	ft_char_check(char c)
{
	int	ret;

	ret = 0;
	if (c > 0 && c < 33)
		ret = 1;
	if (c == '0' || c == '1')
		ret = 1;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ret = 42;
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
			ret = ft_char_check(map[j][i]);
			if (!ret ) //si hay un caracter inválido o más de un personaje
				return (ft_error(CHAR, NULL));
			if (count > 1)
				return (ft_error(PLAYER, NULL));
			if (ret == 42)
				count++;
		}
	}
	return (0); //0 si todo fufa
}
