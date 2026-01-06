#include "pushSwap.h"

static void	common_rotations(t_stack *from, t_stack *to,
	int *inner_rot_cost, int *insert_cost)
{
	while (*insert_cost > 0 && *inner_rot_cost > 0)
	{
		rotate(from);
		rotate(to);
		write(1, "rr\n", 3);
		(*insert_cost)--;
		(*inner_rot_cost)--;
	}
	while (*insert_cost < 0 && *inner_rot_cost < 0)
	{
		reverse_rotate(from);
		reverse_rotate(to);
		write(1, "rrr\n", 4);
		(*insert_cost)++;
		(*inner_rot_cost)++;
	}
}

static void	finish_rotations_from(t_stack *stack, int *cost)
{
	while (*cost > 0)
	{
		rotate(stack);
		write(1, "rb\n", 3);
		(*cost)--;
	}
	while (*cost < 0)
	{
		reverse_rotate(stack);
		write(1, "rrb\n", 4);
		(*cost)++;
	}
}

static void	finish_rotations_to(t_stack *stack, int	*cost)
{
	while (*cost > 0)
	{
		rotate(stack);
		write(1, "ra\n", 3);
		(*cost)--;
	}
	while (*cost < 0)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
		(*cost)++;
	}
}

static void	push_best_back(t_stack *from, t_stack *to)
{
	int		insert_cost;
	int		inner_rot_cost;
	int		ind;

	ind = index_of_lowest_cost(from, to);
	inner_rot_cost = min_rotations_to_top(from, ind);
	insert_cost = insertion_cost(to, ind);
	common_rotations(from, to, &inner_rot_cost, &insert_cost);
	finish_rotations_from(from, &inner_rot_cost);
	finish_rotations_to(to, &insert_cost);
	push_from(from, to);
	write(1, "pa\n", 3);
}

void	push_swap(t_stack *stack_a)
{
	t_stack		*stack_b;
	int			final_rot;

	stack_b = create_empty_stack();
	if (!stack_b)
		return ;
	push_all_chunks(stack_a, stack_b);
	while (stack_b->size)
		push_best_back(stack_b, stack_a);
	final_rot = min_rotations_to_top(stack_a, 0);
	finish_rotations_to(stack_a, &final_rot);
}
