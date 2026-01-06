#include "pushSwap.h"

void	swap_and_write(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	rotate_and_write(t_stack *stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	reverse_rotate_and_write(t_stack *stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	execute_reverse_rotate(t_stack *from, int *minimum_rot)
{
	while ((*minimum_rot)++ < 0)
	{
		reverse_rotate(from);
		write(1, "rra\n", 4);
	}
}

void	execute_rotate(t_stack *from, int *minimum_rot)
{
	while ((*minimum_rot)-- > 0)
	{
		rotate(from);
		write(1, "ra\n", 3);
	}
}
