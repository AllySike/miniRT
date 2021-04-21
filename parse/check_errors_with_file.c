/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_with_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:32:43 by kgale             #+#    #+#             */
/*   Updated: 2021/04/21 16:20:12 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_errors_with_extentions(char *argv[], int fd)
{
	int	i;

	i = 0;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (!argv[1][i])
	{
		write(STDERR_FILENO, "Error\nExtension needed\n", 23);
		exit(-1);
	}
	else if (i < 3 || argv[1][i] != '.' || !argv[1][i + 1]
		|| argv[1][i + 1] != 'c' || !argv[1][i + 2]
		|| argv[1][i + 2] != 'u' || !argv[1][i + 3]
		|| argv[1][i + 3] != 'b' || argv[1][i + 4])
	{
		write(STDERR_FILENO, "Error\nInvalid extension\n", 24);
		exit(-1);
	}
}

void	check_errors_with_file(int argc, char *argv[], int fd)
{
	if (argc < 2 || argc > 3)
	{
		write(STDERR_FILENO, "Error\nWrong number of arguments\n", 33);
		exit(-1);
	}
	check_errors_with_extentions(argv, fd);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		write(STDERR_FILENO, "Error\nNo such file or directory\n", 32);
		exit(-1);
	}
}

void	ft_exit(int fd)
{
	write(STDERR_FILENO, "Error\nWrong info format in the map\n", 35);
	close(fd);
	exit(-1);
}
