/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:56:47 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:45 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Compare lexicographically the null_terminated strings s1 and s2. This
function reversely compares not more tha n characters. Because is designed for
comparing strings rather than binary data, characters that appear a '\0' 
character are not compared.
return an integer greater than, equal to, or less than 0, according as the
string s1 is greater than, equal to, or less than the string s2.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
