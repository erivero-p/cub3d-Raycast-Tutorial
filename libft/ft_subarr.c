/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:31:28 by erivero-          #+#    #+#             */
/*   Updated: 2023/11/28 10:36:11 by erivero-         ###   ########.fr       */
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
	ft_printf("start: %d, len: %d\n", start, len);
	cpy = malloc(sizeof(char **) * (len + 1));
	if (!cpy)
		return (NULL);
	while (arr[start + i] && i < len)
	{
		cpy[i] = ft_strdup(arr[start + i]);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
