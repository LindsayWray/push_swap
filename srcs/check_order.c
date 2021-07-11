#include "push_swap.h"

int 	ascending_order(t_element *stack)
{
	while (stack->next != NULL && stack->content < stack->next->content)
		stack = stack->next;
	if (stack->next == NULL)
		return (1);
	return (0);
}

int 	descending_order(t_element *stack)
{
	while (stack->next != NULL && stack->content > stack->next->content)
		stack = stack->next;
	if (stack->next == NULL)
		return (1);
	return (0);
}