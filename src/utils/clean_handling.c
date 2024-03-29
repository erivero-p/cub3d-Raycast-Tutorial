/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:47:06 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/11 13:16:59 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_clean_map(t_game	*info)
{
	if (info->scene)
	{
		if (info->scene->map)
			ft_free_double_pointer(info->scene->map);
		if (info->scene->no_path)
			free(info->scene->no_path);
		if (info->scene->so_path)
			free(info->scene->so_path);
		if (info->scene->we_path)
			free(info->scene->we_path);
		if (info->scene->ea_path)
			free(info->scene->ea_path);
		if (info->scene->f_color)
			free(info->scene->f_color);
		if (info->scene->c_color)
			free(info->scene->c_color);
	}
	exit(0);
}
