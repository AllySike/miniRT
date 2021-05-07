/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:56:18 by kgale             #+#    #+#             */
/*   Updated: 2021/04/27 16:28:36 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	//free(split);
}

void	init_scene(t_scene **scene)
{
	*scene = (t_scene *)malloc(sizeof(t_scene));
	(*scene)->ceiling = -1;
	(*scene)->east_path = NULL;
	(*scene)->floor = -1;
	(*scene)->map = NULL;
	(*scene)->north_path = NULL;
	(*scene)->south_path = NULL;
	(*scene)->sprite_path = NULL;
	(*scene)->west_path = NULL;
	(*scene)->resolution = (t_resolution *)malloc(sizeof(t_resolution));
	(*scene)->resolution->x = -1;
	(*scene)->resolution->y = -1;
    (*scene)->player.x = -1;
    (*scene)->player.y = -1;
    (*scene)->player.angle = -1;
    (*scene)->rays = NULL;
}

int	line_parser(char *line, t_scene *scene, int fd)
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
			handle_map(&(*line), scene, fd);
		else
		{
			close(fd);
			free(line);
			free_scene(scene);
			write(STDERR_FILENO, "Error\nInvalid map\n", 18);
			exit(-1);
		}
	}
	return (0);
}

t_scene	*parser(int fd)
{
	t_scene	*scene;
	int		gnl;
	char	*line;

	scene = NULL;
	init_scene(&scene);
	gnl = get_next_line((const int)fd, &line);
	while (gnl > 0)
	{
		line_parser(line, scene, fd);
		//free(line);
		gnl = get_next_line((const int)fd, &line);
	}
	//check_not_null(scene, line);
	free(line);
	close(fd);
	map_to_mass(scene);
	return (scene);
}

void	handle_map(char *line, t_scene *scene, int fd)
{
	int			rd;

	scene->map = ft_mapnew(line);
	rd = get_next_line(fd, &line);
	while (rd >= 0 && *line && *line != '\n')
	{
		ft_mapadd_back(&(scene->map), ft_mapnew(line));
		free(line);
		rd = get_next_line(fd, &line);
	}
	while (rd)
	{
		if (line && *line && *line != '\n')
			map_error(fd, scene, line);
		free(line);
		rd = get_next_line(fd, &line);
	}
	if (line && *line && *line != '\n')
		map_error(fd, scene, line);
	free(line);
}
