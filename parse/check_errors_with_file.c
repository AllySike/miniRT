/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_with_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:32:43 by kgale             #+#    #+#             */
/*   Updated: 2021/04/26 13:04:00 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_errors_with_extentions(char *argv[])
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

static int ft_check_save(int *fd, char *argv[])
{
    if (!argv[2][0] || !argv[2][1] || !argv[2][2] || !argv[2][3] || !argv[2][4]
    || !argv[2][5] || argv[2][6] || argv[2][0] != '-' || argv[2][1] != '-'
    || argv[2][2] != 's' || argv[2][3] != 'a' || argv[2][4] != 'v' || argv[2][5] != 'e')
    {
        write(STDERR_FILENO, "Error\nInvalid save option\n", 26);
        close(*fd);
        exit(-1);
    }
    return (1);
}

int	ft_check_path_to_texture(char *path, char **split, char *line)
{
	int		fd;
	char	buff[1];

	if (!path[0])
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit(fd, split, line);
	fd = read(fd, buff, 0);
	if (fd < 0)
		ft_exit(fd, split ,line);
	close(fd);
	return (1);
}

int check_errors_with_file(int argc, char *argv[], int *fd)
{
    if (argc < 2 || argc > 3)
    {
        write(STDERR_FILENO, "Error\nWrong number of arguments\n", 33);
        exit(-1);
    }
    check_errors_with_extentions(argv);
    *fd = open(argv[1], O_RDONLY);
    if (*fd <= 0)
    {
        write(STDERR_FILENO, "Error\nNo such file or directory\n", 32);
        exit(-1);
    }
    if (read(*fd, NULL, 0) < 0)
    {
        write(STDERR_FILENO, "Error\nCan't open file\n", 23);
        exit(-1);
    }
    if (argc == 3)
        return (ft_check_save(fd, argv));
    return (0);
}