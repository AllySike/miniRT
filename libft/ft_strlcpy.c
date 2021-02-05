/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:32:51 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 15:13:34 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t		i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (siz != 0)
	{
		while (siz-- > 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (dst[i] != '\0')
		i++;
	while (dst[i])
		dst[i++] = '\0';
	return (ft_strlen(src));
}
