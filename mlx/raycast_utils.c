#include "../includes/cub3d.h"
void ray_draw(t_scene *scene, double dist, char dir, double angle)
{
    int height;
    int height_real;
    double  fish_eye;
    int     min;
    int     max;
    int     i;

    dist *= cos((angle - scene->player.angle) * (PI / 180));
    fish_eye = 1;//(scene->resolution->y / 2) / tan((int)(FOV / 2) * (PI / 180));
    height = (int)round((dist) * fish_eye);
    height_real = height;
    if (height > scene->resolution->y)
        height = scene->resolution->y;
    min = (int)(scene->resolution->y / 2 - height / 2);
    max = (int)(scene->resolution->y / 2 + height / 2);
    i = 0;
    while (i < min)
        mlx_pixel_put(scene->vars.mlx, scene->vars.win, scene->ray_count, i++, scene->ceiling);
    while (min != max)
        mlx_pixel_put(scene->vars.mlx, scene->vars.win, scene->ray_count, min++, 0x00FF00);
    while (min < scene->resolution->y)
        mlx_pixel_put(scene->vars.mlx, scene->vars.win, scene->ray_count, min++, scene->floor);
}

