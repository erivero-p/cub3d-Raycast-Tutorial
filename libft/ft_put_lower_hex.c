/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lower_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:39:54 by hunter            #+#    #+#             */
/*   Updated: 2023/11/14 11:36:59 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_lower_hex(int nbr)
{
	if (nbr > 15)
	{
		ft_put_lower_hex(nbr / 16);
		ft_put_lower_hex(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr + 87);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_put_lower_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}
