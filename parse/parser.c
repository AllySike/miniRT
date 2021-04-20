/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:56:18 by kgale             #+#    #+#             */
/*   Updated: 2021/04/20 17:39:21 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	t_scene	*init_scene(int fd)
{
	t_scene	*scene;

	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
	{
		close(fd);
		write(STDERR_FILENO, "Error\nUnable to locate memory\n", 31);
		exit(-1);
	}
	return (scene);
}

int		line_parser(char *line, t_scene *scene, int fd)
{
	if (line[0] /*&& line[1]*/)
	{
		if ((line[0] == 'S' || line[0] == 'F' || line[0] == 'C'
		|| line[0] == 'R') && line[1] == ' ')
			handle_res_tex_col(line, scene);
		else if (line[2] && line[2] == ' '
		&& ((line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A')))
			handle_texture(line, scene);
		else if (line[0] == ' ' || line[0] == '1')
			handle_map(line, scene, fd);
		else
		{
			close(fd);
			free(line);
			free(scene);
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

	scene = init_scene(fd);
	while((gnl = get_next_line((const int)fd, &line)) > 0)
	{
		line_parser(line, scene, fd);
		free(line);
	}
	line_parser(line, scene, fd);
	free(line);
	return (scene);
}