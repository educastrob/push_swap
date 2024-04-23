/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:36:01 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	top_min_sort_b(t_stack *a, t_stack *b, int n);
static void	mid_min_sort_b(t_stack *a, t_stack *b, int n);

void	top_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n)
{
	if (priority_stack == A)
	{
		if (a->top->prev->value == n)
		{
			if (a->size <= 3)
			{
				apply_move(a, b, reverse_rotate, A);
				apply_move(a, b, swap, A);
			}
			else
			{
				apply_move(a, b, rotate, A);
				apply_move(a, b, swap, A);
				apply_move(a, b, reverse_rotate, A);
			}
		}
	}
	else
	{
		top_min_sort_b(a, b, n);
	}
}

void	top_min_sort_b(t_stack *a, t_stack *b, int n)
{
	if (b->size <= 3)
		apply_move(a, b, rotate, B);
	else
	{
		apply_move(a, b, swap, B);
		apply_move(a, b, rotate, B);
		apply_move(a, b, swap, B);
		apply_move(a, b, reverse_rotate, B);
	}
	if (b->top->prev->value == n)
		apply_move(a, b, swap, B);
}

void	mid_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n)
{
	if (priority_stack == A)
	{
		if (a->size <= 3)
		{
			if (a->bottom->value == n)
				apply_move(a, b, swap, A);
			else
				apply_move(a, b, rotate, A);
		}
		else
		{
			apply_move(a, b, swap, A);
			if (a->top->prev->value == n)
			{
				apply_move(a, b, rotate, A);
				apply_move(a, b, swap, A);
				apply_move(a, b, reverse_rotate, A);
			}
		}
	}
	else
	{
		mid_min_sort_b(a, b, n);
	}
}

static void	mid_min_sort_b(t_stack *a, t_stack *b, int n)
{
	if (b->size <= 3)
		apply_move(a, b, reverse_rotate, B);
	else
	{
		apply_move(a, b, rotate, B);
		apply_move(a, b, swap, B);
		apply_move(a, b, reverse_rotate, B);
	}
	if (b->top->prev->value == n)
		apply_move(a, b, swap, B);
}

void	bot_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n)
{
	if (priority_stack == A)
	{
		if (a->top->value == n)
			apply_move(a, b, swap, A);
		if (a->size <= 3)
			apply_move(a, b, reverse_rotate, A);
		else
		{
			apply_move(a, b, rotate, A);
			apply_move(a, b, swap, A);
			apply_move(a, b, reverse_rotate, A);
			apply_move(a, b, swap, A);
		}
	}
	else if (b->top->prev->value == n)
		apply_move(a, b, swap, B);
}
