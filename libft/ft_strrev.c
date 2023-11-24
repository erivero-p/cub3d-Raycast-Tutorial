/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:09:25 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:51 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Since we have to return the same string and we cannot use malloc, we must do it
by swapping the "first" and "last" position of the string, without using an 
auxiliary string. i is the counter that goes from back to front. j is the 
counter that goes from the beginning to the end. We don't have to add '\0' at 
the end because the string is actually the same and it already has it at i (end).
We subtract 1 from i after calculating the length of the string because strings
start from position 0 and what we have in i is an integer
*/

char	*ft_strrev(char *str)
{
	int		i;
	char	aux;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i -= 1;
	while (i > j)
	{
		aux = str[j];
		str[j] = str[i];
		str[i] = aux;
		i--;
		j++;
	}
	return (str);
}

/*int	main()
{
	char	str[25] = "Fear";

	printf("%s\n", ft_strrev(str));
}*/
