/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:41:18 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:41:21 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	free(*lst);
	*lst = NULL;
}

void	cleanup_stacks(t_element **stack_a, t_element **stack_b)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
}
