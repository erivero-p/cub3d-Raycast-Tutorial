#include "../../inc/cub3D.h"

int	ft_len_file(int fd)
{
	char	*line;
	int		len;

	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), ft_error(EMPTY, NULL));
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

void	ft_read_file(t_scene *scene, int fd, int len, char *file)
{
	char	*line;
	int		i;

	i = 0;
	scene->file = (char **)ft_calloc(sizeof(char *), len + 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
//		scene->file[i] = ft_strtrim(line, "\n");
//		ft_printf("ft_read_file saved: \'%s\'\n", scene->file[i]);
		scene->file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
//	ft_print_matrix(scene->file, DEBUG_COLOR);
	free(line);
}