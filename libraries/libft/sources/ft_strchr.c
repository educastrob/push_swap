/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:33:46 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*first_occurrence;

	first_occurrence = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			first_occurrence = (char *)s;
			break ;
		}
		s++;
	}
	if (!c || *s == (unsigned char)c)
		first_occurrence = (char *)s;
	return (first_occurrence);
}
