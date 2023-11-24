/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/24 12:40:50 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_parse(t_game *info, int fd)
{
	if (ft_read_file(info, fd))
		printf("1-> lectura del file correcta\n");
	close(fd);
	ft_print_map(info->map);
}

int	ft_arg_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_error(ARG, NULL));
	if (ft_check_ext(av[1], ".cub") == -1)
		return (ft_error(EXT, NULL));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(FD, NULL));
	return (fd);
}

int	ft_check_ext(char *str, char *ext)
{
	int		i;
	char	*tmp;

	if (ft_strchr(str, '.') != 0)
	{
		i = ft_strlen(str);
		while (str[i] != '.')
			i--;
		tmp = &str[i];
		if (!ft_strcmp(tmp, ext))
			return (0);
	}
	return (-1);
}
