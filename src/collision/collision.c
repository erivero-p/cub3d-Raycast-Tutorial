/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:14:14 by marirodr          #+#    #+#             */
/*   Updated: 2024/01/08 18:59:29 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

bool	ft_sidecoll(t_game *info, float angle, t_coord mod)
{
	t_coll	coll;
		
	mod.y -= 0.25;
	while (mod.y <= 0.25)
	{
		coll = ft_ray_caster(info, angle, mod);
		if (coll.raylen < 0.38)
			return (true);
		mod.y += 0.25;
	}
	return (false);
}

bool	ft_frontcoll(t_game *info, float angle, t_coord mod)
{
	t_coll	coll;
		
	mod.x -= 0.25;
	while (mod.x <= 0.25)
	{
		coll = ft_ray_caster(info, angle, mod);
		if (coll.raylen < 0.38)
			return (true);
		mod.x += 0.25;
	}
	return (false);
}

bool	ft_collision(t_game *info, float angle)
{
	t_coll	coll;
	t_coord	mod;
	float	rayangle;
	bool	ret;

	mod.x = 0;
	mod.y = 0;
	if (BONUS == 1)
	{
		mod.x -= 0.25;
		mod.y -= 0.25;
	}
	rayangle = info->player->angle + angle;
	if (rayangle > 360)
		rayangle -= 360;
	coll = ft_ray_caster(info, rayangle, mod);
	if (coll.txt == 1 || coll.txt == -1)
		ret = ft_sidecoll(info, rayangle, mod);
	else
		ret = ft_frontcoll(info, rayangle, mod);
	return (ret);
}