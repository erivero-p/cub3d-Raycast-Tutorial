#include <stdio.h>
#include <math.h>

#define FOV 90.0  // Ángulo de visión total en grados
#define WIDTH 1080 // Ancho del plano de proyección en píxeles

double	ft_deg_to_rad(double deg)
{
	double	rad;

	rad = deg * (M_PI / 180.0);
	return (rad);
}

void    ft_socorro(int i, int seno, int coseno, double deltang, double rayangle)
{
    if (i % 100 == 0)
    {
        printf("ray nº: %i\n", i);
        printf("sin: %i, cos: %i, deltang: %f, rayangle: %f\n", seno, coseno, deltang, rayangle);
    }
}

double	ft_rayangle(int	i, double angle)
{
	int	seno = (WIDTH / 2) / tan(ft_deg_to_rad(FOV / 2)); //esta es la distancia del personaje al plano de proyección
	int	coseno;
    double  deltang;
	double	rayangle;

	if (i < WIDTH / 2) //si el rayo está a la izda del vector direccional del personaje
	{
		coseno = WIDTH / 2 - i;
        deltang = atan2(coseno, seno);
		rayangle = angle - deltang;
	}
	else
	{
		coseno = i - WIDTH / 2;
        deltang = atan2(coseno, seno);
		rayangle = angle + deltang;
	}
	if (rayangle < 0)
		rayangle += (M_PI * 2);
	if (rayangle >= M_PI * 2)
		rayangle -= (M_PI * 2);
    ft_socorro(i, seno, coseno, deltang * 180 / M_PI, rayangle * 180.0 / M_PI);
	return (rayangle * 180.0 / M_PI);
}

void	ft_loop_handler(double angle)
{
/* 	t_game	*info;
	double	a; //Yolanthe dice que el aumento del ángulo no es uniforme así que tengo que arreglar esto
	float	scale;
	t_coll	coll; */
	int		i;
//	int		j;

	double player_angle = ft_deg_to_rad(angle);
	i = 0;
	while (i < WIDTH)
	{
		double rayangle = ft_rayangle(i, player_angle);
/* 		coll = ft_ray_caster(info, rayangle);
		scale = WALL_H / coll.distance;
		ft_draw_col(info, scale, i, coll.txt); // (?) */
		i++;
//		printf("\033[38mft_loop_handler angle is: %f\n%s", angle, END);
	}
}

int main() {

    ft_loop_handler(270);

    return 0;
}
