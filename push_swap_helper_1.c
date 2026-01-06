#include "pushSwap.h"

int	insertion_cost(t_stack *stack, int index)
{
	int		min;
	int		max;

	if (stack->size == 0)
		return (0);
	min = min_index(stack);
	max = max_index(stack);
	if (index > max || index < min)
		return (min_rotations_to_top(stack, min));
	return (min_rotations_to_top(stack, find_lower_bound(stack, index)));
}

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

static int	total_cost(t_stack *from, t_stack *to, int index)
{
	int		insert_cost;
	int		inner_rot_cost;

	insert_cost = insertion_cost(to, index);
	inner_rot_cost = min_rotations_to_top(from, index);
	if (insert_cost * inner_rot_cost < 0)
		return (abs(insert_cost) + abs(inner_rot_cost));
	return (max(abs(insert_cost), abs(inner_rot_cost)));
}

int index_of_lowest_cost(t_stack *from, t_stack *to)
{
	t_node		*node;
	int			best_ind;
	int			best_cost;
	int			current_cost;

	node = from->top;
	best_ind = -1;
	best_cost = INT_MAX;
	while (node)
	{
		current_cost = total_cost(from, to, node->index);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_ind = node->index;
		}
		node = node->next;
	}
	return (best_ind);
}
