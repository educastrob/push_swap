/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:20:07 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 03:38:06 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push_rotate_a(t_stack *a, t_stack *b, t_values *values)
{
	if (a->top->value > values->big_pivot)
	{
		apply_move(a, b, rotate, A);
		values->rotate_a++;
	}
	else
	{
		apply_move(a, b, push, B);
		values->push_b++;
		if (b->top->value > values->small_pivot)
		{
			apply_move(a, b, rotate, B);
			values->rotate_b++;
		}
	}
}

void	push_rotate_b(t_stack *a, t_stack *b, t_values *values)
{
	if (b->top->value <= values->small_pivot)
	{
		apply_move(a, b, rotate, B);
		values->rotate_b++;
	}
	else
	{
		apply_move(a, b, push, A);
		values->push_a++;
		if (a->top->value <= values->big_pivot)
		{
			apply_move(a, b, rotate, A);
			values->rotate_a++;
		}
	}
}