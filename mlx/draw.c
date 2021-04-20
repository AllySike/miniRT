#include "../includes/cub3d.h"
#include <math.h>
int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
#include <mlx.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int             key_hook(int keycode, t_vars *vars)
{
    printf("Hello from key_hook!\n");
    return (0);
}

#include <mlx.h>
#include <stdio.h>


// int             draw(void)
// {
//    /*     t_vars      vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//     mlx_key_hook(vars.win, key_hook, &vars);
//     mlx_loop(vars.mlx);*/
//     t_vars      vars;
//     int y = 0;
//     int x = 0;
//     int k = 0;
//     int d = 0;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
//     char mass[10][10] = {"1111111111",
//                          "1000000001",
//                          "1000000001",
//                          "1000000001",
//                          "1000000001",
//                          "1000000001",
//                          "1000000001",
//                          "1000000001",
//                          "1000000001",
//                          "1111111111"};
//     while (x < 100)
//     {
//         y = 0;
//         while (y < 100)
//         {
//             k = x;
//             d = y;
//             if (mass[x/10][y/10] == '1')
//             while (d != y - 10)
//                 mlx_pixel_put(vars.mlx, vars.win, x, y++, 0x0000FFF0);
//             y = y + 10;
//         }
//         x = x + 10;
//     }
//     mlx_hook(vars.win, 2, 1L<<0, close, &vars);
//     mlx_loop(vars.mlx);
//     return (0);
// } 
int             win_close(int keycode, t_vars *vars)
{
    if (keycode == 53 || keycode == 1L<<5)
	{
    	mlx_destroy_window(vars->mlx, vars->win);
    	//printf("imhere");
	}
    return (0);
}

int             draw(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_loop_hook(vars.mlx, win_close, &vars);
    mlx_loop(vars.mlx);
    //printf("imhere");
    return (0);
} 
