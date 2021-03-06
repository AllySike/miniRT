/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:16:26 by kgale             #+#    #+#             */
/*   Updated: 2021/04/27 16:52:40 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "libft.h"
# define CUBE_SIZE 3
# define ROTATE 10
# define STEP 2
# define PI 3.14
# define FOV 60

typedef struct s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct s_texture
{
    int				mass_x;
    int				mass_y;
    int				y_tmp;
    double			x;
    double			y;
}					t_texture;

typedef struct s_map
{
	char			*line;
	int				len;
	void			*next;
}					t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}			t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_rays
{
	double	dist;
	char	dir;
	void	*next;
}				t_rays;

typedef struct s_scene
{
	t_resolution	*resolution;
	int				floor;
	int				ceiling;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*sprite_path;
	t_map			*map;
	char			**mass;
	t_vars			vars;
	t_player		player;
	int             mass_x;
	int             mass_y;
	int             keycode;
	int             ray_count;
}					t_scene;

typedef struct s_data
{
    void			*img;
    char			*addr;
    int				bits_per_pixel;
    int				line_length;
    int				endian;
}					t_data;

int		    check_errors_with_file(int argc, char *argv[], int *fd);
int         ft_check_path_to_texture(char *path, char **split, char *line);
void        safe_exit(int fd, char **split, char *line, t_scene *scene);

void		handle_res_tex_col(char *line, t_scene *scene, int fd);
void		handle_texture(char *line, t_scene *scene, int fd);
void		handle_map(char *line, t_scene *scene, int fd);
void		ft_exit(int fd, char **split, char *line);
void		free_split(char **split);
int			create_trgb(int t, int r, int g, int b);
int			ft_draw(t_scene *scene);
void		ft_mapadd_back(t_map **lst, t_map *new);
t_map		*ft_mapnew(char *content);
t_scene		*parser(int fd);
void		map_error(int fd, t_scene *scene, char *line);
void		free_scene(t_scene *scene);
void		map_to_mass(t_scene *scene);
int			ft_mapsize(t_map *lst);
void		error_with_map(t_scene *scene);
void		ft_raycast(t_scene *scene);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ray_draw(t_scene *scene, double dist, char dir, double angle);

#endif
