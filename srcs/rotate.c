#include "push_swap.h"

static void	rotate(t_element **stack)
{
	t_element	*rotating_element;

	rotating_element = *stack;
	*stack = (*stack)->next;
	rotating_element->next = NULL;
	ft_lstadd_back(stack, rotating_element);
}

void	rotate_both_stacks(t_element **stack_a, t_element **stack_b,
		void (*rotate_function)(t_element **))
{
	rotate_function(stack_a);
	rotate_function(stack_b);
}

void 	ra(t_element **stack_a)
{
	if (ft_lstsize(*(stack_a)) > 1)
	{
		rotate(stack_a);
		add_operation("ra\n");
	}
}

void 	rb(t_element **stack_b)
{
	if (ft_lstsize(*(stack_b)) > 1)
	{
		rotate(stack_b);
		add_operation("rb\n");
	}
}

void	rr(t_element **stack_a, t_element **stack_b)
{
	rotate_both_stacks(stack_a, stack_b, rotate);
	add_operation("rr\n");
}