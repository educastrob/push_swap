/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:33:57 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	destiny_length;
	size_t	result;

	result = 0;
	index = 0;
	destiny_length = ft_strlen(dst);
	result = ft_strlen(src) + destiny_length;
	if (destiny_length > size)
		return (ft_strlen(src) + size);
	while (index + 1 < (size - destiny_length) && src[index])
	{
		dst[destiny_length + index] = src[index];
		index++;
	}
	dst[destiny_length + index] = '\0';
	return (result);
}
