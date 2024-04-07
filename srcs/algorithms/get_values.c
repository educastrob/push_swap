/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:20:07 by educastro         #+#    #+#             */
/*   Updated: 2024/03/21 16:46:44 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_min_value(t_stack *a, size_t stack_size)
{
	int		min;
	t_node	*temp_node;

	min = a->top->value;
	temp_node = a->top;
	while (stack_size--)
	{
		if (temp_node->value < min)
			min = temp_node->value;
		temp_node = temp_node->prev;
	}
	return (min);
}

int	get_max_value(t_stack *a, size_t stack_size)
{
	int		max;
	t_node	*temp_node;

	max = a->top->value;
	temp_node = a->top;
	while (stack_size--)
	{
		if (temp_node->value > max)
			max = temp_node->value;
		temp_node = temp_node->prev;
	}
	return (max);
}