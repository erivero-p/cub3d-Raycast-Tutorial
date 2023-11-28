#include "../../inc/cub3D.h"


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
	char	*tmp;

	tmp = ft_strtrim(line, "   	");
	if (!ft_strncmp(tmp, "NO ", 3) || !ft_strncmp(tmp, "NO	", 3))
		map->no_path = ft_cpy_info(line);
	else if (!ft_strncmp(tmp, "SO ", 3) || !ft_strncmp(tmp, "SO	", 3))
		map->so_path = ft_cpy_info(line);
	else if (!ft_strncmp(tmp, "WE ", 3) || !ft_strncmp(tmp, "WE	", 3))
		map->we_path = ft_cpy_info(line);
	else if (!ft_strncmp(tmp, "EA ", 3) || !ft_strncmp(tmp, "EA	", 3))
		map->ea_path = ft_cpy_info(line);
	else if (!ft_strncmp(tmp, "F ", 2) || !ft_strncmp(tmp, "F	", 3))
		map->f_color = ft_cpy_info(line);
	else if (!ft_strncmp(tmp, "C ", 2) || !ft_strncmp(tmp, "C	", 3))
		map->c_color = ft_cpy_info(line);
	else
		return (free(tmp), 1);
	count++;
	if (count > 6)
		return (free(tmp), ft_error(FORMAT, "Each parameter can't appear more than once"));
	return (free(tmp), 0);
}

char **ft_subarr(char **arr, int start, int len)
{
	char	**cpy;
	int		i;

	i = 0;
	if (len > ft_arrlen(arr))
		return (NULL);
	ft_printf("start: %d, len: %d\n", start, len);
	cpy = malloc(sizeof(char *) * (len + 1));
	//cpy = (char **)ft_calloc_gnl(len + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	while (arr[start + i] && i < len)
	{
		cpy[i] = ft_strdup(arr[start + i]);
		i++;
	}
	cpy[i] = NULL;
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
