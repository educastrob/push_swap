/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:32:10 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputnbr_fd(long nbr, int fd)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		written_bytes += write(fd, "-", sizeof(char));
	}
	if (nbr / 10 > 0)
		written_bytes += ft_lputnbr_fd(nbr / 10, fd);
	converter = nbr % 10 + '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
