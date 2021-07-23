/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_chunks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:41:57 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:42:02 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	storage;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				storage = array[j];
				array[j] = array[j + 1];
				array[j + 1] = storage;
			}
			j++;
		}
		i++;
	}
}

static int	calculate_chunk_size(int len, int amount_of_chunks)
{
	return ((len / amount_of_chunks));
}

static t_chunk	*divide_in_chunks(int *array, int len, int amount_of_chunks)
{
	t_chunk	*chunks;
	int		i;
	int		chunk_size;

	chunk_size = calculate_chunk_size(len, amount_of_chunks);
	chunks = malloc(amount_of_chunks * sizeof(t_chunk));
	if (chunks == NULL)
		return (NULL);
	i = 0;
	while (i < amount_of_chunks)
	{
		chunks[i].min = array[chunk_size * i];
		if (i == (amount_of_chunks - 1))
		{
			chunks[i].max = array[len - 1];
			chunks[i].size = len - (chunk_size * i);
		}
		else
		{
			chunks[i].max = array[(chunk_size - 1) + (chunk_size * i)];
			chunks[i].size = chunk_size;
		}
		i++;
	}
	return (chunks);
}

int	chunk_amount(int len)
{
	if (len > 6 && len <= 100)
		return (10);
	if (len > 100 && len <= 200)
		return (12);
	if (len > 200 && len <= 400)
		return (16);
	if (len > 400)
		return (20);
	return (0);
}

t_chunk	*make_chunks(t_element *stack, int len, int amount_of_chunks)
{
	int		*array;
	int		i;
	t_chunk	*chunks;

	array = malloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		array[i] = stack->content;
		stack = stack->next;
		i++;
	}
	sort_array(array, len);
	chunks = divide_in_chunks(array, len, amount_of_chunks);
	free (array);
	return (chunks);
}
