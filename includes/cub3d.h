/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:32:31 by kgale             #+#    #+#             */
/*   Updated: 2021/02/15 15:25:17 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "libft.h"

/*identifier == 0 stands for ceiling*/
/*identifier == 1 stands for floor*/
typedef struct		s_color
{
	int				identifier;
	int				r;
	int				g;
	int				b;
}					t_color;

/*identifier == 0 stands for NO*/
/*identifier == 1 stands for SO*/
/*identifier == 2 stands for WE*/
/*identifier == 3 stands for EA*/
/*identifier == 4 stands for S*/
typedef struct		s_texture
{
	int				identifier;
	char			path;
}					t_texture;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

/*identifier == 1 stands for SO*/
/*identifier == 2 stands for WE*/
/*identifier == 3 stands for EA*/
/*identifier == 4 stands for S*/
typedef struct		s_elem
{
	int				x;
	int				y;
	int				identifier;
	void			*next;
}					t_elem;


typedef struct		s_map
{
	t_elem			*walls;
	t_elem			*items;
	t_elem			*empty;
}					t_map;


typedef struct		s_scene
{
	t_resolution	resolution;
	t_color			floor;
	t_color			ceiling;
	t_texture		north;
	t_texture		south;
	t_texture		west;
	t_texture		east;
	t_texture		sprite;
	t_map			*map;
}					t_scene;

void	check_errors_with_file(int argc, char *argv[], int *fd);
t_scene	*parser(int fd);