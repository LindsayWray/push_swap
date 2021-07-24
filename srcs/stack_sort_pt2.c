/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort_pt2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:44:02 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:44:04 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_second_high_value(t_element *stack_b, int chunk_size,
	int highest_val)
{
	int	i;
	int	second_high;

	i = 0;
	if (stack_b)
		second_high = stack_b->content;
	while (i < chunk_size)
	{
		stack_b = stack_b->next;
		if (!stack_b)
			break ;
		if (stack_b->content > second_high && stack_b->content != highest_val)
			second_high = stack_b->content;
		i++;
	}
	return (second_high);
}

static int	get_highest_value(t_element *stack_b, int chunk_size)
{
	int	i;
	int	highest_value;

	i = 0;
	if (stack_b)
		highest_value = stack_b->content;
	while (i < chunk_size)
	{
		stack_b = stack_b->next;
		if (!stack_b)
			break ;
		if (stack_b->content > highest_value)
			highest_value = stack_b->content;
		i++;
	}
	return (highest_value);
}

void	activate_reverse_counter(int reverse_counter, t_element **stack_b)
{
	while (reverse_counter)
	{
		rrb(stack_b);
		reverse_counter--;
	}
}

void	find_second_highest_value(t_element **stack_a, t_element **stack_b,
		int *chunk_size)
{
	int	highest_value;
	int	second_high;
	int	reverse_counter;

	reverse_counter = 0;
	highest_value = get_highest_value((*stack_b), *chunk_size);
	second_high = get_second_high_value(*stack_b, *chunk_size, highest_value);
	while ((*stack_b)->content != highest_value)
	{
		if ((*stack_b)->content == second_high)
		{
			pa(stack_b, stack_a);
			(*chunk_size)--;
		}
		else
		{
			rb(stack_b);
			reverse_counter++;
		}
	}
	pa(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 1 && (*stack_a)->next->content == second_high)
		sa(stack_a);
	activate_reverse_counter(reverse_counter, stack_b);
}

void	push_back_to_a(t_element **stack_a, t_element **stack_b, int chunk_size)
{
	int	highest_value;
	int	reverse_counter;

	if (chunk_size == 0)
		return ;
	find_second_highest_value(stack_a, stack_b, &chunk_size);
	while (chunk_size > 1)
	{
		reverse_counter = 0;
		highest_value = get_highest_value((*stack_b), chunk_size);
		while ((*stack_b)->content != highest_value)
		{
			rb(stack_b);
			reverse_counter++;
		}
		pa(stack_b, stack_a);
		activate_reverse_counter(reverse_counter, stack_b);
		chunk_size--;
	}
}
