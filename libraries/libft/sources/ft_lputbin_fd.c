/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputbin_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:32:02 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputbin_fd(size_t nbr, int fd)
{
	size_t	written_bytes;
	char	converter;

	written_bytes = 0;
	if (nbr / 2 > 0)
		written_bytes += ft_lputbin_fd(nbr / 2, fd);
	converter = nbr % 2 + '0';
	written_bytes += write(fd, &converter, sizeof(char));
	return (written_bytes);
}
