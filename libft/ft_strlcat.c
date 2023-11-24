/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:42:23 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:37 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Concatenate strings. take the full size of the buffer (not just the lenght)
and guarantee to NUL-terminate the result (as long as size is larger tha 0 or,
in the case od strlcat(), as long as there is at least one byte free in dst).
You should include a byte for the NUL in size. The strlcat() funtion appends
the NUL-terminated string src to the end of dst. It will append at most 
size - srtlen(dst) - 1 bytes, NUL-terminating the result.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	j = 0;
	if (size <= lend)
		return (lens + size);
	i = lend;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lend + lens);
}

/*int	main(void)
{
	char dest[10] = "ab";
	char src[10] = "zxy";
	int size = 2;
	printf("original:%lu\n", strlcat(dest, src, size));
	printf("ft_strlcat:%zu\n", ft_strlcat(dest, src, size));
}
*/