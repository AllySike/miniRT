/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:46:23 by kgale             #+#    #+#             */
/*   Updated: 2021/02/05 15:10:35 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_buff	*ft_find_fd_in_lst(t_buff **lst, int fd)
{
	t_buff	*tmp;

	if (!lst)
		return (NULL);
	tmp = *lst;
	while (tmp)
	{
		if (tmp && tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (ft_lstadd_back(lst, NULL, 1, fd));
}

int		ft_read_fd(char **dst, const int fd, t_buff *elem)
{
	int		result;
	char	buff[BUFFER_SIZE + 1];
	int		i;
	int		flag;
	char	*dest;

	flag = 0;
	while (flag != 1 && (result = read(fd, buff, BUFFER_SIZE)))
	{
		if (result < BUFFER_SIZE)
			elem->end = 1;
		buff[result] = '\0';
		dest = *dst;
		if (!(*dst = ft_strjoin(*dst, buff)))
			return (-1);
		free(dest);
		i = 0;
		flag = 0;
		while (buff[i])
			if (buff[i] == '\0' || buff[i++] == '\n')
				flag = 1;
	}
	if (result == 0 && flag == 0)
		elem->end = 1;
	return (result);
}

int		ft_write_in_line(char **line, char *content)
{
	int	i;
	int	index;

	i = 0;
	while (content && content[i] && content[i] != '\0' && content[i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	index = 0;
	while (content && content[index] && index < i)
	{
		line[0][index] = content[index];
		index++;
	}
	line[0][index] = '\0';
	return (i);
}

int		ft_find_end_line_in_buff(char *str, t_buff **lst, int fd)
{
	t_buff	*curr;
	t_buff	*next;

	if (!str)
		return (0);
	while (*str)
		if (*str == '\0' || *str++ == '\n')
			return (0);
	curr = *lst;
	if (curr->fd == fd)
		*lst = curr->next;
	else
		while (curr && (next = curr->next))
		{
			if (next->fd == fd)
			{
				curr->next = next->next;
				curr = next;
				break ;
			}
			curr = curr->next;
		}
	free(curr->content);
	free(curr);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				res;
	char			*tmp;
	static t_buff	*lst;
	t_buff			*currelem;
	char			buff[BUFFER_SIZE + 1];

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1
		|| !(currelem = ft_find_fd_in_lst(&lst, fd)))
		return (-1);
	tmp = currelem->content;
	if (!(res = ft_read_fd(&tmp, fd, currelem)) && (!tmp || (tmp && !*tmp)))
	{
		ft_write_in_line(line, currelem->content);
		ft_find_end_line_in_buff(currelem->content, &lst, fd);
		return (0);
	}
	currelem->content = tmp;
	if ((res = ft_write_in_line(line, tmp)) == -1)
		return (-1);
	if (currelem->end && ft_find_end_line_in_buff(tmp, &lst, fd))
		return (0);
	else
		fd = 1;
	ft_strlcpy(&(tmp), &(tmp[res + 1]), ft_strlen(tmp) - res, 0);
	return (fd);
}
