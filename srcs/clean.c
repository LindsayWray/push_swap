#include "push_swap.h"

void	clear_stack(t_element **stack)
{
	if ((*stack) == NULL)
		return ;
	if ((*stack)->next)
		clear_stack(&((*stack)->next));
	free (*stack);
	*stack = NULL;
}

void	clear_operations(t_operations **lst)
{
	if ((*lst)->next)
		clear_operations(&((*lst)->next));
	free((*lst)->content);
	free(*lst);
	*lst = NULL;
}