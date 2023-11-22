
int	is_wall(char **map, int x, int y, int len)
{
	if (y == 0 && map[y][x] > 32) //si estoy arriba y hay algo
		return (1);
	if (x == 0 && map[y][x] > 32) // si estoy a la izda y hay algo
		return (1);
	if (y == len && map[y][x] > 32) //si estoy abajo y hay algo
		return (1);
	if (map[y][++x] <= 32) //si a la derecha hay un espacio
		return (1);
	if (map[y][--x] <= 32) //si a la izda hay un espacio
		return (1);
	if (map[++y][x] <= 32) //si abajo hay un espacio
		return (1);
	if (map[--y][x] <= 32) //si arriba hay un espacio
		return (1);
	return (0);
}

int	wall_checker(char **map)
{
	int x = 0;
	int y = 0;
	int	len = ft_arraylen(map);

	while (map[y])
	{
		while (map[y][x])
		{
			if (is_wall(map, x, y, len) && map[y][x] != '1')
				return (-1);
		}
		y++;
	}
	return (0);
}