/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:56:18 by kgale             #+#    #+#             */
/*   Updated: 2021/02/19 13:09:46 by kgale            ###   ########.fr       */
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

t_scene	*parser(int fd)
{
	t_scene	*scene;
	char	*line;
	int		gnl;

	scene = init_scene(fd);
	// while ()
	return (scene);
}