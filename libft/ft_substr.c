/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:11:53 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/28 09:29:07 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’*/

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (s[start] != '\0' && start < ft_strlen(s) && i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	return (sub);
} */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;

	if (!s)
		return (0);
	if ((size_t)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	s_copy = malloc((len + 1) * sizeof(char));
	if (s_copy == NULL)
		return (0);
	ft_memcpy(s_copy, s + start, len);
	s_copy[len] = '\0';
	return (s_copy);
}
