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

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	win(t_scene *scene)
{
	int		x;
	int		y;
	int		yy;
	int		xx;
	t_map	*map;

	map = scene->map;
	x = 60;
	while (map)
	{
		y = 0;
		while (map->line[y / 20])
		{
			yy = y;
			if (map->line[yy / 20] == '1')
			{
				while (yy < y + 20)
				{
					xx = x;
					while (xx < x + 20)
					{
						mlx_pixel_put(scene->vars.mlx, scene->vars.win, yy, xx, scene->ceiling);
						xx++;
					}
					yy++;
				}
			}
			else if (map->line[yy / 20] == '2')
			{
				while (yy < y + 20)
				{
					xx = x;
					while (xx < x + 20)
					{
						mlx_pixel_put(scene->vars.mlx, scene->vars.win, yy, xx, scene->floor);
						xx++;
					}
					yy++;
				}
			}
			y += 20;
		}
		map = map->next;
		x += 20;
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

int	ft_draw(t_scene *scene)
{
	scene->vars.mlx = mlx_init();
	scene->vars.win = mlx_new_window(scene->vars.mlx, scene->resolution->x, scene->resolution->y, "cub3d");
	mlx_loop_hook(scene->vars.mlx, win, scene);
	mlx_hook(scene->vars.win, 17, 0, ft_close, &(scene->vars));
	mlx_hook(scene->vars.win, 2, 1L << 0, ft_hook, &(scene->vars));
	mlx_loop(scene->vars.mlx);
	return (0);
}
