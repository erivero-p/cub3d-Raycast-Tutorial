/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:58:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 11:43:07 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_get_scene_x(t_game *info)
{
	int	longest;
	int	i;

	i = 0;
	longest = 0;
	while (info->scene->map[i])
	{
		if (ft_strlen(info->scene->map[i]) > longest)
			longest = ft_strlen(info->scene->map[i]);
		i++;
	}
	return (longest);
}

void	ft_init_scene(t_game *info)
{
	info->scene->len_y = ft_arrlen(info->scene->map);
	//ft_printf("%sla y/altura del map es: %i%s\n", BLUE, info->scene->len_y, END);
	info->scene->len_x = ft_get_scene_x(info);
	//ft_printf("%sla x/longuitud del map es: %i%s\n", BLUE, info->scene->len_x, END);
}
