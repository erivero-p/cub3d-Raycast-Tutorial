#include "../inc/cub3D.h"

int	ft_save_info(char *ptr, char *line)
{
	if (*ptr == NULL)
		ptr = ft_strdup(line);
	else
		return (0);
	return (1);
}

int	ft_read_info(t_map *map, char *line)
{
	int	ret;

	ret = 1;
	if (ft_strncmp(line, "NO ", 3))
		ret = ft_save_info(map->no_path, line);
	if (ft_strncmp(line, "SO ", 3))
		ret = ft_save_info(map->so_path, line);
	if (ft_strncmp(line, "WE ", 3))
		ret = ft_save_info(map->we_path, line);
	if (ft_strncmp(line, "EA ", 3))
		ret = ft_save_info(map->ea_path, line);
	if (ft_strncmp(line, "F ", 2))
		ret = ft_save_info(map->f_color, line);
	if (ft_strncmp(line, "C ", 2))
		ret = ft_save_info(map->c_color, line);
	map->counter += ret;
	free(line);
	return (ret);
}

int	ft_get_map(int fd, t_map *map)
{
	char	*line;
	char	*tmp_map_line;

	line = get_next_line(fd);
	tmp_map_line = NULL;
	if (!line)
		return (0);
	while (line)
	{
		tmp_map_line = ft_join_free(tmp_map_line, line);
		free(line);
		line = get_next_line(fd);
		if (line[0] == '\n') //para que después del split las islas queden bien
			line = ft_strdup("	\n"); //no sé si funcionará en vdd
	} //trim para quitarle los tabs que haya al principio y al final
	map->map = ft_split(ft_strtrim_free(tmp_map_line, "	"), '\n');
	map->aux_map = ft_split(ft_strtrim_free(tmp_map_line, "	"), '\n');
	free(line);
	free(tmp_map_line);
}

int	ft_read_file(t_game info, int fd)
{
	t_map	map;
	char	*line;

	map = malloc(sizeof(t_map));
	if (!map) //con los malloc y toa la pesca
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!ft_read_info(&map, line)); //si hay alguno repe debería salir
			return (0);
		if (map.counter == 6) //si ya tengo cargados los 6 datos
		{
			if(!ft_get_map(fd, &map))
				return (0);
		}
	}
	return (1);
}
