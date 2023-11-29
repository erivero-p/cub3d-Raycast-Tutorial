#include "../../inc/cub3D.h"

int ft_is_wall(char **map, int x, int y, int len)
{
	if (y == 0 && map[y][x] > 32) //si estoy arriba y hay algo
		return (1);
	if (x == 0 && map[y][x] > 32) // si estoy a la izquierda y hay algo
		return (1);
	if (y == len - 1 && map[y][x] > 32) //si estoy abajo y hay algo
		return (1);
	if (x < len - 1 && map[y][x + 1] <= 32) //si a la derecha hay un espacio
		return (1);
	if (x > 0 && map[y][x - 1] <= 32) //si a la izquierda hay un espacio
		return (1);
	if (y < len - 1 && map[y + 1][x] <= 32) //si abajo hay un espacio
		return (1);
	if (y > 0 && map[y - 1][x] <= 32) //si arriba hay un espacio
		return (1);
	return (0);
}

/* int	ft_arraylen(char **arr)
{
	int	j = 0;
	while (arr[j])
		j++;
	printf("len is: %i\n", j);
	return (j);
} */

int	ft_wall_check(char **map)
{
	int x = 0;
	int y = 0;
	int	len = 13; //friendly reminder de actualizar manualmente

//	printf("len is: %i\n", len);
	while (map[y] && y < len)
	{
		while (map[y][x])
		{
			while (map[y][x] > 0 && map[y][x] <= 32)
				x++;
			if (map[y][x] > 0 && ft_is_wall(map, x, y, len) && map[y][x] != '1')
				return (ft_error(WALL, NULL));
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/* int main(void)
{
	char *map[] = {
		"1111111",
		"1000011",
		"10111",
		"1011111",
		"1011101",
		"1011101",
		"1111111",
		"\n",
		"\n",
		"\n",
		"111",
		"101",
		"111"
	};

	if (wall_checker(map))
		printf("to chachi\n");
	else
		printf("maal\n");
	return 0;
} */