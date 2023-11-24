/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:48:20 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:40:21 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;
	int				tmp;

	a = 0;
	b = a + 1;
	while (b < size)
	{
		if (tab[a] > tab[b])
		{
			tmp = tab[a];
			tab[a] = tab[b];
			tab[b] = tmp;
			a = 0;
			b = a + 1;
		}
		else
		{
			a++;
			b++;
		}
	}
}

/*void	print_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;

	while (i <= size - 1)
	{
		printf("[%d]", tab[i]);
		i++;
	}
	printf("\n");
}

int	main()
{
	int	tab[] = {2, 5, 1, 0, 4, -9};
	unsigned int size = 6;

	print_tab(tab, size);
	sort_int_tab(tab, size);
	print_tab(tab, size);
}*/