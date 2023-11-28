/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/28 13:51:12 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
	info->map->len_y = ft_arrlen(info->map->map);
	//ft_printf("%sla y/altura del map es: %i%s\n", BLUE, info->map->len_y, END);
	info->map->len_x = ft_get_map_x(info);
	//ft_printf("%sla x/longuitud del map es: %i%s\n", BLUE, info->map->len_x, END);
}
