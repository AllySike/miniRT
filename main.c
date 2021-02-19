
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:30:23 by kgale             #+#    #+#             */
/*   Updated: 2021/02/15 20:13:23 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
int             draw(int fd);
int	main(int argc, char *argv[])
{
	int		fd;
	t_scene	*scene;
	int gnl;
	char line[6];

	check_errors_with_file(argc, argv, &fd);
	parser(fd);
	//дальнейшая обработка спарсенной сцены - тут будет вызываться функция из блока рендер
	//draw(fd);
	close(fd);
	return (0);
}
// cp MiniLibX/libmlx.dylib .
// gcc libmlx.dylib -framework Metal -framework AppKit main.c parse/* mlx/* && ./a.out examples/gay.cub