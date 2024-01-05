#include "../../inc/cub3D.h"

/* t_homer	ft_load_homer(t_game *info)
{
	t_homer	homer;

	homer.h0 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homernt.png");
/* 	homer.h7 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homer7.png");
	homer.h6 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homer6.png");
	homer.h5 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homer5.png");
	homer.h4 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homer4.png");
	homer.h3 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homer3.png");
	homer.h2 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homer2.png");
	homer.h1 = mlx_load_png("/Users/erivero-/Desktop/coll-cub3d/homer/homer1.png");
	if (!homer.h0 || homer.h1)
		return (ft_error(IMAGE, NULL), homer);
	return (homer);
} */

mlx_texture_t *ft_homerizer(t_game *game, int col)
{
	static int	i = 0;

	if (i == 1)
	{
		i = 0;
		return (game->homer.h1);
	}
	else
		return (game->homer.h0);
	if (col == WIDTH - 1)
		i++;
}
/* mlx_texture_t *ft_homerizer(t_game *game, int col)
{
	static int	i = -8;
	t_homer homer = ft_load_homer();

	if (i > 7)
		i = -8;
	if (i == -8 || i == 8)
		return (homer.h0);
	else if (i == -7 || i == 7)
		return (homer.h7);
	else if (i == -6 || i == 6)
		return (homer.h6);
	else if (i == -5 || i == 5)
		return (homer.h5);
	else if (i == -4 || i == 4)
		return (homer.h4);
	else if (i == -3 || i == 3)
		return (homer.h3);
	else if (i == -2 || i == 2)
		return (homer.h2);
	else if (i == -1 || i == 1)
		return (homer.h1);
	else if (i == 0)
		return (homer.h1);
	if (col == WIDTH - 1)
	{
		printf("holi se supone que he actualizado i xd\n");
		i++;
	}
} */
