#include "push_swap.h"

void	print_stack(t_element *stack)
{
	ft_printf("stack A\n");
    while(stack)
    {
        ft_printf("%d\n",(stack->content));
        stack = stack->next;
    }
}

void	print_both_stack(t_element *stack_a, t_element *stack_b)
{
	ft_printf("stack A\n");
    while(stack_a)
    {
        ft_printf("%d\n",(stack_a->content));
        stack_a = stack_a->next;
    }
    ft_printf("stack B\n");
    while(stack_b)
    {
        ft_printf("%d\n", (stack_b->content));
        stack_b = stack_b->next;
    }
}