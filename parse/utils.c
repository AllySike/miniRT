#include "../includes/cub3d.h"

void	handle_color(char *line, t_scene *scene, int fd)
{
	if (line[0] == 'F')
		printf("Floor: %s\n", line);
	else if (line[0] == 'C')
		printf("Ceiling: %s\n", line);
}

void	handle_res_tex_col(char *line, t_scene *scene, int fd)
{
	char **split;

	//split = ft_split(line, ' ');
	if (line[0] == 'R')
	{
		printf("inherer");
		// if (!split[0] || !split[1] || !split[2] || split[3])
		// 	ft_exit(fd);
		printf("Resolution: %i %i\n", scene->resolution.x, scene->resolution.y);
	}
	else if (line[0] == 'S')
		printf("Sprite: %s\n", line);
	else
		handle_color(line, scene, fd);
}

void	handle_texture(char *line, t_scene *scene, int fd)
{
	if (line[0] == 'N')
		printf("North:\t%s\n", line);
	else if (line[0] == 'S')
		printf("South:\t%s\n", line);
	else if (line[0] == 'W')
		printf("West:\t%s\n", line);
	else if (line[0] == 'E')
		printf("East:\t%s\n", line);
}

void handle_map(char *line, t_scene *scene, int fd)
{
	int rd;

	printf("Map:\t%s\n", line);
	rd = get_next_line(fd, &line);
	while (rd && *line)
	{
		printf("Map:\t%s\n", line);
		rd = get_next_line(fd, &line);
	}
}
