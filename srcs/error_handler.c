/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:41:35 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:41:37 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_error(t_element **stack_a)
{
	clear_stack(stack_a);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	malloc_error(t_element **stack_a)
{
	clear_stack(stack_a);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	operation_input_error(t_element **stack_a, t_element **stack_b)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}
