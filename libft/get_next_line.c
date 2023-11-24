/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:55:48 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/14 11:39:17 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function is used to read a line from the buffer that we are reading, in
order to later return it.*/

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

/*This function serves to free the buffer of the previously read line, and keep
only what could be stored of the next one, in order to later store that remainder
in the static variable (here 'leftover') when it goes through get_next_line.*/

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
	leftover = ft_calloc_gnl(ft_strlen(buffer) - i + 1, sizeof(char));
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

/*This function replicates the functionality of read(), as it takes the value
of BUFFER_SIZE to read the same amount of bytes.

In addition, it is the one that concatenates the read lines, because we can not
read the entire file at once. Therefore, we will be returning line by line and 
maintaining the position of the 'cursor' thanks to the static variable.*/

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
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

/*This function actually doesn't do much, because the different actions are
performed by the other three, but it gives execution order and adds some error
checks.*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = 0;
// 	if (fd == -1)
// 	{
// 		perror ("open");
// 		exit(EXIT_FAILURE);
// 	}
// 	str = get_next_line(fd);
// 	while (ft_strcmp(str, "EOF\n") != 0)
// 	{
// 		printf("%s", str);
// 	}
// 	close(fd);
// 	return (0);
// }
