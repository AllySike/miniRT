/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgale <kgale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:51:56 by kgale             #+#    #+#             */
/*   Updated: 2020/11/03 22:44:39 by kgale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_count_range(int n)
{
	int		range;
	int		nbr;

	range = 0;
	nbr = 1000000000;
	while (n != 0 && n / nbr == 0 && range++ < 10)
		nbr /= 10;
	if (n == 0)
		range = 10;
	range = 10 - range;
	if (n <= 0)
		range++;
	return (range);
}

static long int	ft_count_nbr(int n)
{
	int			range;
	long int	nbr;

	range = 0;
	nbr = 1000000000;
	while (n != 0 && n / nbr == 0 && range++ < 10)
		nbr /= 10;
	return (nbr);
}

char			*ft_itoa(int n)
{
	char		*output;
	long int	nmbr;
	int			i;
	int			range;
	long int	nbr;

	i = 0;
	nbr = ft_count_nbr(n);
	range = ft_count_range(n);
	output = (char *)malloc(sizeof(char) * (range + 1));
	nmbr = (long)n;
	if (n < 0 && output != NULL)
	{
		output[i++] = '-';
		nmbr *= -1;
	}
	while (i < range && output != NULL)
	{
		output[i++] = (nmbr / nbr + '0');
		nmbr %= nbr;
		nbr /= 10;
	}
	if (output != NULL)
		output[i] = '\0';
	return (output);
}
