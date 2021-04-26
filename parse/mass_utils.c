#include "../includes/cub3d.h"

static void set_player(int x, int y, char c, t_scene *scene)
{
    if (c == 'N')
        scene->player->angle = 0;
    else if (c == 'S')
        scene->player->angle = 180;
    else if (c != 'W')
        scene->player->angle = 270;
    else if (c != 'E')
        scene->player->angle = 90;
    scene->player->x = x;
    scene->player->y = y;
}

static void mass_from_map(t_scene *scene, t_map   *map, int ii)
{
    int     i;
    char    c;
    char    *mass;

    i = 0;
    while (map->line[i])
    {
        c = map->line[i];
        if (c == '0' || c == '1' || c == ' ')
            scene->mass[ii][i] = c;
        else if (c == '2')
            scene->mass[ii][i] = c;
        else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && !scene->player)
            set_player(ii, i, c, scene);
        else
            error_with_map(scene);
        i++;
    }
}

void    map_to_mass(t_scene *scene)
{
    t_map   *tmp;
    int     max;
    int     j;
    int     i;

    tmp = scene->map;
    max = 0;
    while (tmp)
    {
        if (max < tmp->len)
            max = tmp->len;
        tmp = tmp->next;
    }
    tmp = scene->map;
    j = ft_mapsize(scene->map);
    scene->mass = (char **)malloc(sizeof(char*) * (j + 1));
    i = 0;
    while (i < j)
    {
        scene->mass[i] = calloc(max, sizeof(char));
        mass_from_map(scene, tmp, i);
        tmp = tmp->next;
        i++;
    }
    scene->mass[i] = NULL;
}