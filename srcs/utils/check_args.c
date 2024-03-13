/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:25:38 by educastro         #+#    #+#             */
/*   Updated: 2024/03/13 05:30:29 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static enum e_boolean	args_are_numbers(char **args_list)
{
	char	*temp_arg;

	while (*args_list)
	{
		temp_arg = *args_list;
		if (*temp_arg == '-')
			temp_arg++;
		while (*temp_arg)
		{
			if (!ft_isdigit(*temp_arg))
				return (FALSE);
			temp_arg++;
		}
		args_list++;
	}
	return (TRUE);
}

static enum e_boolean	args_are_duplicates(char **args_list)
{
	size_t	index;
	size_t	comp_len;

	while (*args_list)
	{
		index = 1;
		while (args_list[index])
		{
			comp_len = ft_operate((int) ft_strlen(*args_list),
					(int) ft_strlen(args_list[index]), MAX);
			if (!ft_strncmp(*args_list, args_list[index], comp_len))
				return (TRUE);
			index++;
		}
		args_list++;
	}
	return (FALSE);
}

static enum e_boolean	args_are_integers(char **args_list)
{
	while (*args_list)
	{
		if (ft_atol(*args_list) > INT_MAX || ft_atol(*args_list) < INT_MIN)
			return (FALSE);
		args_list++;
	}
	return (TRUE);
}

void	free_args_list(char **args_list, enum e_boolean is_split)
{
	if (is_split)
	{
		ft_for_each((void **) args_list, free());
		free(args_list);
	}
}

void	check_args_list(char **args_list, enum e_boolean is_split)
{
	if (!args_are_numbers(args_list) || args_are_duplicates(args_list)
		|| !args_are_integers(args_list))
	{
		free_args_list(args_list, is_split);
		ft_handle_error(ERROR_MESSAGE);
	}
}