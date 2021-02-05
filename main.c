/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:30:23 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 14:36:31 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int main(int argc, char *argv[])
{
    int     fd;
    t_scene *scene;

    check_errors_with_file(argc, argv, &fd);
    if (argc == 2)
    {

    }
    else
    {

    }
    close(fd);
    return (1);
}