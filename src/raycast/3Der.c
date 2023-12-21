#include "../../inc/cub3D.h"

float 	ft_scalator(t_game *info, float angle, t_coll *coll)
{
	float	scale;
	float	len; //distancia al plano de proyección. Es fija
	float	distance; //distancia real al rayo
	float	deltang; //ángulo entre el rayo y el vector de dirección
//	t_coll	coll;
//	t_ray	ray;

	len = (WIDTH / 2) / tan(ft_deg_to_rad(FOV / 2));
	deltang = info->player->angle - angle;
//	deltang = 270 - angle;

	coll->distance = coll->raylen * cos(ft_deg_to_rad(deltang));
//	distance = ft_ray_caster(info, angle) * cos(ft_deg_to_rad(deltang));
	scale = WALL_H / coll->distance; // * len; dice yolanthe que no hace falta el len pa na
//	printf("%sft_scalator:\nlen: %f, deltang: %f, distance: %f, scale: %f%s\n", DEBUG_COLOR, len, deltang, distance, scale, END);
	return (scale);
}

void	ft_draw_col(t_game	*info, float scale, int	coll, int txt)
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
			mlx_put_pixel(info->scene->canvas, coll, j, BLUE);
		else if (j > bot)
			mlx_put_pixel(info->scene->canvas, coll, j, GREEN);
		else
		{
			if (txt == 1) // E
				mlx_put_pixel(info->scene->canvas, coll, j, PINK);
			if (txt == -1) // W
				mlx_put_pixel(info->scene->canvas, coll, j, BLACK);
			if (txt == 2) // S
				mlx_put_pixel(info->scene->canvas, coll, j, WHITE);
			if (txt == -2) // N
				mlx_put_pixel(info->scene->canvas, coll, j, RED);
		}
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

void	ft_ray_tester(t_game *info)
{
	t_ray	ray;

	ft_ray_caster(info, 45);
//	ft_print_ray(&ray, WRONG);
	ft_ray_caster(info, 135);
//	ft_print_ray(&ray, DEBUG2);
	ft_ray_caster(info, 225);
//	ft_print_ray(&ray, GOOD);
	ft_ray_caster(info, 315);
//	ft_print_ray(&ray, DEBUG_COLOR);
}

void	ft_3Der(void *param)
{
	t_game	*info;
	float	angle;
	double	a; //Yolanthe dice que el aumento del ángulo no es uniforme así que tengo que arreglar esto
	float	scale;
	t_coll	coll;
	int		i;
	int		j;

	info = (t_game *)param;
	ft_redisplay(info);
	angle = info->player->angle - (FOV / 2); //empezamos a lanzar desde -45 y hasta +45
	a = 0.08333; //lo que tengo que aumentar el ángulo en cada iteración (mentira T_T)
	i = 0;
	if (angle < 0)
		angle += 360;
//	ft_test(info, 1080/2);
//	ft_ray_tester(info);
	while (i < WIDTH)
	{
		coll = ft_ray_caster(info, angle);
		scale = ft_scalator(info, angle, &coll);
		ft_draw_col(info, scale, i, coll.txt); // (?)
		i++;
//		printf("\033[38mft_3Der angle is: %f\n%s", angle, END);
		angle += a;
		if (angle >= 360)
			angle -= 360;
	}
}
