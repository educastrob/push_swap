/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:46 by educastro         #+#    #+#             */
/*   Updated: 2024/03/13 19:23:47 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	init_stacks(t_stack *a, t_stack *b, char **args_list)
{
	t_node	*new_node;
	t_node	*top_node;
	t_node	*prev_node;

	top_node = malloc(sizeof(t_node));
	if (!top_node)
		return ;
	*top_node = (t_node){ft_atoi(*args_list++), NULL, NULL};
	prev_node = top_node;
	a->size = 1;
	while (*args_list)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		*new_node = (t_node){ft_atoi(*args_list), NULL, prev_node};
		prev_node->prev = new_node;
		prev_node = new_node;
		a->size++;
		args_list++;
	}
	*a = (t_stack){a->size, top_node, prev_node};
	*b = (t_stack){0, NULL, NULL};
}

enum e_boolean	stack_is_sorted(t_stack *stack)
{
	t_node	temp_node;

	if (!stack || !stack->top)
		return (FALSE);
	temp_node = *stack->top;
	while (temp_node.prev)
	{
		if (temp_node.value > temp_node.prev->value)
			return (FALSE);
		temp_node = *temp_node.prev;
	}
	return (TRUE);
}

void	free_nodes(t_node *top_node)
{
	t_node	*temp_node;

	while (top_node)
	{
		temp_node = top_node;
		top_node = top_node->prev;
		free(temp_node);
	}
}