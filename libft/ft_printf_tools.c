/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:12:27 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:54 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_printstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
		ft_printstr("(null)", count);
	else
	{
		while (str[i])
		{
			ft_printchar(str[i], count);
			i++;
		}
	}
}

void	ft_printnbr(int nb, int *count)
{
	if (nb == -2147483648)
		ft_printstr("-2147483648", count);
	else
	{
		if (nb < 0)
		{
			ft_printchar(('-'), count);
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_printnbr((nb / 10), count);
			ft_printchar((nb % 10 + 48), count);
		}
		else
			ft_printchar((nb + 48), count);
	}
}

void	ft_printunsigned(unsigned int nb, int *count)
{
	if (nb > 9)
	{
		ft_printunsigned((nb / 10), count);
		ft_printchar((nb % 10 + 48), count);
	}
	if (nb <= 9)
		ft_printchar((nb + 48), count);
}
