/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:20:07 by educastro         #+#    #+#             */
/*   Updated: 2024/03/13 05:01:33 by educastro        ###   ########.fr       */
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
	
}