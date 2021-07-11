#include "push_swap.h"

static void    push(t_element **pushing_stack, t_element **receiving_stack)
{
    t_element *pushed_element;

    pushed_element = *pushing_stack;
    *pushing_stack = (*pushing_stack)->next;
    ft_lstadd_front(receiving_stack, pushed_element);
}

void 	pa(t_element **stack_b, t_element **stack_a)
{
	if (*stack_b)
	{
		push(stack_b, stack_a);
		add_operation("pa\n");
	}
}

void 	pb(t_element **stack_a, t_element **stack_b)
{
	if (*stack_a)
	{
		push(stack_a, stack_b);
		add_operation("pb\n");
	}
}