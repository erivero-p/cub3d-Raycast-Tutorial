/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:46:52 by erivero-          #+#    #+#             */
/*   Updated: 2024/01/12 14:02:29 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D_bonus.h"

static void	ft_print_fileformat(char *str)
{
	printf("%sError\nIncorrect file format%s\n", WRONG, END);
	if (*str)
		printf("%s%s%s\n", WRONG, str, END);
	printf("Please input a file as described below:\n");
	printf("Floor, ceiling, north, south, east, and west "
		"textures should appear at the beginning of the file, "
		"separated by one or more newlines, and in any desired order.\n");
	printf("The map should be the last element in the file.\n");
}

void	ft_parse_errors(int err, char *str)
{
	if (err == ARG)
		printf("%sError\nWrong input%s\n", WRONG, END);
	if (err == EXT_CUB)
		printf("%sError\nThe map file doesn't have "
			"a valid extension. It must be .cub%s\n", WRONG, END);
	if (err == EXT_PNG)
		printf("%sError\nThe texture file doesn't have "
			"a valid extension. It must be .png%s\n", WRONG, END);
	if (err == FD)
		printf("%sError\nProblem while opening file%s\n", WRONG, END);
	if (err == FORMAT)
		ft_print_fileformat(str);
	if (err == WALL)
		printf("%sError\nThe map must be surrounded by walls%s\n", WRONG, END);
	if (err == CHAR)
		printf("%sError\nThe map contains invalid characters%s\n", WRONG, END);
	if (err == EMPTY)
		printf("%sError\nInvalid file, empty map%s\n", WRONG, END);
	if (err == PLAYER)
		printf("%sError\nThe map must have one player"
			"position%s\n", WRONG, END);
	if (err == COLOR)
		printf("%sError\nIncorrect colour format%s\n", WRONG, END);
}

void	ft_mlx_errors(int err, char *str)
{
	if (err == WINDOW)
		printf("%sError while opening the window\n%s%s\n", WRONG, str, END);
	if (err == IMAGE)
		printf("%sError while rendering an image\n%s%s\n", WRONG, str, END);
}

int	ft_error(int err, char *str)
{
	if (err == 42)
		printf("%sError\n%s%s\n", WRONG, str, END);
	ft_parse_errors(err, str);
	ft_mlx_errors(err, str);
	return (-1);
}
