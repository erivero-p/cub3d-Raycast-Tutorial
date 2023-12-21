/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:14:14 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/21 13:07:38 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_frontal_collision(t_game *game, int y, int x)
{
	int	lim;
	int	size;

	lim = x + 4;
	size = (int)game->scene->tile;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d / size: %d\n", lim, size);
	printf("(y - 30) / size: %d / (x - 30) / size: %d\n", (y - 30) / size, (x - 30) / size);
	while (x < lim)
	{
		if (game->scene->map[(y - 30) / size][(x - 30) / size] == '1') //size ->scene.tile
		{
			printf("%sNO PUEDES PASAR%s\n", GOOD, END);
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_back_collision(t_game *game, int y, int x)
{
	int	lim;
	int	size;

	lim = x + 4;
	size = (int)game->scene->tile;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d\n", lim);
	while (x < lim)
	{
		if (game->scene->map[(y + 4 - 30) / size][(x - 30) / size] == '1')
		{
			printf("%sNO PUEDES PASAR%s\n", GOOD, END);
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_left_collision(t_game *game, int y, int x)
{
	int	lim;
	int	size;

	lim = y + 4;
	size = (int)game->scene->tile;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d\n", lim);
	while (y < lim)
	{
		if (game->scene->map[(y - 30) / size][(x - 30) / size] == '1')
		{
			printf("%sNO PUEDES PASAR%s\n", GOOD, END);
			return (1);
		}
		y++;
	}
	return (0);
}

int	ft_right_collision(t_game *game, int y, int x)
{
	int	lim;
	int	size;

	lim = y + 4;
	size = (int)game->scene->tile;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d\n", lim);
	while (y < lim)
	{
		if (game->scene->map[(y - 30) / size][(x + 4 - 30) / size] == '1')
		{
			printf("%sNO PUEDES PASAR%s\n", GOOD, END);
			return (1);
		}
		y++;
	}
	return (0);
}
