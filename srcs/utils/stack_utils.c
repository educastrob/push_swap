/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:46 by educastro         #+#    #+#             */
/*   Updated: 2024/03/13 06:19:01 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->size = 0;
	ptr->top = NULL;
	ptr->bottom = NULL;
	return (ptr);
}

t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
}