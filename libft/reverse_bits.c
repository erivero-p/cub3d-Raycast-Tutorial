/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:55:21 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:40:19 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i--)
	{
		res = (res * 2) + (octet % 2);
		octet /= 2;
	}
	return (res);
}

/*int main()
{
	unsigned char octet = 38;

	printf("original value:%d\n", octet);
	printf("original value:%d\n", reverse_bits(octet));
}*/