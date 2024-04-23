/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:31:48 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ilen(long long nbr, size_t base_len);
static char		ft_apply_checker(size_t *checker, char c);

char	*ft_itoa_base(long long nbr, size_t base_len, const char *base)
{
	char	*string;
	size_t	length;
	size_t	checker;

	length = ft_ilen(nbr, base_len);
	string = (char *)ft_calloc(length + 1, sizeof(char));
	checker = 0;
	if (!string)
		return (NULL);
	if (!nbr)
	{
		*string = ft_apply_checker(&checker, '0');
		return (string);
	}
	else if (nbr < 0)
	{
		*string = ft_apply_checker(&checker, '-');
		nbr = -nbr;
	}
	while (length > checker)
	{
		string[--length] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (string);
}

static char	ft_apply_checker(size_t *checker, char c)
{
	(*checker)++;
	return (c);
}

static size_t	ft_ilen(long long nbr, size_t base_len)
{
	size_t	counter;

	counter = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		counter++;
	}
	while (nbr)
	{
		nbr /= base_len;
		counter++;
	}
	return (counter);
}
