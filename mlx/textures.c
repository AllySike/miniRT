//
// Created by Kurz Gale on 5/9/21.
//
#include "../includes/cub3d.h"
/*void	draw(t_scene *scene, double x, double y, double l)
{
    t_texture 	        texture;
    int					h;
    int					h_real;

    scene->ray_mass[scene->mass_y] = l;
    l *= cos(fabs(all->visual.ugl - (all->turn.alpha * (PI / 180))));
    h = (int)round((CUBE_SIZE / l) * all->visual.dist_screen);
    h_real = h;
    if (h > all->file.R_y)
        h = all->file.R_y;
    texture.y_tmp = (all->file.R_y / 2) + (h / 2) - 1;
    texture.mass_x = (int)(round(x) / CUBE_SIZE) * CUBE_SIZE;
    texture.mass_y = (int)(round(y) / CUBE_SIZE) * CUBE_SIZE;
    texture.x = x;
    texture.y = y;
    pull_texture(all, &texture, h, h_real);
}

void	pull_texture(t_all *all, t_maping_texture *texture, int h, int h_real)
{
    int	i;
    int	k;

    i = 0;
    pull_texture_utils(all, texture);
    draw_flag(all);
    while (texture->y_tmp >= (all->file.R_y / 2) - (h / 2)
           && texture->y_tmp >= 0)
    {
        k = ((h + h_real) >> 1) - i;
        all->NO_texture.color_y = (int)((all->NO_texture.height - 1)
                                        * k / h_real);
        all->WE_texture.color_y = (int)((all->WE_texture.height - 1)
                                        * k / h_real);
        all->SO_texture.color_y = (int)((all->SO_texture.height - 1)
                                        * k / h_real);
        all->EA_texture.color_y = (int)((all->EA_texture.height - 1)
                                        * k / h_real);
        wall_for_screen(all, texture);
        texture->y_tmp--;
        i++;
    }
}

void	pull_texture_utils(t_scene *scene, t_texture *texture)
{
    if (CUBE_SIZE > scene->north_path.width)
        all->NO_texture.color_x = (int)(((int)texture->x % CUBE_SIZE)
                                        / (CUBE_SIZE / all->NO_texture.width));
    else
        all->NO_texture.color_x = (int)(((int)texture->x % CUBE_SIZE)
                                        * (all->NO_texture.width / CUBE_SIZE));
    if (CUBE_SIZE > all->SO_texture.width)
        all->SO_texture.color_x = (int)(((int)texture->x % CUBE_SIZE)
                                        / (CUBE_SIZE / all->SO_texture.width));
    else
        all->SO_texture.color_x = (int)(((int)texture->x % CUBE_SIZE)
                                        * (all->SO_texture.width / CUBE_SIZE));
    if (CUBE_SIZE > all->EA_texture.width)
        all->EA_texture.color_x = (int)(((int)texture->y % CUBE_SIZE)
                                        / (CUBE_SIZE / all->EA_texture.width));
    else
        all->EA_texture.color_x = (int)(((int)texture->y % CUBE_SIZE)
                                        * (all->EA_texture.width / CUBE_SIZE));
    if (CUBE_SIZE > all->WE_texture.width)
        all->WE_texture.color_x = (int)(((int)texture->y % CUBE_SIZE)
                                        / (CUBE_SIZE / all->WE_texture.width));
    else
        all->WE_texture.color_x = (int)(((int)texture->y % CUBE_SIZE)
                                        * (all->WE_texture.width / CUBE_SIZE));
}*/