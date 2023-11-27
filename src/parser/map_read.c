#include "../../inc/cub3D.h"

void	ft_print_map(t_map *map)
{
	int	i = -1;

	ft_printf("-------------------------------\n");
	if (map->no_path)
		ft_printf("NO PATH: %s\n", map->no_path);
	if (map->so_path)
		ft_printf("SO PATH: %s\n", map->so_path);
	if (map->we_path)
		ft_printf("WE PATH: %s\n", map->we_path);
	if (map->ea_path)
		ft_printf("EA PATH: %s\n", map->ea_path);
	if (map->f_color)
		ft_printf("COLOR: F: %s\n", map->f_color);
	if (map->c_color)
		ft_printf("COLOR: C: %s\n", map->c_color);
	ft_printf("---------------MAP-------------\n");
	if (*map->map)
	{
		while (map->map[++i])
			ft_printf("%s\n", map->map[i]);
	}
	ft_printf("-------------------------------\n");
}

char	*ft_cpy_info(char *line)
{
	while (*line && *line > 32) //salto hasta enontrar un espacio
		line++;
	while (*line > 0 && *line < 33) //salto los espacios tras el nombre
		line++;
	return (ft_strdup(line));
}

int	ft_save_info(t_map *map, char *line)
{
	static int	count = 0;

	while (*line > 0 && *line < 32)
		line++;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO	", 3))
		map->no_path = ft_cpy_info(line);
	else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO	", 3))
		map->so_path = ft_cpy_info(line);
	else if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE	", 3))
		map->we_path = ft_cpy_info(line);
	else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA	", 3))
		map->ea_path = ft_cpy_info(line);
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F	", 3))
		map->f_color = ft_cpy_info(line);
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C	", 3))
		map->c_color = ft_cpy_info(line);
	else
		return (1);
	count++;
	if (count > 6)
		return (ft_error(FORMAT, "Each parameter can't appear more than once"));
	return (0);
}

char **ft_subarr(char **arr, int start, int len)
{
	char	**cpy;
	int		i;

	i = 0;
	if (len > ft_arrlen(arr))
		return (NULL);
	ft_printf("start: %d, len: %d\n", start, len);
	cpy = malloc(sizeof(char **) * (len + 1));
	if (!cpy)
		return (NULL);
	while (arr[start + i] && i < len)
	{
		cpy[i] = ft_strdup(arr[start + i]);
		ft_printf("copying: [%d], %s\n", i, cpy[i]);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

int ft_get_map(char **file, t_map *map, int j)
{
	int		len;
	char	**cpy;

	if (!(map->no_path && map->so_path && map->we_path
		&& map->ea_path && map->f_color && map->c_color))
		return (ft_error(FORMAT, "All six parameter must be above the map"));
	len = 0;
	while(file[j + len])
		len++;
	ft_printf("len is: %i\n", len);
	map->map = ft_subarr(file, j, len);
	return (0);
}

int	ft_parse_file(t_map *map)
{
	int	j;
	int	i;
	int	ret;

	j = -1;
	ret = 0;
	while(map->file[j] && map->file[++j])
	{
		i = 0;
		while(map->file[j][0] == 10)
			j++;
		ret = ft_save_info(map, map->file[j]);
		if (ret == 1) //si no es ninguno de los parámetros salgo y guardo el mapa fuera del loop
			break ;
		if (ret == -1) //parámetro repe o get_map fallando
			return (-1);
	}
	ret = ft_get_map(map->file, map, j);
	ft_print_map(map);
	return (ret);
}
