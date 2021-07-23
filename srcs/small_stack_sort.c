/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stack_sort.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:43:52 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:43:54 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_element **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && first > third && third > second)
		return (ra(stack_a));
	if (second > first && second > third && first > third)
		return (rra(stack_a));
	if (ascending_order(*stack_a))
		return ;
	sa(stack_a);
	return (sort_three(stack_a));
}

void	get_biggest_three(t_element *stack, int *biggest_three)
{
	int	i;
	int	len;
	int	*array;

	len = ft_lstsize(stack);
	array = malloc(len * sizeof (int));
	if (!array)
		malloc_error(&stack);
	i = 0;
	while (i < len)
	{
		array[i] = stack->content;
		stack = stack->next;
		i++;
	}
	sort_array(array, len);
	i = 0;
	while (i < 3)
	{
		biggest_three[i] = array[len - 1 - i];
		i++;
	}
	free (array);
}

void	small_sort(t_element **stack_a, t_element **stack_b)
{
	int	array[3];
	int	content;

	get_biggest_three(*stack_a, array);
	while (ft_lstsize(*stack_a) > 3)
	{
		content = (*stack_a)->content;
		if (content == array[0] || content == array[1] || content == array[2])
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	if (ft_lstsize(*stack_b) == 2 && ascending_order(*stack_b))
		sb(stack_b);
	sort_three (stack_a);
	push_back_to_a (stack_a, stack_b, ft_lstsize(*stack_b));
}

void	small_stack_sort(t_element **stack_a, t_element **stack_b, int len)
{
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else
		small_sort(stack_a, stack_b);
}
