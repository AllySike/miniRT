/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:08:06 by kgale             #+#    #+#             */
/*   Updated: 2020/11/03 22:44:39 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*output;
	unsigned int	index;
	unsigned int	length;

	if (s == NULL)
		return (NULL);
	index = 0;
	length = ft_strlen(s);
	if (start > length)
		len = 0;
	else if (length - start - 1 < len)
		len = length - start;
	output = (char *)malloc(len + 1);
	if (output == NULL)
		return (NULL);
	while (index < len)
	{
		output[index] = s[index + start];
		index++;
		if (s[index - 1 + start] == '\0')
			return (output);
	}
	output[index] = '\0';
	return (output);
}