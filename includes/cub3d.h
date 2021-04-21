/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:26:43 by kgale             #+#    #+#             */
/*   Updated: 2021/04/21 19:47:26 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "libft.h"

/*identifier == 0 stands for ceiling
identifier == 1 stands for floor*/
typedef struct		s_color
{
	int				identifier;
	int				r;
	int				g;
	int				b;
}					t_color;


// /*identifier == 0 stands for NO*/
// /*identifier == 1 stands for SO*/
// /*identifier == 2 stands for WE*/
// /*identifier == 3 stands for EA*/
// /*identifier == 4 stands for S*/
// typedef struct		s_texture
// {
// 	int				identifier;
// 	char			*path;
// }					t_texture;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

// /*identifier == 1 stands for SO*/
// /*identifier == 2 stands for WE*/
// /*identifier == 3 stands for EA*/
// /*identifier == 4 stands for S*/
// typedef struct		s_elem
// {
// 	int				x;
// 	int				y;
// 	int				identifier;
// 	void			*next;
// }					t_elem;


// typedef struct		s_map
// {
// 	t_elem			walls;
// 	t_elem			items;
// 	t_elem			empty;
// }					t_map;
// /*сверху две структуры хуета*/

typedef struct		s_scene
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
