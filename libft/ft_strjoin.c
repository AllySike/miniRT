/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:36:49 by kgale             #+#    #+#             */
/*   Updated: 2020/11/03 22:44:39 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		index;
	char	*output;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	index = 0;
	output = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (output == NULL)
		return (NULL);
	while (index < len1)
	{
		output[index] = s1[index];
		index++;
	}
	index = 0;
	while (index < len2)
	{
		output[index + len1] = s2[index];
		index++;
	}
	output[len1 + len2] = '\0';
	return (output);
}
