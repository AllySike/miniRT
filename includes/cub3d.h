/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:16:26 by kgale             #+#    #+#             */
/*   Updated: 2021/04/21 20:17:42 by kgale            ###   ########.fr       */
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
	char			**map;
}					t_scene;

void	check_errors_with_file(int argc, char *argv[], int *fd);
void	handle_res_tex_col(char *line, t_scene *scene, int fd);
void	handle_texture(char *line, t_scene *scene, int fd);
void	handle_map(char *line, t_scene *scene, int fd);
void	ft_exit(int fd, char **split);
int		ft_check_path_to_texture(char *path);
void	free_split(char **split);
int		create_trgb(int t, int r, int g, int b);
int		ft_draw(void);
t_scene	*parser(int fd);
#endif
