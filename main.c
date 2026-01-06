#include "pushSwap.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_stack	*stack;
	//t_node	*node;

	stack = create_fill_stack(argc, argv);
	if (!stack)
		return (1);
	if (!stack_indexing(stack))
		return (1);
	push_swap(stack);
	/*node = stack->top;
	while (node)
	{
		printf("node: %d \t index %d\n", node->value, node->index);
		node = node->next;
	}*/
	return (0);
}
