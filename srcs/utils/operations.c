/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:25:38 by educastro         #+#    #+#             */
/*   Updated: 2024/03/20 10:28:14 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_stack *a)
{
	int	temp_value;

	if (a->size < 2)
		return ;
	temp_value = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = temp_value;
}