/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:20:07 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 03:44:22 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reorder_rr(t_stack *a, t_stack *b, t_rr params, t_values *values)
{
	size_t	rotate_both;
	size_t	rotate_a_remaining;
	size_t	rotate_b_remaining;

	rotate_both = ft_operate(values->rotate_a, values->rotate_b, MIN);
	rotate_a_remaining = values->rotate_a - rotate_both;
	rotate_b_remaining = values->rotate_b - rotate_both;
	if (params.iterations > 0 || params.priority_stack == B)
	{
		while (rotate_both--)
			apply_move(a, b, reverse_rotate, AB);
		while (rotate_a_remaining--)
			apply_move(a, b, reverse_rotate, A);
		while (rotate_b_remaining--)
			apply_move(a, b, reverse_rotate, B);
		return ;
	}
	rotate_b_remaining = ft_operate(rotate_both, values->rotate_b, MAX);
	while (rotate_b_remaining--)
		apply_move(a, b, reverse_rotate, B);
}