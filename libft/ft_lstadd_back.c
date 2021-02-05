/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:37:04 by kgale             #+#    #+#             */
/*   Updated: 2020/11/05 12:36:05 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	void	*f;

	if (lst)
	{
		if (!*lst && new)
		{
			*lst = new;
		}
		else if (new)
		{
			f = *lst;
			*lst = ft_lstlast(*lst);
			(*lst)->next = new;
			*lst = f;
		}
	}
}
