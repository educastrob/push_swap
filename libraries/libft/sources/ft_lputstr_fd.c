/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:32:18 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lputstr_fd(char *s, int fd)
{
	size_t	written_bytes;

	written_bytes = 0;
	if (!s)
		return (write(fd, NULL_STRING, ft_strlen(NULL_STRING)));
	while (*s)
		written_bytes += write(fd, s++, sizeof(char));
	return (written_bytes);
}
