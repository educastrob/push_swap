/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 03:56:50 by educastro        ###   ########.fr       */
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
typedef struct s_rr		t_rr;
typedef void	(*t_move_stack)(t_stack *a);
typedef char	t_byte;

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
	size_t	rotate_a;
	size_t	rotate_b;
	size_t	push_a;
	size_t	push_b;
};

struct s_rr
{
	t_byte	priority_stack;
	size_t	iterations;
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
// operations.c
void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	reverse_rotate(t_stack *a);
void	rotate(t_stack *a);
// get_values.c
int		get_min_value(t_stack *a, size_t stack_size);
int		get_max_value(t_stack *a, size_t stack_size);
// apply_move.c
void	apply_move(t_stack *a, t_stack *b, void *move, t_byte stacks);
// small_sort.c
void	small_sort(size_t size, t_stack *a, t_stack *b, t_byte stack);
void	two_sort(t_stack *a, t_stack *b, t_byte stack);
void	three_sort(t_stack *a, t_stack *b, t_byte s);
// sort_stack.c
void	sort_stack(size_t size, t_stack *a, t_stack *b, size_t iterations);
// three_sort_utils.c
void	top_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n);
void	mid_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n);
void	bot_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n);
// five_sort.c
void	five_sort(t_stack *a, t_stack *b, t_byte priority_stack);
// push_rotates.c
void	push_rotate_a(t_stack *a, t_stack *b, t_values *values);
void	push_rotate_b(t_stack *a, t_stack *b, t_values *values);
// reorder_rr.c
void	reorder_rr(t_stack *a, t_stack *b, t_rr params, t_values *values);

#endif