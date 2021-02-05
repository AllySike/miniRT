/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:47:19 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 15:11:08 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		ft_strlen(const char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

void	ft_strlcpy(char **dst, const char *src, int siz, int index)
{
	size_t	i;

	i = 0;
	while (--siz >= 0 && src[i])
	{
		dst[0][i + index] = src[i];
		i++;
	}
	dst[0][i + index] = '\0';
	while (dst[0][i + index] != '\0')
		i++;
	while (dst[0][i + index])
		dst[0][i++] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		index;
	char	*output;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	index = 0;
	if (!(output = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (index++ < len1)
		output[index - 1] = s1[index - 1];
	index = 0;
	while (index < len2)
	{
		output[index + len1] = s2[index];
		index++;
	}
	output[len1 + len2] = '\0';
	return (output);
}

t_buff	*ft_lstnew(char *content, t_buff *elem, int len, int fd)
{
	if (!content)
	{
		elem->content = NULL;
		elem->fd = fd;
		elem->end = 0;
	}
	else
		ft_strlcpy(&(elem->content), content, len, 0);
	return (elem);
}

t_buff	*ft_lstadd_back(t_buff **lst, char *content, int len, int fd)
{
	void	*f;
	t_buff	*elem;

	if ((elem = (t_buff *)malloc(sizeof(t_buff))))
	{
		ft_lstnew(content, elem, len, fd)->next = NULL;
		if (lst && elem)
		{
			if (elem && *lst)
			{
				f = *lst;
				while (*lst != NULL && (*lst)->next)
					*lst = (*lst)->next;
				(*lst)->next = elem;
				*lst = f;
			}
			else if (!*lst && elem)
				*lst = elem;
		}
	}
	return (elem);
}