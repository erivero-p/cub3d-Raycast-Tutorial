/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:40:55 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:54 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
specified in ’set’ removed from the beginning and the end of the string.*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*char_set;

	char_set = (char *)set;
	if (!s1 || !char_set)
		return (0);
	while (*s1 && ft_strchr(char_set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(char_set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
