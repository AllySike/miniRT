/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:30:30 by marvin            #+#    #+#             */
/*   Updated: 2020/11/03 22:44:39 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*output;
	int		len;

	i = 0;
	len = ft_strlen(s);
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (output == NULL || f == NULL)
		return (NULL);
	while (i < len)
	{
		output[i] = (*f)(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
