/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:14:27 by erivero-          #+#    #+#             */
/*   Updated: 2023/11/24 16:29:59 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrjoin(char **arr, char *str)
{
	int		i;
	char	**join;

	i = 0;
	if (!arr)
		return (NULL);
	join = malloc(ft_arrlen(arr) + 2 * sizeof(char *));
	if (!join)
		return (ft_arr_free(arr), NULL);
	while (arr[i])
	{
		join[i] = ft_strdup(arr[i]);
		i++;
	}
	join[i] = ft_strdup(str);
	join[++i] = NULL;
	return (ft_arr_free(arr), join);
}
