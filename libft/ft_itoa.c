/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:23:02 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:35:51 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates (with malloc) and returns a string representing the integer received
as an argument. Negative numbers must be handled.*/

static int	ft_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		nlen;
	char	*str;
	long	num;

	num = (long)n;
	nlen = ft_len(n);
	str = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!str)
		return (NULL);
	str[nlen] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	nlen--;
	while (nlen >= 0 && num != 0)
	{
		str[nlen] = (num % 10) + '0';
		num /= 10;
		nlen--;
	}
	return (str);
}
