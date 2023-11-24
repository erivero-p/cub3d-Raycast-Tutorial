/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:13:28 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:38 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Compares byte string s1 against byte string s2. Both strings are assumed to
be n bytes long.
Returns zero if the two strings are identical, otherwise returns the difference
between the first two differing bytes (treated as unsigned char values).
This behavior is not required by C and portable code should only depend on 
the sign of the returned value.*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)&s1[i] != *(unsigned char *)&s2[i])
			return (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i]);
		i++;
	}
	return (0);
}
