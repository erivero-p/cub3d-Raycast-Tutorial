/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:37:15 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:37:01 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*output a character to given file. The fputc() function writes the character c
(converted to an 'unsigned char') to the output stream pointed to by stream.*/

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
