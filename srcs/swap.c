/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:44:09 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:44:11 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_element *stack)
{
	int	stored_value;

	if (ft_lstsize(stack) > 1)
	{
		stored_value = stack->content;
		stack->content = stack->next->content;
		stack->next->content = stored_value;
	}
}

void	swap_both_stacks(t_element *stack_a, t_element *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	sa(t_element **stack_a)
{
	if (ft_lstsize(*(stack_a)) > 1)
	{
		swap(*stack_a);
		add_operation("sa");
	}
}

void	sb(t_element **stack_b)
{
	if (ft_lstsize(*(stack_b)) > 1)
	{
		swap(*stack_b);
		add_operation("sb");
	}
}
