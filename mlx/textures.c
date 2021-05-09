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

void	wall_for_screen(t_all *all, t_maping_texture *texture)
{
    if ((texture->x_mass + CUBE_SIZE - SIZE_PLAYER
         <= (int)round(texture->x))
        && (all->file.map[texture->y_mass / CUBE_SIZE]
            [(texture->x_mass / CUBE_SIZE) + 1] != '1'))
        my_mlx_pixel_put(&all->data, all->visual.width, texture->y_tmp,
                         (int)get_color_image(&all->WE_texture,
                                              (int)all->WE_texture.color_x, (int)all->WE_texture.color_y));
    if (texture->y_mass + CUBE_SIZE - SIZE_PLAYER == (int)round(texture->y)
        && (all->file.map[(texture->y_mass / CUBE_SIZE) + 1]
            [texture->x_mass / CUBE_SIZE] != '1'))
        my_mlx_pixel_put(&all->data, all->visual.width, texture->y_tmp,
                         (int)get_color_image(&all->NO_texture,
                                              (int)all->NO_texture.color_x, (int)all->NO_texture.color_y));
    if ((texture->y_mass == (int)round(texture->y))
        && (all->file.map[(texture->y_mass / CUBE_SIZE) - 1]
            [texture->x_mass / CUBE_SIZE] != '1'))
        my_mlx_pixel_put(&all->data, all->visual.width, texture->y_tmp,
                         (int)get_color_image(&all->SO_texture,
                                              (int)all->SO_texture.color_x, (int)all->SO_texture.color_y));
    if ((texture->x_mass == (int)round(texture->x))
        && (all->file.map[texture->y_mass / CUBE_SIZE]
            [(texture->x_mass / CUBE_SIZE) - 1] != '1'))
        my_mlx_pixel_put(&all->data, all->visual.width, texture->y_tmp,
                         (int)get_color_image(&all->EA_texture,
                                              (int)all->EA_texture.color_x, (int)all->EA_texture.color_y));
}

void	draw_flag(t_all *all)
{
    int	i;

    i = 0;
    while (i < all->file.R_y / 2)
    {
        my_mlx_pixel_put(&all->data, all->visual.width, i,
                         create_trgb(0, all->file.C[0], all->file.C[1], all->file.C[2]));
        i++;
    }
    while (i < all->file.R_y)
    {
        my_mlx_pixel_put(&all->data, all->visual.width, i,
                         create_trgb(0, all->file.F[0], all->file.F[1], all->file.F[2]));
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