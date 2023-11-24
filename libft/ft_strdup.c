/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:52:55 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:26 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*allocates sufficient memory for a copy of the string s1, does the copy, and
returns a pointer to it. The pointer may subsequently be used as an argument
to the function free(3).*/

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!s1)
		return (0);
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
