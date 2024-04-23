/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:57:35 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_stacks(t_stack *a, t_stack *b, void *move, t_byte stacks);
static void	print_moves(void *move, t_byte stacks);

void	apply_move(t_stack *a, t_stack *b, void *move, t_byte stacks)
{
	if (check_stacks(a, b, move, stacks))
		return ;
	if (move == push)
	{
		if (stacks == B)
			push(a, b);
		else
			push(b, a);
	}
	else
	{
		if (stacks & A)
			((t_move_stack)move)(a);
		if (stacks & B)
			((t_move_stack)move)(b);
	}
	print_moves(move, stacks);
}

static int	check_stacks(t_stack *a, t_stack *b, void *move, t_byte stacks)
{
	return (((move == push) && ((stacks == A && b->size < 1)
				|| (stacks == B && a->size < 1)))
		|| ((move != push) && ((stacks == A && a->size <= 1)
				|| (stacks == B && b->size <= 1))));
}

static void	print_moves(void *move, t_byte stacks)
{
	char	*move_abbreviation;

	if (move == push)
		move_abbreviation = "p";
	else if (move == swap)
		move_abbreviation = "s";
	else if (move == rotate)
		move_abbreviation = "r";
	else
		move_abbreviation = "rr";
	ft_putstr_fd(move_abbreviation, STDOUT_FILENO);
	if (stacks == A)
		ft_putstr_fd("a", STDOUT_FILENO);
	else if (stacks == B)
		ft_putstr_fd("b", STDOUT_FILENO);
	else
		ft_putchar_fd(*move_abbreviation, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
