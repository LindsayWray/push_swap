/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:41:27 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:41:30 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_duplicate(int number, t_element *stack)
{
	while (stack)
	{
		if (stack->content == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	create_stack(int number, t_element **stack_a)
{
	t_element	*newest;

	if (find_duplicate(number, *stack_a))
		parsing_error(stack_a);
	newest = ft_lstnew(number);
	ft_lstadd_back(stack_a, newest);
}
