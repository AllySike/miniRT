/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:56:18 by kgale             #+#    #+#             */
/*   Updated: 2021/04/21 20:00:18 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_scene(t_scene *scene)
{
	scene->ceiling = 0;
	scene->east_path = NULL;
	scene->floor = 0;
	scene->map = NULL;
	scene->north_path = NULL;
	scene->south_path = NULL;
	scene->sprite_path = NULL;
	scene->west_path = NULL;
	scene->resolution->x = 0;
	scene->resolution->y = 0;
}

int		line_parser(char *line, t_scene *scene, int fd)
{
	if (line[0])
	{
		if ((line[0] == 'S' || line[0] == 'F' || line[0] == 'C'
		|| line[0] == 'R') && line[1] == ' ')
			handle_res_tex_col(line, scene, fd);
		else if (line[2] && line[2] == ' '
		&& ((line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A')))
			handle_texture(line, scene, fd);
		else if (line[0] == ' ' || line[0] == '1')
			handle_map(line, scene, fd);
		else
		{
			close(fd);
			free(line);
			write(STDERR_FILENO, "Error\nInvalid map\n", 19);
			exit(-1);
		}
	}
	return (0);
}

t_scene	*parser(int fd)
{
	t_scene	*scene;
	int gnl;
	char	*line;

	init_scene(scene);
	gnl = get_next_line((const int)fd, &line);
	while(gnl > 0)
	{
		line_parser(line, scene, fd);
		free(line);
		gnl = get_next_line((const int)fd, &line);
	}/*
	line_parser(line, scene, fd);
	free(line);*/
	////////////////////////////
	/*Check for all not NULL*/

	printf("Resolution: %i %i\n", scene->resolution->x, scene->resolution->y);
	printf("Sprite: %s\n", scene->sprite_path);
	printf("North:\t%s\n", scene->north_path);
	printf("South:\t%s\n", scene->south_path);
	printf("West:\t%s\n", scene->west_path);
	printf("East:\t%s\n", scene->east_path);
	printf("Floor:\t\t%i\n", scene->floor);
	printf("Ceiling:\t%i\n", scene->ceiling);
	return (scene);
}

void	handle_map(char *line, t_scene *scene, int fd)
{
	int rd;

	//printf("Map:\t%s\n", line);
	rd = get_next_line(fd, &line);
	while (rd && *line)
	{
	//	printf("Map:\t%s\n", line);
		rd = get_next_line(fd, &line);
	}
}
