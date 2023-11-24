/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:36:34 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:35:18 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*like malloc, calloc allocated memory. Th e allocated memory is aligned such
that it can be used for any data type. The free function frees allocations that
were created via the preceding allocation functions.
calloc function contiguosly allocates enough space for count objects that are
size bytes of memory each and returns a pointer to the allocated memory is
aligned on a page boundary.*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
