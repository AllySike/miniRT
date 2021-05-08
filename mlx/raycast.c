#include "../includes/cub3d.h"

static double    raycast_x(t_scene *scene, double angle, int x_term, int y_term)
{
    double     x;
    double      y;
    double  dist_x;
    double  tan_a;

    x = scene->player.x;
    tan_a = tan(angle * PI / 180);
    mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(scene->player.x * CUBE_SIZE),
                  (int)floor(scene->player.y * CUBE_SIZE), 0xFFFF00);
    y = scene->player.y + y_term * ((x - scene->player.x) / tan_a);
    while (x >= 0 && x < scene->mass_x && y >= 0 && y < scene->mass_y
    && scene->mass[(int)floor(y)][(int)x])
    {
        //mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(x * CUBE_SIZE),
        //              (int)floor(y * CUBE_SIZE), 0xFFFF00);
        if (scene->mass[(int)floor(y)][(int)x] != '0')
        {
            dist_x = fabs(sqrt(pow(x, 2) + pow(y, 2)));
            return (dist_x);
        }
        x += x_term;
        y = (scene->player.y + y_term * fabs((x - scene->player.x) / tan_a));
    }
    return (dist_x);
}

static double    raycast_y(t_scene *scene, double angle, int x_term, int y_term)
{
    double  x;
    double     y;
    double  dist_y;
    double  tan_a;

    y = scene->player.y;
    tan_a = tan(angle * PI / 180);
    mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(scene->player.x * CUBE_SIZE),
                  (int)floor(scene->player.y * CUBE_SIZE), 0xFF0000);
    x = scene->player.x + ((y - scene->player.y) * tan_a);
    while (x >= 0 && x < scene->mass_x && y >= 0 && y < scene->mass_y)
    {
        //mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(x * CUBE_SIZE),
        //              (int)floor(y * CUBE_SIZE), 0xFF0000);
        if (scene->mass[(int)y][(int)floor(x)] != '0')
        {
            dist_y = fabs(sqrt(pow(x, 2) + pow(y, 2)));
            return (dist_y);
        }
        y += y_term;
        x = scene->player.x + x_term * fabs((y - scene->player.y) * tan_a);
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
    if (dist >= dist2)
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

    step = ((double)FOV / scene->resolution->x);
    angle = (scene->player.angle - (FOV / 2));
    curr = scene->resolution->x;
    while (curr--)
    {
        if (angle < 0)
            angle += 360;
        if (angle > 360)
            angle -= 360;
        if (angle < 90)
            raycast(scene, angle, -1, -1);
        else if (angle < 180)
            raycast(scene, angle, -1, 1);
        else if (angle < 270)
            raycast(scene, angle, 1, 1);
        else
            raycast(scene, angle, 1, -1);
        angle += step;
    }
}
