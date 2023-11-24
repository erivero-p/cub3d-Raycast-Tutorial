#include "../../inc/cub3D.h"

int	ft_save_info(char *ptr, char *line)
{
	printf("en ft_save_info----\n");
	if (ptr == NULL)
	{
		printf("en ft_save_info-> ptr: %s\n", ptr);
		ptr = ft_strdup(line);
	}
	else
		return (0);
	return (1);
}

int	ft_read_info(t_map *map, char *line)
{
	int	ret;

	ret = 1;
	if (!ft_strncmp(line, "NO ", 3))
		ret = ft_save_info(map->no_path, line);
	if (!ft_strncmp(line, "SO ", 3))
	{
		printf("en ft_read_info-> line: %s\n", line);
		ret = ft_save_info(map->so_path, line);
	}
	if (!ft_strncmp(line, "WE ", 3))
		ret = ft_save_info(map->we_path, line);
	if (!ft_strncmp(line, "EA ", 3))
		ret = ft_save_info(map->ea_path, line);
	if (!ft_strncmp(line, "F ", 2))
		ret = ft_save_info(map->f_color, line);
	if (!ft_strncmp(line, "C ", 2))
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
		tmp_map_line = ft_strjoin_free(tmp_map_line, line);
		free(line);
		line = get_next_line(fd);
		if (line[0] == '\n') //para que después del split las islas queden bien
			line = ft_strdup("	\n"); //no sé si funcionará en vdd
	} //trim para quitarle los tabs que haya al principio y al final
	map->map = ft_split(ft_strtrim_free(tmp_map_line, "	"), '\n');
	map->aux_map = ft_split(ft_strtrim_free(tmp_map_line, "	"), '\n');
	free(line);
	free(tmp_map_line);
	return (1);  //si todo guay
}

void	ft_print_map(t_map *map)
{
	int	i = -1;

	ft_printf("-------------------------------\n");
	ft_printf("NO PATH: %s\n", map->no_path);
	ft_printf("SO PATH: %s\n", map->so_path);
	ft_printf("WE PATH: %s\n", map->we_path);
	ft_printf("EA PATH: %s\n", map->ea_path);
	ft_printf("COLOR: F: %s\n", map->f_color);
	ft_printf("COLOR: C: %s\n", map->c_color);
	while (map->map[++i])
		ft_printf("%s\n", map->map[i]);
	ft_printf("-------------------------------\n");
}

int	ft_read_file(t_game *info, int fd)
{
//	t_map	map;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("LLEGO--\n");
		if (!ft_read_info(info->map, line)) //si hay alguno repe debería salir
			return (0);
		if (info->map->counter == 6) //si ya tengo cargados los 6 datos
		{
			if(!ft_get_map(fd, info->map))
				return (0);
		}
	}
//	ft_print_map(info->map);
	return (1);
}
