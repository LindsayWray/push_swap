/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:41:45 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:41:47 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(int argc, char *argv[], t_element **stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		put_int_in_stack(argv[i], stack);
		i++;
	}
	if (ascending_order(*stack))
	{
		clear_stack(stack);
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	int			stack_len;
	t_element	*stack_a;
	t_element	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_input(argc, argv, &stack_a);
	stack_len = ft_lstsize(stack_a);
	if (stack_len < 7)
		small_stack_sort(&stack_a, &stack_b, stack_len);
	else
		big_stack_sort(&stack_a, &stack_b, stack_len);
	optimize_and_print();
	cleanup_stacks(&stack_a, &stack_b);
	return (0);
}