/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:13:29 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:43 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies len bytes from string src to string dst. The two strings may overlap;
the copy is always done in a non-destructive manner.
Returns the original valuen of dst.*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (0);
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else if (d < s)
		ft_memcpy(dst, src, len);
	return (dst);
}
