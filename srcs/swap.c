#include "push_swap.h"

static void swap(t_element *stack)
{
    int stored_value;
    
    stored_value = stack->content;
    stack->content = stack->next->content;
    stack->next->content = stored_value;

}

void 	sa(t_element **stack_a)
{
		swap(*stack_a);
		add_operation("sa\n");
}

void 	sb(t_element **stack_b)
{
		swap(*stack_b);
		add_operation("sb\n");
}