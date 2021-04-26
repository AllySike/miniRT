/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:30:23 by kgale             #+#    #+#             */
/*   Updated: 2021/04/26 13:02:03 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_scene	*scene;

	check_errors_with_file(argc, argv, &fd);
	scene = parser(fd);
	/*printf("Resolution: %i %i\n", scene->resolution->x, scene->resolution->y);
	printf("Sprite: %s\n", scene->sprite_path);
	printf("North:\t%s\n", scene->north_path);
	printf("South:\t%s\n", scene->south_path);
	printf("West:\t%s\n", scene->west_path);
	printf("East:\t%s\n", scene->east_path);
	printf("Floor:\t\t%i\n", scene->floor);
	printf("Ceiling:\t%i\n", scene->ceiling);*/
// /* дальнейшая обработка спарсенной сцены -
// тут будет вызываться функция из блока рендер*/
/*t_map *list = scene->map;
	while (list)
	{
		printf("Map:\t%s\n", list->line);
		list = list->next;
	}*/
	ft_draw(scene);
	return (0);
}
// /*	cp MiniLibX/libmlx.dylib .
// 	gcc libmlx.dylib -framework Metal \
// -framework AppKit \
// 	main.c parse/* mlx/* libft/libft.a \
// && ./a.out examples/gay.cub
// */
