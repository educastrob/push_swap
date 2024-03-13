/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/03/13 19:34:49 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

// libs
# include <limits.h>
# include "../libft/inc/libft.h"

// macros
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ERROR_MESSAGE "Error\n"
# define A 0b1
# define B 0b10
# define AB 0b11

typedef struct s_node	t_node;
typedef struct s_values	t_values;
typedef struct s_stack	t_stack;

enum	e_boolean
{
	FALSE,
	TRUE
};

struct	s_node
{
	int		value;
	t_node  *next;
	t_node	*prev;
};

struct	s_stack
{
	size_t		size;
	t_node	*top;
	t_node	*bottom;
};

struct	s_values
{
	int 	big_pivot;
	int 	small_pivot;
	size_t	ra;
	size_t	rb;
	size_t	pa;
	size_t	pb;
};

# ifndef SWAPS
#  define SWAPS "sa sb ss"
# endif

# ifndef PUSHES
#  define PUSHES "pa pb"
# endif

# ifndef ROTATIONS
#  define ROTATIONS "ra rb rr rra rrb rrr"
# endif

// check_args.c
void			check_args_list(char **args_list, enum e_boolean is_split);
void			free_args_list(char **args_list, enum e_boolean is_split);
// stack_utils.c
void			init_stacks(t_stack *a, t_stack *b, char **args_list);
enum e_boolean	stack_is_sorted(t_stack *stack);
void			free_nodes(t_node *top_node);

#endif