
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

int	main(int argc, char *argv[])
{
	int		fd;
	t_scene	*scene;

	check_errors_with_file(argc, argv, &fd);
	fd = open(argv[1], O_RDONLY);
	scene = parser(fd);
	//дальнейшая обработка спарсенной сцены - тут будет вызываться функция из блока рендер
	close(fd);
	return (0);
}
// gcc libmlx.dylib -framework Metal -framework AppKit *.c && ./a.out