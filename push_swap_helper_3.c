#include "pushSwap.h"

static bool	is_in_range(t_node *node, int low, int high)
{
	if (!node)
		return (false);
	return (node->index <= high && node->index >= low);
}

static int	min_rotations_for_closest(t_stack *stack, int low, int high)
{
	t_node		*top;
	t_node		*bottom;
	int			minimum_rot;

	top = stack->top;
	bottom = stack->bottom;
	if (is_in_range(top, low, high))
		return (0);
	top = top->next;
	minimum_rot = 1;
	while (!is_in_range(top, low, high) && !is_in_range(bottom, low, high))
	{
		top = top ->next;
		bottom = bottom->prev;
		minimum_rot++;
	}
	if (is_in_range(top, low, high))
		return (minimum_rot);
	return (-minimum_rot);
}

static void	push_chunk(t_stack *from, t_stack *to, int low, int high)
{
	int		size;
	int		minimum_rot;

	size = high - low + 1;
	while (size-- > 0 && from->size > 0)
	{
		minimum_rot = min_rotations_for_closest(from, low, high);
		if (minimum_rot < 0)
		{
			execute_reverse_rotate(from, &minimum_rot);
		}
		else if (minimum_rot > 0)
			execute_rotate(from, &minimum_rot);
		push_from(from, to);
		write(1, "pb\n", 3);
	}
}

void	push_all_chunks(t_stack *from, t_stack *to)
{
	int		low;
	int		chunk_size;

	if (from->size <= 100)
		chunk_size = 36;
	else if (from->size <= 500)
		chunk_size = 60;
	else
		chunk_size = 80;
	low = 0;
	while (from->size)
	{
		push_chunk(from, to, low, low + chunk_size - 1);
		low += chunk_size;
	}
}

int	min_index(t_stack *stack)
{
	int		ind;
	t_node	*node;

	if (stack->size == 0)
		return (-1);
	node = stack->top;
	ind = node->index;
	while (node)
	{
		if (node->index < ind)
			ind = node->index;
		node = node->next;
	}
	return (ind);
}
