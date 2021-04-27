#include "../includes/cub3d.h"

static double    raycast_x(t_scene *scene, double angle, int x_term, int y_term)
{
    double     x;
    double     y;
    double  dist_x;

    x = scene->player.x;
    while (x >= 0 && x <= scene->mass_x)
    {
        x += x_term;
        y = scene->player.y + ((x - x_term * scene->player.x) / tan(angle));
        if (scene->mass[(int)x, (int)y] == '1' || (y < 0 || y > scene->mass_y)
            || scene->mass[(int)x, (int)y + y_term] == '1')
        {
            dist_x = (x - (x_term * scene->player.x)) / cos(angle);
            if (y >= 0 && y <= scene->mass_y)
                mlx_pixel_put(scene->vars.mlx, scene->vars.win, x - x_term, y - y_term, 0xff0000);
            break;
        }
    }
    return (dist_x);
}

static double    raycast_y(t_scene *scene, double angle, int x_term, int y_term)
{
    double     x;
    double     y;
    double  dist_y;

    y = scene->player.y;
    while (y >= 0 && y <= scene->mass_y)
    {
        y += y_term;
        x = scene->player.x + ((x - x_term * scene->player.x) / tan(angle));
        if (scene->mass[(int)x, (int)y] == '1' || (x < 0 || x > scene->mass_x)
            || scene->mass[(int)x + x_term, (int)y] == '1')
        {
            dist_y = (y - (y_term * scene->player.y)) * sin(angle);
            if (x - x_term > 0 && x - x_term < scene->mass_x)
                mlx_pixel_put(scene->vars.mlx, scene->vars.win, x - x_term, y - y_term, 0x00ff00);
            break;
        }
    }
    return (dist_y);
}

static void add_ray(t_scene *scene, double dist, char dir)
{
    t_rays	*start;
    t_rays 	*ray;

    ray = (t_scene *)malloc(sizeof(t_scene));
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

    step = (FOV * 180 / PI) / scene->resolution->x - 1;
    angle = scene->player.angle - FOV / 2;
    curr = scene->resolution->x;
    while (curr--)
    {
        if (angle < 0)
            angle = 360 + angle;
        if (angle > 360)
            angle = 360 - angle;
        if (angle < 90)
            raycast(scene, angle, 1, 1);
        else if (angle < 180)
            raycast(scene, angle, 1, -1);
        else if (angle < 270)
            raycast(scene, angle, -1, -1);
        else
            raycast(scene, angle, -1, 1);
        angle += step;
    }
}
