/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:33:55 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	length;

	length = ft_strlen(s1);
	string = (char *)malloc(length + ft_strlen(s2) + 1);
	if (string && s1 && s2)
	{
		ft_strlcpy(string, s1, length + 1);
		while (*s2)
			string[length++] = *s2++;
		string[length] = '\0';
	}
	return (string);
}
