#include "../includes/cub3d.h"

void	handle_color(char *line, t_scene *scene, int fd)
{
	char	**split;
	char	**color;

	split = ft_split(line, ' ');
	if (!split[0] || !split[1] || split[2])
		ft_exit(fd, split);
	color = ft_split(split[1], ',');
	if (!color[0] || !color[1] || !color[2] || color[3]
		|| !ft_aredigits(color[0]) || !ft_aredigits(color[1])
		|| !ft_aredigits(color[2]))
		{
			free_split(color);
			ft_exit(fd, split);
		}
	if (line[0] == 'F')
		scene->floor = create_trgb(0, ft_atoi(color[0]), ft_atoi(color[1]), ft_atoi(color[2]));
	else if (line[0] == 'C')
		scene->ceiling = create_trgb(0, ft_atoi(color[0]), ft_atoi(color[1]), ft_atoi(color[2]));
	free_split(split);
	free_split(color);
}

void	handle_res_tex_col(char *line, t_scene *scene, int fd)
{
	char **split;

	split = ft_split(line, ' ');
	if (line[0] == 'R')
	{
		if (!split[0] || !split[1] || !split[2] || split[3]
		|| !ft_aredigits(split[1]) || !ft_aredigits(split[2]))
			ft_exit(fd, split);
		scene->resolution->x = ft_atoi(split[1]);
		scene->resolution->y = ft_atoi(split[2]);
	}
	else if (line[0] == 'S')
	{
		if (!split[0] || !split[1] || split[2]
		|| !ft_check_path_to_texture(split[1]))
			ft_exit(fd, split);
		scene->sprite_path = ft_strdup(split[1]);
	}
	else
		handle_color(line, scene, fd);
	free_split(split);
}

void	handle_textures(char *line, t_scene *scene, int fd, char **split)
{
	if (line[0] == 'W')
	{
		if (!split[0] || !split[1] || split[2]
		|| !ft_check_path_to_texture(split[1]))
			ft_exit(fd, split);
		scene->west_path = ft_strdup(split[1]);
	}
	else if (line[0] == 'E')
	{
		if (!split[0] || !split[1] || split[2]
		|| !ft_check_path_to_texture(split[1]))
			ft_exit(fd, split);
		scene->east_path = ft_strdup(split[1]);
	}
}

void	handle_texture(char *line, t_scene *scene, int fd)
{
	char **split;

	split = ft_split(line, ' ');
	if (line[0] == 'N')
	{
		if (!split[0] || !split[1] || split[2]
		|| !ft_check_path_to_texture(split[1]))
			ft_exit(fd, split);
		scene->north_path = ft_strdup(split[1]);
	}
	else if (line[0] == 'S')
	{
		if (!split[0] || !split[1] || split[2]
		|| !ft_check_path_to_texture(split[1]))
			ft_exit(fd, split);
		scene->south_path = ft_strdup(split[1]);
	}
	else handle_textures(line, scene, fd, split);
	free_split(split);
}
