/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:14:14 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/20 16:35:14 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_frontal_collision(t_game *game, int y, int x)
{
	int	lim;

	lim = x + 14;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d\n", lim);
	while (x < lim)
	{
		if (game->scene->map[(y - 30) / 15][(x - 30) / 15] == '1')
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

	lim = x + 14;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d\n", lim);
	while (x < lim)
	{
		if (game->scene->map[(y + 14 - 30) / 15][(x - 30) / 15] == '1')
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

	lim = y + 14;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d\n", lim);
	while (y < lim)
	{
		if (game->scene->map[(y - 30) / 15][(x - 30) / 15] == '1')
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

	lim = y + 14;
	printf("en ft_sy: %d / x: %d\n", y, x);
	printf("en lim: %d\n", lim);
	while (y < lim)
	{
		if (game->scene->map[(y - 30) / 15][(x + 14 - 30) / 15] == '1')
		{
			printf("%sNO PUEDES PASAR%s\n", GOOD, END);
			return (1);
		}
		y++;
	}
	return (0);
}
