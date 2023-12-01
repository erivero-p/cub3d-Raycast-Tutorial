/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:31:28 by erivero-          #+#    #+#             */
/*   Updated: 2023/12/01 13:32:47 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_subarr(char **arr, int start, int len)
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
		cpy[i] = ft_strtrim(arr[start + i], "\n");
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
