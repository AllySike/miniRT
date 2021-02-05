/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:32:31 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 15:01:47 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct		s_point_3d
{
	float			x;
	float			y;
	float			z;
}					t_point_3d;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef	struct		s_ray
{
	t_point_3d		start;
	t_point_3d		via;
}					t_ray;

typedef struct		s_sphere
{
	t_point_3d		center;
	float			diameter;
	t_color			color;
	void			*next;
}					t_sphere;

typedef struct		s_plane
{
	t_point_3d		center;
	t_point_3d		norm_vector;
	t_color			color;
	void			*next;
}					t_plane;

typedef struct		s_square
{
	t_point_3d		center;
	t_point_3d		norm_vector;
	float			side;
	t_color			color;
	void			*next;
}					t_square;

typedef struct		s_cylinder
{
	t_point_3d		center;
	t_point_3d		norm_vector;
	float			diameter;
	float			height;
	t_color			color;
	void			*next;
}					t_cylinder;

typedef struct		s_triangle
{
	t_point_3d		a;
	t_point_3d		b;
	t_point_3d		c;
	t_color			color;
	void			*next;
}					t_triangle;

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct		s_ambi_light
{
	float			ratio;
	t_color			color;
}					t_ambi_light;

typedef struct		s_camera
{
	t_point_3d		point;
	t_point_3d		norm_vector;
	int				fov;
}					t_camera;

typedef struct		s_light
{
	t_point_3d		point;
	float			ratio;
	t_color			color;
	void			*next;
}					t_light;

typedef struct		s_scene
{
	t_resolution	resolution;
	t_ambi_light	ambi_light;
	t_camera		camera;
	t_light			*light;
	t_square		*squares;
	t_sphere		*spheres;
	t_cylinder		*cylinders;
	t_triangle		*triangles;
	t_plane			*planes;
}					t_scene;

void	check_errors_with_file(int argc, char *argv[], int *fd);
t_scene	*parser(int fd);