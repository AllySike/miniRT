/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:48:39 by kgale             #+#    #+#             */
/*   Updated: 2020/12/20 02:37:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_buff
{
	char			*content;
	int				fd;
	struct s_buff	*next;
	int				end;
}					t_buff;

int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
t_buff				*ft_lstadd_back(t_buff **lst,
					char *content, int len, int fd);
int					ft_strlen(const char *str);
void				ft_strlcpy(char **dst, const char *src, int siz, int index);

#endif
