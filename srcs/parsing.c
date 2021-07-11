#include "push_swap.h"

t_element	*put_int_in_stack(const char *str, t_element *stack_a)
{
	long    number;
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
            return NULL;
	}
    if (str[i] != '\0')
        return NULL;
    number = number * sign;
    return (create_stack(number, stack_a));
}