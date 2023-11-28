/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/27 19:36:11 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("en ft_matrix_len matrix[%i]: %s\n", i, matrix[i]);
		i++;
	}
	return (-1);
}

int	ft_get_map_x(t_game *info)
{
	int	longest;
	int	i;

	i = 0;
	longest = 0;
	while (info->map->map[i])
	{
		if (ft_strlen(info->map->map[i]) > longest)
			longest = ft_strlen(info->map->map[i]);
		i++;
	}
	return (longest);
}

void	ft_init_map(t_game *info)
{
	ft_printf("%sLLEGO%s\n", BLUE, END);
	info->map->len_y = ft_matrix_len(info->map->map);
	ft_printf("%sla y/altura del map es: %i%s\n", BLUE, info->map->len_y, END);
	info->map->len_x = ft_get_map_x(info);
	ft_printf("%sla x/longuitud del map es: %i%s\n", BLUE, info->map->len_x, END);
}
