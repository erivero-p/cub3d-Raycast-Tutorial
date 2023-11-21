/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:13:25 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/11/08 13:48:13 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insertstr(char *orig, int start, int len, char *replace)
{
	char	*f_str;
	char	*l_str;
	char	*f_half;
	char	*final;

	f_str = ft_substr(orig, 0, start);
	l_str = ft_substr(orig, start + len, ft_strlen(orig) - start + len);
	if (!replace)
	{
		final = ft_strjoin(f_str, l_str);
		return (free(f_str), free(l_str), free(orig), free(replace), final);
	}
	f_half = ft_strjoin(f_str, replace);
	final = ft_strjoin(f_half, l_str);
	return (free(f_str), free(l_str), free(f_half), free(orig),
		free(replace), final);
}
