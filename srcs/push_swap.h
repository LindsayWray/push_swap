#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef	struct s_operations
{
	char *content;
	struct s_operations *next;
}				t_operations;

typedef struct s_chunk
{
	int min;
	int max;
	int size;
}			t_chunk;

t_element	*put_int_in_stack(const char *str, t_element *stack_a);
t_element	*create_stack(int number, t_element *stack_a);
void		clear_stack(t_element **stack);
void	rotate_both_stacks(t_element **stack_a, t_element **stack_b,
		void (*rotate_function)(t_element **));
void		print_both_stack(t_element *stack_a, t_element *stack_b);
void		print_stack(t_element *stack);
int 	ascending_order(t_element *stack);
int 	descending_order(t_element *stack);
t_operations	*add_operation(char *operation);
void 	pa(t_element **stack_b, t_element **stack_a);
void 	pb(t_element **stack_a, t_element **stack_b);
void 	ra(t_element **stack_a);
void 	rb(t_element **stack_b);
void	rra(t_element **stack_a);
void	rrb(t_element **stack_b);
void	clear_operations(t_operations **lst);
t_chunk		*fill_array(t_element *stack, int size, int amount_of_chunks);
void	sort_stack(t_chunk *chunks, t_element **stack_a, t_element **stack_b, int amount_of_chunks);
int 	chunk_amount(int len);
t_operations *get_operation_list(void);
void	optimise(t_operations *operations);
#endif