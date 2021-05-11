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
	int save;

	save = check_errors_with_file(argc, argv, &fd);
	scene = parser(fd);
	if (/*!*/save)
	    ft_draw(scene);
	return (0);
}
 /*	cp MiniLibX/libmlx.dylib .
 	gcc libmlx.dylib -framework Metal \
 -framework AppKit \
 	main.c parse/* mlx/* libft/libft.a \
 && ./a.out examples/gay.cub
 */
