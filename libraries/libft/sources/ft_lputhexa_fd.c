/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputhexa_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:32:08 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputhexa_fd(size_t nbr, int fd, char specifier)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr / 16 > 0)
		written_bytes += ft_lputhexa_fd(nbr / 16, fd, specifier);
	converter = nbr % 16;
	if (converter > 9)
	{
		converter -= 10;
		if (specifier == 'X')
			converter += 'A';
		else
			converter += 'a';
	}
	else
		converter += '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
