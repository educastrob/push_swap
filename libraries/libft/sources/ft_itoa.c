/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:31:54 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ilen(long number);
static void		ft_putnbr_str(long n, size_t i, size_t len, char *str);

char	*ft_itoa(int n)
{
	long	number;
	size_t	length;
	char	*string;

	number = n;
	length = ft_ilen(number);
	string = ft_calloc(length + 1, sizeof(char));
	if (!string)
		return (NULL);
	if (number < 0)
	{
		number *= -1;
		*string = '-';
		ft_putnbr_str(number, 1, length, string);
	}
	else
		ft_putnbr_str(number, 0, length, string);
	return (string);
}

static size_t	ft_ilen(long number)
{
	size_t	counter;

	counter = 0;
	if (number <= 0)
	{
		number *= -1;
		counter++;
	}
	while (number)
	{
		number /= 10;
		counter++;
	}
	return (counter);
}

static void	ft_putnbr_str(long n, size_t i, size_t len, char *str)
{
	while (i < len)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
}
