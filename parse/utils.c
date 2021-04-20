#include "../includes/cub3d.h"

void	handle_res_tex_col(char *line, t_scene *scene)
{
	if (line[0] == 'R')
		printf("Resolution: %s\n", line);
	else if (line[0] == 'F')
		printf("Floor: %s\n", line);
	else if (line[0] == 'C')
		printf("Ceiling: %s\n", line);
	else if (line[0] == 'S')
		printf("Sprite: %s\n", line);
}

void	handle_texture(char *line, t_scene *scene)
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