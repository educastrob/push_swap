/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputaddress_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:31:58 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputaddress_fd(size_t nbr, int fd)
{
	size_t	written_bytes;

	written_bytes = 0;
	if (!nbr)
	{
		written_bytes += ft_lputstr_fd(NULL_POINTER, fd);
		return (written_bytes);
	}
	written_bytes += ft_lputstr_fd("0x", fd);
	written_bytes += ft_lputhexa_fd(nbr, fd, 'x');
	return (written_bytes);
}
