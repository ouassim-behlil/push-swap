/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:34:20 by obehlil           #+#    #+#             */
/*   Updated: 2026/01/08 13:34:21 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

void	sort_three(t_stack *stack)
{
	int		x;
	int		y;
	int		z;

	x = stack->top->index;
	y = stack->top->next->index;
	z = stack->top->next->next->index;
	if (x > y && y < z && x < z)
		swap_and_write(stack);
	else if (x > y && y > z)
	{
		swap_and_write(stack);
		reverse_rotate_and_write(stack);
	}
	else if (x > y && y < z && x > z)
		rotate_and_write(stack);
	else if (x < y && y > z && x < z)
	{
		swap_and_write(stack);
		rotate_and_write(stack);
	}
	else if (x < y && y > z && x > z)
		reverse_rotate_and_write(stack);
}

void	sort_four(t_stack *a)
{
	int			pos;
	t_stack		*b;

	b = create_empty_stack();
	if (!b)
		return ;
	pos = min_rotations_to_top(a, 0);
	while (pos > 0)
	{
		rotate(a);
		write(1, "ra\n", 3);
		pos--;
	}
	while (pos < 0)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
		pos++;
	}
	push_from(a, b);
	write(1, "pb\n", 3);
	sort_three(a);
	push_from(b, a);
	write(1, "pa\n", 3);
	free_stack(b);
}

void	move_min_to_top(t_stack *stack)
{
	int	pos;

	pos = min_rotations_to_top(stack, min_index(stack));
	while (pos > 0)
	{
		rotate(stack);
		write(1, "ra\n", 3);
		pos--;
	}
	while (pos < 0)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
		pos++;
	}
}

void	sort_five(t_stack *a)
{
	t_stack		*b;

	b = create_empty_stack();
	if (!b)
		return ;
	move_min_to_top(a);
	push_from(a, b);
	write(1, "pb\n", 3);
	move_min_to_top(a);
	push_from(a, b);
	write(1, "pb\n", 3);
	sort_three(a);
	if (b->top->index < b->top->next->index)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	push_from(b, a);
	write(1, "pa\n", 3);
	push_from(b, a);
	write(1, "pa\n", 3);
	free_stack(b);
}
