/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:41:14 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/11/21 12:48:24 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_next(char *st_ac)
{
	int		i;
	int		j;
	char	*ret_str;

	i = 0;
	while (st_ac[i] != '\0' && st_ac[i] != '\n')
		i++;
	if (st_ac[i] == '\0')
	{
		free(st_ac);
		return (NULL);
	}
	ret_str = ft_calloc((ft_strlen(st_ac) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (st_ac[i] != '\0')
		ret_str[j++] = st_ac[i++];
	free(st_ac);
	if (ret_str[0] == '\0')
	{
		free(ret_str);
		return (NULL);
	}
	return (ret_str);
}

static char	*get_line(char *st_ac)
{
	char	*ret_str;
	int		i;

	i = 0;
	if (st_ac[i] == '\0')
		return (NULL);
	while (st_ac[i] != '\0' && st_ac[i] != '\n')
		i++;
	ret_str = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (st_ac[i] != '\0' && st_ac[i] != '\n')
	{
		ret_str[i] = st_ac[i];
		i++;
	}
	if (st_ac[i] != '\0' && st_ac[i] == '\n')
		ret_str[i++] = '\n';
	return (ret_str);
}

static char	*get_joint(char *st_ac, char *buff)
{
	char	*r;

	r = ft_strjoin(st_ac, buff);
	free(st_ac);
	return (r);
}

static char	*get_piece(int fd, char *st_ac)
{
	char	*tmp;
	int		read_char;

	if (!st_ac)
		st_ac = ft_calloc(1, sizeof(char));
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_char = 1;
	while (read_char > 0)
	{
		read_char = read(fd, tmp, BUFFER_SIZE);
		if (read_char < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_char] = '\0';
		st_ac = get_joint(st_ac, tmp);
		if (ft_strchr_mod(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (st_ac);
}

char	*get_next_line(int fd)
{
	static char	*st_ac;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (st_ac != NULL)
		{
			free(st_ac);
			st_ac = NULL;
		}
		return (NULL);
	}
	st_ac = get_piece(fd, st_ac);
	line = get_line(st_ac);
	st_ac = get_next(st_ac);
	return (line);
}
