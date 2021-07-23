/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize_and_print.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:42:52 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:42:54 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations(t_operations *operations)
{
	while (operations)
	{
		ft_printf("%s\n", operations->content);
		operations = operations->next;
	}
}

void	optimize_and_print(void)
{
	t_operations	*operations;

	operations = get_operation_list();
	optimizer(operations);
	print_operations(operations);
	clear_operations(&operations);
}
