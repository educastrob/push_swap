/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:30:59 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	***ft_arr_split(char **array, char delimiter)
{
	char	***split_array;
	size_t	length;

	length = ft_arr_len(array);
	split_array = ft_calloc(length + 1, sizeof(char **));
	split_array[length] = NULL;
	while (length--)
		split_array[length] = ft_split(array[length], delimiter);
	return (split_array);
}
