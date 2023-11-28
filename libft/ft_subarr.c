/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:31:28 by erivero-          #+#    #+#             */
/*   Updated: 2023/11/28 09:31:39 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
