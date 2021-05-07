#include "../includes/cub3d.h"

static double    raycast_x(t_scene *scene, double angle, int x_term, int y_term)
{
    double     x;
    double     y;
    double  dist_x;
    double  tan_a;
    double  cos_a;

    x = scene->player.x + x_term;
    cos_a = cos(angle * PI / 180);
    tan_a = tan(angle * PI / 180);
    y = scene->player.y +  ((x - scene->player.x) / tan_a);
    while (x >= 0 && x <= scene->mass_x && y >= 0 && y <= scene->mass_y)
    {
        mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(x * CUBE_SIZE),
                      (int)floor(y * CUBE_SIZE), 0xff0000);
        if (scene->mass[(int)floor(y), (int)floor(x)] == '1')
        {
            dist_x = x - scene->player.x / cos_a;
            mlx_pixel_put(scene->vars.mlx, scene->vars.win, (x - x_term) * CUBE_SIZE,
                              (y - y_term) * CUBE_SIZE, 0xff00FF);
            return (dist_x);
        }
        x += x_term;
        y = scene->player.y + y_term * ((x - scene->player.x) / tan_a);
    }
    return (dist_x);
}

static double    raycast_y(t_scene *scene, double angle, int x_term, int y_term)
{
    double     x;
    double     y;
    double  dist_y;
    double  tan_a;
    double  sin_a;

    y = scene->player.y + y_term;
    sin_a = sin(angle * PI / 180);
    tan_a = tan(angle * PI / 180);
    x = scene->player.x + (y - scene->player.y) * tan_a;
    while (x >= 0 && x <= scene->mass_x && y >= 0 && y <= scene->mass_y)
    {
        mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor((x - x_term) * CUBE_SIZE),
                      (int)floor((y - y_term) * CUBE_SIZE), 0x00ff00);
        if (scene->mass[(int)floor(y), (int)floor(x)] == '1')
        {
            dist_y = x - scene->player.x / sin_a;
//            mlx_pixel_put(scene->vars.mlx, scene->vars.win, (x - x_term) * CUBE_SIZE,
//                          (y - y_term) * CUBE_SIZE, 0x00ffFF);
            return (dist_y);
        }
        y += y_term;
        x = scene->player.x + x_term * ((y - scene->player.y) * tan_a);
    }
    return (dist_y);
}

static void add_ray(t_scene *scene, double dist, char dir)
{
    t_rays	*start;
    t_rays 	*ray;

    ray = (t_rays *)malloc(sizeof(t_rays));
    ray->dir = dir;
    ray->dist = dist;
    ray->next = NULL;
    if (!scene->rays)
        scene->rays = ray;
    else
    {
        start = scene->rays;
        while (start && start->next)
            start = start->next;
        start->next = ray;
    }
}

static void raycast(t_scene *scene, double angle, int x_term, int y_term)
{
    double dist1;
    double dist2;
    char     dir;
    double  dist;

    dist1 = raycast_x(scene, angle, x_term, y_term);
    dist2 = raycast_y(scene, angle, x_term, y_term);
    if (dist1 < dist2)
    {
        dist = dist1;
        dir = 'E';
        if (x_term < 0)
            dir = 'W';
    }
    else if (dist >= dist2)
    {
        dist = dist2;
        dir = 'S';
        if (y_term < 0)
            dir = 'N';
    }
    add_ray(scene, dist, dir);
}

void ft_raycast(t_scene *scene)
{
    double step;
    double angle;
    int curr;

    step = 6;//(FOV / (scene->resolution->x / 100)) - 1;
    angle = (scene->player.angle - (FOV / 2));
    curr = 10;scene->resolution->x / 100;
    while (curr--)
    {
        if (angle < 90)
            raycast(scene, angle, 1, 1);
        else if (angle < 180)
            raycast(scene, angle, 1, -1);
        else if (angle <= 270)
            raycast(scene, angle, -1, -1);
        else
            raycast(scene, angle, -1, 1);
        angle += step;
    }
}
