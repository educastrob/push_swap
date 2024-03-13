/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:03:16 by edcastro          #+#    #+#             */
/*   Updated: 2024/03/13 04:58:38 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
