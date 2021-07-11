#include "push_swap.h"

int     find_duplicate(int number, t_element *stack)
{
    while (stack)
    {
        if (stack->content == number)
            return (1);
        stack = stack->next;
    }
    return (0);
}


t_element *create_stack(int number, t_element* stack_a)
{
    t_element *newest;

    if (find_duplicate(number, stack_a))
    {
        clear_stack(&stack_a);
        return (NULL);
    }
    newest = ft_lstnew(number);
    ft_lstadd_back(&stack_a, newest);
    return (stack_a);
}