/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:22:32 by kgale             #+#    #+#             */
/*   Updated: 2020/11/05 12:17:39 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	void	*ref;

	if (lst && *lst)
	{
		while (*lst)
		{
			ref = (void *)(*lst)->next;
			(*del)(*lst);
			*lst = ref;
		}
		*lst = NULL;
	}
}
