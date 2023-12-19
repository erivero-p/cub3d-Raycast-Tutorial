#include "../../inc/cub3D.h"

float 	ft_scalator(t_game *info, float angle)
{
	float	scale;
	float	len; //distancia al plano de proyección. Es fija
	float	distance; //distancia real al rayo
	float	deltang; //ángulo entre el rayo y el vector de dirección

	len = (WIDTH / 2) / tan(ft_deg_to_rad(FOV / 2));
//	deltang = info->player->angle - angle;
	deltang = 270 - angle;
//	distance = ft_ray_caster(info, angle) * cos(ft_deg_to_rad(deltang));
	distance = 10;
	scale = WALL_H / distance; // * len; dice yolanthe que no hace falta el len pa na
//	printf("%sft_scalator:\nlen: %f, deltang: %f, distance: %f, scale: %f%s\n", DEBUG_COLOR, len, deltang, distance, scale, END);
	return (scale);
}

void	ft_draw_coll(t_game	*info, float scale, int	coll)
{
	int	j;
	int	top; //el pixel de arriba del todo del muro
	int	bot;
	int	wall; //altura del muro en píxeles?

//	wall = WALL_H / scale; //digo yo que la pared mide en píxeles su altura entre la escala
	wall = scale;
	top = HEIGHT / 2 - wall / 2;
	bot = top + wall;
//	printf("ft_draw_coll:\nwall: %i, top: %i, bot: %i\n", wall, top, bot);
	j = 0;
	while (j < HEIGHT)
	{
		if (j < top)
			mlx_put_pixel(info->canvas, coll, j, BLUE);
		else if (j > bot)
			mlx_put_pixel(info->canvas, coll, j, GREEN);
		else
			mlx_put_pixel(info->canvas, coll, j, PINK); //se supone que es naranja clarito
		//cuando j sea top habrá que empezar a pintar muro
		//cuando j sea top + wall habrá que dejar de pintar muro
		j++;
	}
}

/* void	ft_test(t_game *info, int i)
{
//	printf("\033[95mft_test:\n");
	float angle = 270;
	float scale = ft_scalator(info, angle);
	printf("\033[95mft_test:\nangle: %f\nscale: %f\ni: %i\n", angle, scale, i);
	ft_draw_coll(info, scale, i);
	printf("%s\n", END);
} */

void	ft_3Der(t_game *info)
{
	float	angle;
	double	a; //Yolanthe dice que el aumento del ángulo no es uniforme así que tengo que arreglar esto
	float	scale;
	int		i;
	int		j;

//	angle = info->player->angle - (FOV / 2); //empezamos a lanzar desde -45 y hasta +45
	angle = 270 - (FOV / 2); //empezamos a lanzar desde -45 y hasta +45
	a = 0.08333; //lo que tengo que aumentar el ángulo en cada iteración (mentira T_T)
	i = 0;
	if (angle < 0)
		angle += 360;
//	ft_test(info, 1080/2);
	while (i < WIDTH)
	{
		scale = ft_scalator(info, angle);
		ft_draw_coll(info, scale, i); // (?)
		i++;
//		printf("\033[38mft_3Der angle is: %f\n%s", angle, END);
		angle += a;
		if (angle > 359)
			angle -= 360;
	}
}
