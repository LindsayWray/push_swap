/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_list.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:42:08 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:42:13 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_operations	*lstnew(char *content)
{
	t_operations	*element;

	element = (t_operations *)malloc(sizeof(t_operations));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

static t_operations	*lstlast(t_operations *last)
{
	if (last == NULL)
		return (NULL);
	while ((last->next) != NULL)
		last = (last->next);
	return (last);
}

static void	lstadd_back(t_operations **stack, t_operations *new)
{
	t_operations	*last;

	if (stack && *stack)
	{
		last = lstlast(*stack);
		if (last)
			last->next = new;
	}
	else if (stack)
		*stack = new;
}

t_operations	*add_operation(char *operation)
{
	static t_operations	*operations_list = NULL;
	t_operations		*newest;

	if (operation)
	{
		newest = lstnew(operation);
		lstadd_back(&operations_list, newest);
	}
	return (operations_list);
}

t_operations	*get_operation_list(void)
{
	return (add_operation(NULL));
}
