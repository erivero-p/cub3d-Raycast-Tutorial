/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:44:03 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/24 13:44:28 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_init(t_game *info)
{
	info->map = malloc(sizeof(t_map *));
	if (!info->map) //con los malloc y toa la pesca
		return ;
	info->map->no_path = NULL;
	info->map->so_path = NULL;
	info->map->we_path = NULL;
	info->map->ea_path = NULL;
	info->map->f_color = NULL;
	info->map->c_color = NULL;
	// info->map->map = NULL;
	// info->map->aux_map = NULL;
}
