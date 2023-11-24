/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:24:47 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:18 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Locates the first occurrence of c (converted to a char) in the string pointed
to by s. The terminating null character is considered to be part of the string;
therefore if c is '\0', the functions locate the terminating '\0'.*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if ((*ptr) == (char)c)
			return (ptr);
		ptr++;
	}
	if ((char)c == *ptr)
		return (ptr);
	return (0);
}

/*    size_t i;

    i = 0;
    while (s[i])
    {
        if (str[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    if ((char)c == s[i])
        return ((char *)&s[i]);
    return (NULL);*/