/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/13 14:43:01 by lwray         #+#    #+#                 */
/*   Updated: 2021/07/13 14:43:03 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_int_in_stack(const char *str, t_element **stack_a)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
		if (number > 2147483647 || (number * sign) < -2147483648)
			parsing_error(stack_a);
	}
	if (str[i] != '\0')
		parsing_error(stack_a);
	number = number * sign;
	return (create_stack(number, stack_a));
}
