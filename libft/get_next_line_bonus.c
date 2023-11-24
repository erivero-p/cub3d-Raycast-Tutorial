/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:55:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:38:26 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc_gnl(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	leftover = ft_calloc_gnl(ft_strlen_gnl(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i] != '\0')
	{
		leftover[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (leftover);
}

char	*ft_read_line(int fd, char *buffer)
{
	char	*tmp;
	int		n;

	tmp = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	n = 1;
	while (n != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		tmp[n] = '\0';
		buffer = ft_strjoin_gnl(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4296];
	char		*line;

	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}

/*int	main(void)
{
	int	fd;
	char	*str;

	fd = 0;
	str = get_next_line(fd);
	if (fd == -1)
	{
		perror ("open");
		exit(EXIT_FAILURE);
	}
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
