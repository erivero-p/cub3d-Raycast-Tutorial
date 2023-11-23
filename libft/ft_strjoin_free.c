/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:16 by erivero-          #+#    #+#             */
/*   Updated: 2023/11/23 14:54:24 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;
	size_t	len;
	int		i;
	int		a;

	i = 0;
	a = 0;
	len = ((size_t)ft_strlen(s1) + (size_t)ft_strlen(s2));
	join = (char *)malloc(((len + 1) * sizeof(char)));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[a])
	{
		join[i + a] = s2[a];
		a++;
	}
	join[i + a] = '\0';
	return (free(s1), join);
}
