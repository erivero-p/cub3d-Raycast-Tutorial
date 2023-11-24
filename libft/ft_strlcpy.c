/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:42:04 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:39 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*coty strings. take the full size of the buffer (not just the length) and
guarantee to NUL-terminate the result (as long as size is larger than 0.
Note that you should include a byte for the NUL in size.Also note that strlcpy()
only operate on true 'C' strings. This means that src must be NUL-terminated.It
will append at most size - srtlen(dst - 1 bytes, NUL-terminating the result*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize > 0)
	{
		while ((src[i] != '\0') && (i < (destsize - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}
