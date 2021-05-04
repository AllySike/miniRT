#include "../includes/cub3d.h"

static t_map	*ft_maplast(t_map *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_mapadd_back(t_map **lst, t_map *new)
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
			*lst = ft_maplast(*lst);
			(*lst)->next = new;
			*lst = f;
		}
	}
}

t_map	*ft_mapnew(char *content)
{
	t_map	*elem;

	elem = (t_map *)malloc(sizeof(t_map));
	if (elem == NULL)
		return (NULL);
    elem->len = ft_strlen(content);
	(*elem).line = ft_strdup(content);
	(*elem).next = NULL;
	return (elem);
}

int	ft_mapsize(t_map *lst)
{
    int	i;

    i = 0;
    if (!lst)
        return (0);
    else
    {
        while (lst && lst->next)
        {
            lst = lst->next;
            i++;
            if (!lst->next)
                return (i + 1);
        }
    }
    return (i + 1);
}
