#include "../../inc/cub3D.h"

int	ft_char_check(char c)
{
	int	ret;

	ret = 0;
	if (c > 0 && c < 33)
		ret = 1;
	if (c == '0' || c == '1')
		ret = 1;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ret = 42;
	ft_printf("char_check checks: %c, ret is: %i\n", c, ret);
	return (ret);
}

int	ft_char_mapcheck(char **map)
{
	int	i;
	int	j;
	int	ret;
	int	count;

	j = -1;
	ret = 0;
	count = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			ret = ft_char_check(map[j][i]);
			if (!ret ) //si hay un caracter inválido
				return (ft_error(CHAR, NULL));
			if (ret == 42)
				count++;
		}
	}
	if (count != 1) //si hay más de un personaje o ninguno
		return (ft_error(PLAYER, NULL));
	return (0); //0 si todo fufa
}
