/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:25:52 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 15:13:45 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			if (s[i] == (char)c)
				return ((char *)&s[i]);
			i++;
		}
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
