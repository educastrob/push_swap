/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:33:39 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_sort_int_arr(int *arr, size_t size)
{
	size_t	first_index;
	size_t	second_index;

	first_index = 0;
	while (first_index < size)
	{
		second_index = first_index + 1;
		while (second_index < size)
		{
			if (arr[first_index] > arr[second_index])
				ft_swap((arr + first_index), (arr + second_index));
			second_index++;
		}
		first_index++;
	}
}
