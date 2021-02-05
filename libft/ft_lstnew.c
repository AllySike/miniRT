/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:01:35 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 15:12:49 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	(*elem).content = content;
	(*elem).next = NULL;
	return (elem);
}
