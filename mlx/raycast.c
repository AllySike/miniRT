#include "../includes/cub3d.h"

void ft_move_player(double x, double y, t_scene *scene)
{
    if (scene->mass[(int)floor(y)] && scene->mass[(int)floor(y)][(int)floor(x)] && scene->mass[(int)floor(y)][(int)floor(x)] != '1')
    {
        scene->player.x = x;
        scene->player.y = y;
    }
}

int	ft_hook(t_scene *scene)
{
    if (scene->keycode == -1)
        return (0);
    else if (scene->keycode == 123)
        scene->player.angle -= ROTATE;
    else if (scene->keycode == 124)
        scene->player.angle += ROTATE;
    else if (scene->keycode == 126 || scene->keycode == 13)
        ft_move_player(scene->player.x + STEP * sin(scene->player.angle * PI / 180),
                       scene->player.y + STEP * cos(scene->player.angle * PI / 180), scene);
    else if (scene->keycode == 1 || scene->keycode == 125)
        ft_move_player(scene->player.x - STEP * sin(scene->player.angle * PI / 180),
                       scene->player.y - STEP * cos(scene->player.angle * PI / 180), scene);
    else if (scene->keycode == 2)
        ft_move_player(scene->player.x + STEP * sin((scene->player.angle - 90) * PI / 180),
                       scene->player.y + STEP * cos((scene->player.angle - 90) * PI / 180), scene);
    else if (scene->keycode == 0)
        ft_move_player(scene->player.x - STEP * sin((scene->player.angle - 90) * PI / 180),
                       scene->player.y - STEP * cos((scene->player.angle - 90) * PI / 180), scene);
    return (0);
}

static double    raycast_x(t_scene *scene, double angle, int x_term, int y_term)
{
    double     x;
    double      y;
    double  tan_a;

    x = scene->player.x * CUBE_SIZE;
    tan_a = tan(angle * PI / 180);
//    mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(scene->player.x * CUBE_SIZE),
//                  (int)floor(scene->player.y * CUBE_SIZE), 0xFFFF00);
    y = (scene->player.y * CUBE_SIZE + y_term * ((x - scene->player.x) / tan_a));
    while (x / CUBE_SIZE >= 0 && x / CUBE_SIZE < scene->mass_x && y / CUBE_SIZE >= 0 && y / CUBE_SIZE < scene->mass_y
    && scene->mass[(int)floor(y / CUBE_SIZE)][(int)floor(x / CUBE_SIZE)])
    {
        if (scene->mass[(int)floor(y / CUBE_SIZE)][(int)floor(x / CUBE_SIZE)] != '0')
            return (fabs(sqrt(pow(x / CUBE_SIZE - scene->player.x, 2) + pow(y / CUBE_SIZE - scene->player.y, 2))));
//        mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(x * CUBE_SIZE),
//                      (int)floor(y * CUBE_SIZE), 0xFFFF00);
        x += x_term;
        y = (scene->player.y + y_term * fabs((x - scene->player.x) / tan_a));
    }
    return (scene->mass_x);
}

static double    raycast_y(t_scene *scene, double angle, int x_term, int y_term)
{
    double  x;
    double     y;
    double  tan_a;

    y = scene->player.y * CUBE_SIZE;
    tan_a = tan(angle * PI / 180);
//    mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(scene->player.x * CUBE_SIZE),
//                  (int)floor(scene->player.y * CUBE_SIZE), 0xFF0000);
    x = scene->player.x * CUBE_SIZE + ((y - scene->player.y) * tan_a);
    while (x / CUBE_SIZE >= 0 && x / CUBE_SIZE < scene->mass_x && y / CUBE_SIZE >= 0 && y / CUBE_SIZE < scene->mass_y
    && scene->mass[(int)floor(y / CUBE_SIZE)][(int)floor(x / CUBE_SIZE)])
    {
        if (scene->mass[(int)floor(y / CUBE_SIZE)][(int)floor(x / CUBE_SIZE)] != '0')
            return (fabs(sqrt(pow(x / CUBE_SIZE - scene->player.x, 2) + pow(y / CUBE_SIZE - scene->player.y, 2))));
//        mlx_pixel_put(scene->vars.mlx, scene->vars.win, (int)floor(x * CUBE_SIZE),
//                      (int)floor(y * CUBE_SIZE), 0xFF0000);
        y += y_term;
        x = scene->player.x + x_term * fabs((y - scene->player.y) * tan_a);
    }
    return (scene->mass_y);
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
    else
    {
        dist = dist2;
        dir = 'S';
        if (y_term < 0)
            dir = 'N';
    }
    ray_draw(scene, dist, dir, angle);
}

void ft_raycast(t_scene *scene)
{
    double step;
    double angle;

    ft_hook(scene);
    step = ((double)FOV / scene->resolution->x);
    angle = (scene->player.angle - (FOV / 2));
    scene->ray_count = 0;
    while (scene->ray_count < scene->resolution->x)
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
        scene->ray_count++;
    }
}
