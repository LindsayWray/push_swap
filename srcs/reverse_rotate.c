#include "push_swap.h"

static t_element	*seperate_last_element(t_element *stack)
{
	t_element *last;

	while ((stack->next->next) != NULL)
		stack = (stack->next);
	last = stack->next;
	stack->next = NULL;
	return (last);
}

static void	reverse_rotate(t_element **stack)
{
	t_element	*rotating_element;
	rotating_element = seperate_last_element(*stack);
	ft_lstadd_front(stack, rotating_element);
}

void	rra(t_element **stack_a)
{
	if (ft_lstsize(*(stack_a)) > 1)
	{
		reverse_rotate(stack_a);
		add_operation("rra\n");
	}
}

void	rrb(t_element **stack_b)
{
	if (ft_lstsize(*(stack_b)) > 1)
	{
		reverse_rotate(stack_b);
		add_operation("rrb\n");
	}
}

void	rrr(t_element **stack_a, t_element **stack_b)
{
	rotate_both_stacks(stack_a, stack_b, reverse_rotate);
	add_operation("rrr\n");
}