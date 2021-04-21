#include "../includes/cub3d.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <mlx.h>
#define HEIGHT 1080
#define WIDTH 1920

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	win(t_vars *vars)
{
	int		x = 0;
	int		y = 0;
	int		k, d;

	char	mass[10][10] = {"1111111111",
						 "1000000001",
						 "1101000001",
						 "1000100001",
						 "1000100001",
						 "1000020001",
						 "1000000001",
						 "1000010001",
						 "1000000001",
						 "1111111111"};
	while (mass[x / 70][0])
	{
		y = 0;
		while (y < 700)
		{
			d = y;
			if (mass[x / 70][d / 70] == '1')
			{
				while (d < y + 70)
				{
					k = x;
					while (k < x + 70)
					{
						mlx_pixel_put(vars->mlx, vars->win, k, d, 14443520);
						k++;
					}
					d++;
				}
			}
			else if (mass[x / 70][d / 70] == '2')
			{
				mlx_pixel_put(vars->mlx, vars->win, k, d, 0xFFF0000);
			}
			y = y + 70;
		}
		x = x + 70;
	}
	return (0);
}

int	ft_close(t_vars *vars)
{
	// if (keycode == 53 || keycode == 1L<<5 || keycode == 17)
	// {
	// 	mlx_destroy_window(vars->mlx, vars->win);
	// 	//printf("imhere");
	//     exit(0);
	// }
	exit(0);
}

int	ft_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		ft_close(vars);
	}
	return (0);
}

int	ft_draw(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "cub3d");
	mlx_loop_hook(vars.mlx, win, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
