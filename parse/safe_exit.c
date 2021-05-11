#include "../includes/cub3d.h"

void    map_error(int fd, t_scene *scene, char *line)
{
    printf("Error:\nWrong map format\n");
    free(line);
    free_scene(scene);
    exit(-1);
}

static void    free_map(t_scene *scene)
{
    t_map   *map;

    map = scene->map->next;
    while (scene->map)
    {
        if (scene->map->line)
            free(scene->map->line);
        if (scene->map)
            free(scene->map);
        scene->map = map;
        if (map)
            map = map->next;
    }
}

static void    free_mass(t_scene *scene) {
    int i;

    i = 0;
    if (scene->mass)
    {
        while (scene->mass[i])
            free(scene->mass[i++]);
        free(scene->mass);
    }
}

void    free_scene(t_scene *scene)
{
    if (scene->resolution)
        free(scene->resolution);
    if (scene->north_path)
        free(scene->north_path);
    if (scene->south_path)
        free(scene->south_path);
    if (scene->west_path)
        free(scene->west_path);
    if (scene->east_path)
        free(scene->east_path);
    if (scene->sprite_path)
        free(scene->sprite_path);
    if (scene->map)
        free_map(scene);
    if (scene->mass)
        free_mass(scene);
    if (scene)
        free(scene);
}

void	ft_exit(int fd, char **split, char *line)
{
    write(STDERR_FILENO, "Error\nWrong info format in the map\n", 35);
    free_split(split);
    if (fd > 0)
        close(fd);
    free(line);
    exit(-1);
}

void safe_exit(int fd, char **split, char *line, t_scene *scene)
{
    free_scene(scene);
    ft_exit(fd, split, line);
}

void    error_with_map(t_scene *scene)
{
    write(STDERR_FILENO, "Error\nWrong map format\n", 23);
    free_scene(scene);
    exit(-1);
}
