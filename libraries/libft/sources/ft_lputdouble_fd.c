/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputdouble_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:32:05 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputdouble_fd(double nbr, int fd)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		written_bytes += write(fd, "-", sizeof(char));
	}
	written_bytes += ft_lputnbr_fd((int)nbr, fd);
	nbr -= (int)nbr;
	written_bytes += write(fd, ".", sizeof(char));
	while (((int)(nbr * 10)) / 1 > 0)
	{
		nbr *= 10.0;
		converter = ((int)nbr) % 10 + '0';
		written_bytes += write(fd, &converter, sizeof(char));
		nbr -= (int)nbr;
	}
	return (written_bytes);
}
