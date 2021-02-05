/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:31:26 by kgale             #+#    #+#             */
/*   Updated: 2020/11/03 22:44:39 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*source;
	char	*dst;
	size_t	i;

	if (dest != NULL && src != NULL)
	{
		source = (char *)src;
		dst = (char *)dest;
		if (dst > source)
		{
			while (n-- > 0)
				dst[n] = source[n];
		}
		else
		{
			i = 0;
			while (i < n)
			{
				dst[i] = source[i];
				i++;
			}
		}
	}
	return (dest);
}
