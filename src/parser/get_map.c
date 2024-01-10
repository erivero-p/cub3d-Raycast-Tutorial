/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:26 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/10 11:16:05 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

char	*ft_space_fill(char *str, int max)
{
	int		len;
	char	*spaced;

	spaced = ft_strtrim(str, "\n");
	len = ft_strlen(spaced);
	while (len++ < max)
		spaced = ft_strjoin_sl(spaced, " ");
	return (spaced);
}

char	**ft_get_spaced_map(char **arr, int start, int len, int max)
{
	char	**cpy;
	int		i;

	i = 0;
	if (len > ft_arrlen(arr))
		return (NULL);
	cpy = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	while (arr[start + i] && i < len)
	{
		cpy[i] = ft_space_fill(arr[start + i], max);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
