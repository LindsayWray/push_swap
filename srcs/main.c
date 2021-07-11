#include "push_swap.h"

int main(int argc, char *argv[])
{
    int i;
    t_element *stack_a;
    t_element *stack_b;
    stack_a = NULL;
	stack_b = NULL;

    i = 1;
    while(i < argc)
    {
        stack_a = put_int_in_stack(argv[i], stack_a);
        if (stack_a == NULL)
        {
            ft_printf("Error\n");
            return (0);
        }
        i++;
    }
	if (ascending_order(stack_a))
	{
		print_stack(stack_a);
		clear_stack(&stack_a);
		return (0);
	}

	int total_len = ft_lstsize(stack_a);

	int amount_of_chunks = chunk_amount(total_len);
	t_chunk *chunks = fill_array(stack_a, total_len, amount_of_chunks);
	(void)chunks;
	sort_stack(chunks, &stack_a, &stack_b, amount_of_chunks);

	//print_both_stack(stack_a, stack_b);

	t_operations *operations = get_operation_list();
	optimise(operations);

	while (operations)
	{
		ft_printf(operations->content);
		operations = operations->next;
	}
	clear_stack(&stack_a);
	clear_stack(&stack_b);
    return (0);
}