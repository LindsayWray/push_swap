/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_order.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:41:04 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:41:09 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ascending_order(t_element *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL && stack->content < stack->next->content)
		stack = stack->next;
	if (stack->next == NULL)
		return (1);
	return (0);
}
