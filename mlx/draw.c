#include "../includes/cub3d.h"
#include <math.h>
#include <stdio.h>
#define HEIGHT 1080
#define WIDTH 1920

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	//keycode = keycode + 1 - 1;
	//vars->mlx = vars->mlx;
	return (0);
}

int	win(t_scene *scene)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
//	while (scene->mass[i / CUBE_SIZE])
//	{
//		j = 0;
//		while (scene->mass[i / CUBE_SIZE][j / CUBE_SIZE])
//		{
//			x = j;
//			if (scene->mass[i / CUBE_SIZE][x / CUBE_SIZE] == '1')
//			{
//				while (x < j + CUBE_SIZE)
//				{
//					y = i;
//					while (y < i + CUBE_SIZE)
//						mlx_pixel_put(scene->vars.mlx, scene->vars.win, x, y++, scene->ceiling);
//					x++;
//				}
//			}
//			else if (scene->mass[i / CUBE_SIZE][x / CUBE_SIZE] == '2')
//			{
//				while (x < j + CUBE_SIZE)
//				{
//					y = i;
//					while (y < i + CUBE_SIZE)
//						mlx_pixel_put(scene->vars.mlx, scene->vars.win, x, y++, scene->floor);
//					x++;
//				}
//			}
//			j += CUBE_SIZE;
//		}
//		i += CUBE_SIZE;
//	}
	ft_raycast(scene);
//	t_rays *tmp = scene->rays;
//	while (tmp)
//    {
//	    printf("%c %i", tmp->dir, tmp->dist);
//        tmp = tmp->next;
//    }
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
