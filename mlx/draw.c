#include "../includes/cub3d.h"

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

int             draw(void)
{
    t_vars      vars;
    int y = 0;
    int x = 0;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 650, 400, "Hello world!");
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    while (x++ < 320)
    {
        y = 0;
        while (y++ < 400)
            mlx_pixel_put(vars.mlx, vars.win, x, y, create_trgb(2, 100, 255, 200));
    }
    return (0);
} 