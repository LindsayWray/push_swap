#include "push_swap.h"

int		get_highest_value(t_element *stack_b, int chunk_size)
{
	int i;
	int highest_value;

	i = 0;
	if (stack_b)
		highest_value = stack_b->content;
	while(i < chunk_size)
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

void	push_back_to_a(t_element **stack_a, t_element **stack_b, int chunk_size)
{
	int highest_value;
	int reverse_counter;

	reverse_counter = 0;
	while(chunk_size > 0)
	{
		highest_value = get_highest_value((*stack_b), chunk_size);
		while ((*stack_b)->content != highest_value)
		{
			rb(stack_b);
			reverse_counter++;
		}
		pa(stack_b, stack_a);
		while(reverse_counter > 0)
		{
			rrb(stack_b);
			reverse_counter--;
		}
		chunk_size--;
	}
}

void	push_chunks_to_b(t_element **stack_a, t_element **stack_b, t_chunk high_chunk, t_chunk low_chunk)
{
	int content;
	int len_stack_a;
	int push_count;

	push_count = 0;
	len_stack_a = ft_lstsize(*stack_a);
	while (len_stack_a > 0)
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
		else if (push_count != (high_chunk.size + low_chunk.size))
			ra(stack_a);
		else
			return;			
		len_stack_a--;
	}
}

void	sort_stack(t_chunk *chunks, t_element **stack_a, t_element **stack_b, int amount_of_chunks)
{
	int i;
	int index;

	index = amount_of_chunks / 2;
	i = 0;
	while(i < index)
	{
		push_chunks_to_b(stack_a, stack_b, chunks[index + i], chunks[index - 1 - i]);
		i++;
	}
	i = amount_of_chunks;
	while(i > 0)
	{
		push_back_to_a(stack_a, stack_b, chunks[i - 1].size);
		i--;
	}
}