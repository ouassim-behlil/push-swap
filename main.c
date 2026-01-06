#include "pushSwap.h"
#include <stdio.h>

static void	solve(t_stack *stack)
{
	if (stack->size == 2)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
	else if (stack->size == 3)
		sort_three(stack);
	else if (stack->size == 4)
		sort_four(stack);
	else if (stack->size == 5)
		sort_five(stack);
	else
		push_swap(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = create_fill_stack(argc, argv);
	if (!stack)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (stack->size == 0)
		return (0);
	if (!stack_indexing(stack))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	solve(stack);
	return (0);
}
