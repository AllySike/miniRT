/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:16:26 by kgale             #+#    #+#             */
/*   Updated: 2021/04/22 19:22:03 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

typedef struct s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct s_map
{
	char			*line;
	void			*next;
}					t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

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
	t_vars			vars;
}					t_scene;

void		check_errors_with_file(int argc, char *argv[], int *fd);
void		handle_res_tex_col(char *line, t_scene *scene, int fd);
void		handle_texture(char *line, t_scene *scene, int fd);
void		handle_map(char *line, t_scene *scene, int fd);
void		ft_exit(int fd, char **split);
int			ft_check_path_to_texture(char *path, char **split);
void		free_split(char **split);
int			create_trgb(int t, int r, int g, int b);
int			ft_draw(t_scene *scene);
void		ft_mapadd_back(t_map **lst, t_map *new);
t_map		*ft_mapnew(char *content);
t_scene		*parser(int fd);

#endif
