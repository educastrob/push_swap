/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:34:13 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*first_occurrence;
	size_t	i;
	size_t	l_len;

	first_occurrence = NULL;
	i = 0;
	l_len = ft_strlen(little);
	while (big[i] && i < len && l_len)
	{
		if (!ft_strncmp((big + i), little, l_len) && (i + l_len <= len))
		{
			first_occurrence = (char *)(big + i);
			break ;
		}
		i++;
	}
	if (!l_len)
		first_occurrence = (char *)big;
	return (first_occurrence);
}
