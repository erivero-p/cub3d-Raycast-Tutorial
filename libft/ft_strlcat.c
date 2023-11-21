/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:55:24 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/11/21 12:41:18 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	ret;

	a = 0;
	b = 0;
	ret = 0;
	while (dest[a] != '\0')
		a++;
	while (src[ret] != '\0')
		ret++;
	if (size <= a)
		ret += size;
	else
		ret += a;
	while (src[b] != '\0' && (a + 1) < size)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (ret);
}
