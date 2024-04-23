/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:20:07 by educastro         #+#    #+#             */
/*   Updated: 2024/04/22 17:36:55 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	enum e_boolean	is_split;
	char			**args_list;

	is_split = FALSE;
	args_list = NULL;
	if (!argv || argc < 2)
		return (EXIT_FAILURE);
	else if (argc == 2)
	{
		args_list = ft_split(argv[1], ' ');
		is_split = TRUE;
	}
	else
		args_list = argv[1];
	check_args_list(args_list, is_split);
	init_stacks(&a, &b, args_list);
	if (!stack_is_sorted(&a))
		sort_stack(a.size, &a, &b, 0);
	free_args_list(args_list, is_split);
	free_nodes(a.top);
}