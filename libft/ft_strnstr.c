/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:50:13 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:46 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*function locates the first occurrence of the null-terminated string needle in
the string haystack, where not more than len characters (in haystack) are sear-
ched. Characters that appear after a `\0' character are not searched.
If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the first
character of the first occurrence of needle is returned.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (needle[0] == '\0')
		return ((char *)haystack);
	h = 0;
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			while (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[h]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)&haystack[h]);
		h++;
	}
	return (0);
}

/*int main () 
{
	const char haystack[40] = "yo soy rosa, yo lima, y yo lavanda";
	const char needle[10] = "lima";
	char *result;

    result = ft_strnstr(haystack, needle, 40);
	printf("The substring is: %s\n", result);
	printf("original:%s\n", strnstr(haystack, needle, 40));
	return(0);
}*/
