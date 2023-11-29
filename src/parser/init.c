/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:44:53 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 12:31:26 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_init_map_struct(t_game *info)
{
	info->map = malloc(sizeof(t_map));
	info->map->no_path = NULL;
	info->map->so_path = NULL;
	info->map->we_path = NULL;
	info->map->ea_path = NULL;
	info->map->f_color = NULL;
	info->map->c_color = NULL;
	info->map->file = NULL;
	info->map->map = NULL;
	info->map->len_x = -1;
	info->map->len_y = -1;
	info->map->limit = -1;
	info->map->w = -1;
	info->map->h = -1;
}
