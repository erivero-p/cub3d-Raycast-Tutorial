/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:12:19 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/10 11:13:37 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_char_check(char c)
{
	int	ret;

	ret = 0;
	if (c > 0 && c < 33)
		ret = 1;
	if (c == '0' || c == '1')
		ret = 1;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ret = 42;
	return (ret);
}

int	ft_char_mapcheck(char **map)
{
	int	i;
	int	j;
	int	ret;
	int	count;

	j = -1;
	ret = 0;
	count = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			ret = ft_char_check(map[j][i]);
			if (!ret)
				return (ft_error(CHAR, NULL));
			if (ret == 42)
				count++;
		}
	}
	if (count != 1)
		return (ft_error(PLAYER, NULL));
	return (0);
}
