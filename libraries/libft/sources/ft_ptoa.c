/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:33:17 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ptoa(size_t nbr)
{
	char	*string;
	char	*temp;

	if (!nbr)
		return (ft_strdup(NULL_POINTER));
	temp = ft_itoa_hex(nbr, 16, LOWER_HEXAS);
	string = ft_strjoin("0x", temp);
	free(temp);
	return (string);
}
