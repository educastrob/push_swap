/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:43:54 by educastro         #+#    #+#             */
/*   Updated: 2024/04/23 05:58:07 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Headers
# include "../libraries/libft/includes/libft.h"
# include <limits.h>

//Macros
# define FALSE 0
# define TRUE 1
# define ERROR_MESSAGE "Error\n"
# define A 0b1
# define B 0b10
# define AB 0b11

//Typedefs
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	size_t	size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;
typedef struct s_values
{
	size_t	rotate_a;
	size_t	rotate_b;
	size_t	push_a;
	size_t	push_b;
	int		big_pivot;
	int		small_pivot;
}	t_values;
typedef void	(*t_move_stack)(t_stack *a);
typedef char	t_byte;
typedef struct s_rr
{
	t_byte	priority_stack;
	size_t	iterations;
}	t_rr;

# ifndef SWAPS
#  define SWAPS "sa sb ss"
# endif

# ifndef PUSHES
#  define PUSHES "pa pb"
# endif

# ifndef ROTATIONS
#  define ROTATIONS "ra rb rr rra rrb rrr"
# endif

//Prototypes
void	check_args_list(char **args_list, int is_split);
void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	rotate(t_stack *a);
void	reverse_rotate(t_stack *a);
void	apply_move(t_stack *a, t_stack *b, void *move, t_byte stack);
void	sort_stack(size_t size, t_stack *a, t_stack *b, size_t iterations);
void	five_sort(t_stack *a, t_stack *b, t_byte priority_stack);
void	small_sort(size_t size, t_stack *a, t_stack *b, t_byte stack);
void	three_sort(t_stack *a, t_stack *b, t_byte s);
void	top_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n);
void	mid_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n);
void	bot_min_sort(t_stack *a, t_stack *b, t_byte priority_stack, int n);
void	two_sort(t_stack *a, t_stack *b, t_byte stack);
void	push_rotate_a(t_stack *a, t_stack *b, t_values *values);
void	push_rotate_b(t_stack *a, t_stack *b, t_values *values);
void	reorder_rr(t_stack *a, t_stack *b, t_rr params, t_values *values);
void	free_args_list(char **args_list, int is_split);
void	init_stacks(t_stack *a, t_stack *b, char **args_list);
void	free_nodes(t_node *top_node);
void	read_moves(t_stack *a, t_stack *b);
int		stack_is_sorted(t_stack *stack);
int		get_min_value(t_stack *a, size_t stack_size);
int		get_max_value(t_stack *a, size_t stack_size);

#endif //PUSH_SWAP_H
