/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:40:55 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/28 17:12:46 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	initial_pos(char const *s1, char const *set)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	while (s1[a])
	{
		while (set[b])
		{
			if (s1[a] == set[b])
			{
				a++;
				break ;
			}
			b++;
		}
		if (b == ft_strlen(set))
			return (a);
		b = 0;
	}
	return (0);
}

static int	final_pos(char const *s1, char const *set)
{
	int	len;
	size_t	j;

	len = 0;
	j = 0;
	while (s1[len])
		len++;
	while (len > 0)
	{
		while (set[j])
		{
			if (s1[len - 1] == set[j])
			{
				len--;
				break ;
			}
			j++;
		}
		if (j == ft_strlen((char *)set))
			return (len);
		j = 0;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		ini;
	int		fin;
	int		i;
	char	*ret_str;

	i = 0;
	ini = initial_pos(s1, set);
	fin = final_pos(s1, set);
	ret_str = ft_calloc((fin - ini + 1), sizeof(char));
	if (ret_str == NULL)
		return (NULL);
	while (ini < fin)
	{
		ret_str[i] = s1[ini];
		i++;
		ini++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
