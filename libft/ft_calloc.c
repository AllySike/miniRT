/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:51:23 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 15:11:53 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *output;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = 1;
	}
	output = malloc(size * count);
	if (output == NULL)
		return (NULL);
	ft_bzero(output, count * size);
	return (output);
}
