/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 06:49:34 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_sort(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		is_split;
	char	**args_list;

	is_split = FALSE;
	args_list = NULL;
	if (!argv || argc == 1)
		return (EXIT_FAILURE);
	else if (argc == 2)
	{
		args_list = ft_split(argv[1], ' ');
		is_split = TRUE;
	}
	else
		args_list = argv + 1;
	check_args_list(args_list, is_split);
	init_stacks(&a, &b, args_list);
	free_args_list(args_list, is_split);
	read_moves(&a, &b);
	check_sort(&a, &b);
	free_nodes(a.top);
	free_nodes(b.top);
	return (EXIT_SUCCESS);
}

static void	check_sort(t_stack *a, t_stack *b)
{
	if (stack_is_sorted(a) && !b->top)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}
