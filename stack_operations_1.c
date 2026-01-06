#include "pushSwap.h"

void	swap(t_stack *a)
{
	t_node		*top_node_1;
	t_node		*top_node_2;

	if (!a || a->size < 2)
		return ;
	top_node_1 = pop(a);
	top_node_2 = pop(a);
	if (!top_node_1 || !top_node_2)
		return ;
	push(a, top_node_2);
	push(a, top_node_1);
}

void	push_from(t_stack *from, t_stack *to)
{
	t_node		*node;

	if (!from || !to || !(from->size))
		return ;
	node = pop(from);
	if (node)
		push(to, node);
}

t_stack	*create_empty_stack(void)
{
	t_stack		*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node	*create_node(int val)
{
	t_node		*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->value = val;
	return (node);
}

int	*stack_to_array(t_stack *stack)
{
	int		*arr;
	int		i;
	t_node	*head;

	if (stack->size == 0)
		return (NULL);
	arr = malloc(sizeof(int) * (stack->size));
	if (!arr)
		return (NULL);
	head = stack->top;
	i = 0;
	while (head)
	{
		arr[i++] = head->value;
		head = head->next;
	}
	return (arr);
}
