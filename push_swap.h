/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/01/22 16:45:30 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

// libs
# include <unistd.h>
# include <stdlib.h>
# include "./libft/inc/libft.h"

// macros
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node t_node;
typedef struct s_stack t_stack;

typedef struct	s_node
{
	int		value;
	t_node  *next;
	t_node	*prev;
}				t_node;

typedef struct	s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}				t_stack;

#endif