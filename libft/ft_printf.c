/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:01 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:36:57 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*printf function prints a string on the screen using a "format string" that 
includes the instructions to mix several strings and produce the final string
to be printed on the srceen.
*count is a pointer that save the lenght of the final string.*/

#include "libft.h"

static void	ft_control(const char c, va_list args, int *count)
{
	if (c == 'c')
		ft_printchar(va_arg(args, int), count);
	else if (c == 's')
		ft_printstr(va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(args, int), count);
	else if (c == 'u')
		ft_printunsigned(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_printhex(va_arg(args, unsigned int), count, 'x');
	else if (c == 'X')
		ft_printhex(va_arg(args, unsigned int), count, 'X');
	else if (c == 'p')
		ft_printpointer(va_arg(args, void *), count);
	else if (c == '%')
		ft_printchar('%', count);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			count;
	va_list		args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			ft_printchar(s[i], &count);
			i++;
		}
		if (s[i] == '%')
		{
			i++;
			ft_control(s[i], args, &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
