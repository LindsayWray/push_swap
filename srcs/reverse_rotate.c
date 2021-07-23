/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:43:38 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:43:40 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_element	*seperate_last_element(t_element *stack)
{
	t_element	*last;

	while ((stack->next->next) != NULL)
		stack = (stack->next);
	last = stack->next;
	stack->next = NULL;
	return (last);
}

void	reverse_rotate(t_element **stack)
{
	t_element	*rotating_element;

	if (ft_lstsize(*(stack)) > 1)
	{
		rotating_element = seperate_last_element(*stack);
		ft_lstadd_front(stack, rotating_element);
	}
}

void	rra(t_element **stack_a)
{
	if (ft_lstsize(*(stack_a)) > 1)
	{
		reverse_rotate(stack_a);
		add_operation("rra");
	}
}

void	rrb(t_element **stack_b)
{
	if (ft_lstsize(*(stack_b)) > 1)
	{
		reverse_rotate(stack_b);
		add_operation("rrb");
	}
}
