/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:56:49 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:55 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printhex(unsigned long hex, int *count, char x)
{
	if (hex >= 16)
	{
		ft_printhex((hex / 16), count, x);
		ft_printhex((hex % 16), count, x);
	}
	if (hex < 16)
	{
		if (hex < 10)
			ft_printchar((hex + 48), count);
		else
		{
			if (x == 'x')
				ft_printchar((hex + 87), count);
			if (x == 'X')
				ft_printchar((hex + 55), count);
		}
	}
}

/* %p is used for printing the value of a pointer in C. For ejemple, we have 
a integer i = 100 and a pointer k that points toward the adress of i. Then, 
when we use prinft("%p", i), the result is 64 becase thats 100 in hexadecimal,
but if we use printf("%p", k), we print the value inside the pointer.*/

void	ft_printpointer(void *ptr, int *count)
{
	ft_printstr(("0x"), count);
	ft_printhex(((unsigned long long)ptr), count, 'x');
}
