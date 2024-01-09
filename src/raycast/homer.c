#include "../../inc/cub3D.h"


/* mlx_texture_t *ft_homerizer(t_game *game, int frame)
{
	static int	i = -2;
	mlx_texture_t	*txt;

	if (i == -6 || i == 6)
		txt = game->homer->h6;
	if (i == -5 || i == 5)
		txt = game->homer->h5;
	if (i == -4 || i == 4)
		txt = game->homer->h4;
	if (i == -3 || i == 3)
		txt = game->homer->h0;
	if (i == -2 || i == 2)
		txt = game->homer->h1;
	else if (i == -1 || i == 1)
		txt = game->homer->h2;
	else if (i == 0)
		txt = game->homer->h3;
	if (frame % 2 == 0)
	{
		//printf("i: %d\n", i);
		i++;
		if (i == 3)
			i = -3;
	}
	return (txt);
} */
mlx_texture_t *ft_homerizer(t_game *game, int frame)
{
	static int	i = -3;
	mlx_texture_t	*txt;

	if (i == -6 || i == 6)
		txt = game->homer->h6;
	if (i == -5 || i == 5)
		txt = game->homer->h5;
	if (i == -4 || i == 4)
		txt = game->homer->h4;
	if (i == -3 || i == 3)
		txt = game->homer->h3;
	else if (i == -2 || i == 2)
		txt = game->homer->h2;
	else if (i == -1 || i == 1)
		txt = game->homer->h1;
	else if (i == 0)
		txt = game->homer->h0;
	if (frame == 2 || frame == 5)
	{
		printf("i: %d\n", i);
		i++;
		if (i == 6)
			i = -6;
	}
	return (txt);
}
