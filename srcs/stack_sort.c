/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:44:02 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:44:04 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_element **stack_a, t_element **stack_b,
	t_chunk high_chunk, t_chunk low_chunk)
{
	int	content;
	int	push_count;

	push_count = 0;
	while (push_count != (high_chunk.size + low_chunk.size))
	{
		content = (*stack_a)->content;
		if (content >= high_chunk.min && content <= high_chunk.max)
		{
			pb(stack_a, stack_b);
			push_count++;
		}
		else if (content >= low_chunk.min && content <= low_chunk.max)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			push_count++;
		}
		else
			ra(stack_a);
	}
}

static void	sort_stack(t_chunk *chunks, t_element **stack_a,
	t_element **stack_b, int amount_of_chunks)
{
	int	i;
	int	index;

	index = amount_of_chunks / 2;
	i = 0;
	while (i < index)
	{
		push_chunks_to_b(stack_a, stack_b, chunks[index + i],
			chunks[index - 1 - i]);
		i++;
	}
	i = amount_of_chunks;
	while (i > 0)
	{
		push_back_to_a(stack_a, stack_b, chunks[i - 1].size);
		i--;
	}
}

void	big_stack_sort(t_element **stack_a, t_element **stack_b, int len)
{
	int		amount_of_chunks;
	t_chunk	*chunks;

	amount_of_chunks = chunk_amount(len);
	chunks = make_chunks(*stack_a, len, amount_of_chunks);
	sort_stack(chunks, stack_a, stack_b, amount_of_chunks);
	free (chunks);
}
