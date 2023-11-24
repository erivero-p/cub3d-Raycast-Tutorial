/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:35:42 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/24 15:38:47 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_check_ext(char *str, char *ext)
{
	int		i;
	char	*tmp;

	if (ft_strchr(str, '.') != 0)
	{
		i = ft_strlen(str);
		while (str[i] != '.')
			i--;
		tmp = &str[i];
		if (!ft_strncmp(tmp, ext, 4))
			return (0);
	}
	return (-1);
}
