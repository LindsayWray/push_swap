/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:42:52 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:42:54 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_operation(char *operation, t_element **stack_a, t_element **stack_b)
{
	if (ft_strequal("pa", operation))
		push(stack_b, stack_a);
	else if (ft_strequal("pb", operation))
		push(stack_a, stack_b);
	else if (ft_strequal("sa", operation))
		swap(*stack_a);
	else if (ft_strequal("sb", operation))
		swap(*stack_b);
	else if (ft_strequal("ss", operation))
		swap_both_stacks(*stack_a, *stack_b);
	else if (ft_strequal("ra", operation))
		rotate(stack_a);
	else if (ft_strequal("rb", operation))
		rotate(stack_b);
	else if (ft_strequal("rr", operation))
		rotate_both_stacks(stack_a, stack_b, rotate);
	else if (ft_strequal("rra", operation))
		reverse_rotate(stack_a);
	else if (ft_strequal("rrb", operation))
		reverse_rotate(stack_b);
	else if (ft_strequal("rrr", operation))
		rotate_both_stacks(stack_a, stack_b, reverse_rotate);
	else
		operation_input_error(stack_a, stack_b);
}

void	read_input(t_element **stack_a, t_element **stack_b)
{
	char	*line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		get_operation(line, stack_a, stack_b);
		free (line);
	}
}

int	main(int argc, char *argv[])
{
	t_element	*stack_a;
	t_element	*stack_b;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		put_int_in_stack(argv[i], &stack_a);
		i++;
	}
	read_input(&stack_a, &stack_b);
	if (ascending_order(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup_stacks(&stack_a, &stack_b);
	return (0);
}
