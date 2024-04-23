/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:34:22 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start >= len)
		substring = ft_calloc((len + 1), sizeof(char));
	else
		substring = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	if (substring)
	{
		if (len > ft_strlen(s) + 1)
			len = ft_strlen(s) + 1;
		ft_strlcpy(substring, (s + start), (len + 1));
	}
	else
		return (NULL);
	return (substring);
}
