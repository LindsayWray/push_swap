/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:43:24 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:43:27 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_operations
{
	char				*content;
	struct s_operations	*next;
}				t_operations;

typedef struct s_chunk
{
	int	min;
	int	max;
	int	size;
}			t_chunk;

void			put_int_in_stack(const char *str, t_element **stack_a);
void			create_stack(int number, t_element **stack_a);
void			clear_stack(t_element **stack);
void			rotate(t_element **stack);
void			reverse_rotate(t_element **stack);
void			rotate_both_stacks(t_element **stack_a, t_element **stack_b,
					void (*rotate_function)(t_element **));
int				ascending_order(t_element *stack);
t_operations	*add_operation(char *operation);
void			parsing_error(t_element **stack_a);
void			malloc_error(t_element **stack_a);
void			operation_input_error(t_element **stack_a, t_element **stack_b);
void			swap(t_element *stack);
void			swap_both_stacks(t_element *stack_a, t_element *stack_b);
void			push(t_element **pushing_stack, t_element **receiving_stack);
void			sa(t_element **stack_a);
void			sb(t_element **stack_b);
void			pa(t_element **stack_b, t_element **stack_a);
void			pb(t_element **stack_a, t_element **stack_b);
void			ra(t_element **stack_a);
void			rb(t_element **stack_b);
void			rra(t_element **stack_a);
void			rrb(t_element **stack_b);
void			clear_operations(t_operations **lst);
t_chunk			*make_chunks(t_element *stack, int size, int amount_of_chunks);
void			push_back_to_a(t_element **stack_a, t_element **stack_b,
					int chunk_size);
int				chunk_amount(int len);
t_operations	*get_operation_list(void);
void			optimizer(t_operations *operations);
void			small_stack_sort(t_element **stack_a, t_element **stack_b,
					int len);
void			big_stack_sort(t_element **stack_a, t_element **stack_b,
					int len);
void			sort_array(int *array, int len);
void			print_operations(t_operations *operations);
void			cleanup_stacks(t_element **stack_a, t_element **stack_b);
void			optimize_and_print(void);
#endif
