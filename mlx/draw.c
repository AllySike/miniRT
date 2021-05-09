#include "../includes/cub3d.h"
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
	while (i / CUBE_SIZE < scene->mass_y)
	{
		j = 0;
		while (j / CUBE_SIZE < scene->mass_x)
		{
			x = j;
			if (scene->mass[i / CUBE_SIZE][x / CUBE_SIZE] == '1')
			{
				while (x < j + CUBE_SIZE)
				{
					y = i;
					while (y < i + CUBE_SIZE)
						mlx_pixel_put(scene->vars.mlx, scene->vars.win, x, y++, scene->ceiling);
					x++;
				}
			}
			else if (scene->mass[i / CUBE_SIZE][x / CUBE_SIZE] == '2')
			{
				while (x < j + CUBE_SIZE)
				{
					y = i;
					while (y < i + CUBE_SIZE)
						mlx_pixel_put(scene->vars.mlx, scene->vars.win, x, y++, scene->floor);
					x++;
				}
			}
            else
            {
                while (x < j + CUBE_SIZE)
                {
                    y = i;
                    while (y < i + CUBE_SIZE)
                        mlx_pixel_put(scene->vars.mlx, scene->vars.win, x, y++, 0x000000);
                    x++;
                }
            }
			j += CUBE_SIZE;
		}
		i += CUBE_SIZE;
	}
	ft_raycast(scene);
//	t_rays *tmp = scene->rays;
//	while (tmp)
//    {
//	    printf("%c %i", tmp->dir, tmp->dist);
//        tmp = tmp->next;
//    }
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    if ((unsigned int)color == 0xFF000000)
        return ;
    *(unsigned int *)dst = color;
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

int ft_press(int keycode, t_scene *scene)
{
    if (keycode == 53)
        ft_close(&(scene->vars));
    else if (keycode == 123 || keycode == 124 || keycode == 126 || keycode == 13
        || keycode == 1 || keycode == 125 || keycode == 2 || keycode == 0)
        scene->keycode = keycode;
}

int ft_release(int keycode, t_scene *scene)
{
    if (keycode == 53)
        ft_close(&(scene->vars));
    else
        scene->keycode = -1;
}

int	ft_draw(t_scene *scene)
{
	scene->vars.mlx = mlx_init();
	scene->vars.win = mlx_new_window(scene->vars.mlx, scene->resolution->x, scene->resolution->y, "cub3d");
	mlx_loop_hook(scene->vars.mlx, win, scene);
	mlx_hook(scene->vars.win, 17, 0, ft_close, &(scene->vars));
    mlx_hook(scene->vars.win, 2, 1L << 0, ft_press, scene);
    mlx_hook(scene->vars.win, 3, 1L << 1, ft_release, scene);//сделать движения в draw и зажатие/отжатие клавиш
	mlx_loop(scene->vars.mlx);
	return (0);
}
