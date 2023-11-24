/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/24 11:43:43 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_parse(t_game *info, int fd)
{
	if (ft_read_file(info, fd))
		printf("1-> lectura del file correcta\n");
	ft_print_map(info->map);
}

int	ft_arg_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("%sError\nWrong arguments%s\n", RED, END);
		return (-1);
	}
	if (ft_check_ext(av[1], ".cub") == -1)
	{
		ft_printf("\033[0;31mError\nThe map file doesn't have a valid extension. It must be .cub%s\n", END);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033[0;31mError\nProblem while opening file%s\n", END);
		return (-1);
	}
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
