/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:34:41 by obehlil           #+#    #+#             */
/*   Updated: 2026/01/08 13:34:42 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

int	max_index(t_stack *stack)
{
	int		ind;
	t_node	*node;

	if (stack->size == 0)
		return (-1);
	node = stack->top;
	ind = node->index;
	while (node)
	{
		if (node->index > ind)
			ind = node->index;
		node = node->next;
	}
	return (ind);
}

int	min_rotations_to_top(t_stack *stack, int index)
{
	t_node		*top;
	t_node		*bottom;
	int			minimum_rot;

	if (!stack || stack->size == 0)
		return (0);
	top = stack->top;
	bottom = stack->bottom;
	if (top->index == index)
		return (0);
	top = top->next;
	minimum_rot = 1;
	while (top && bottom && top->index != index && bottom->index != index)
	{
		top = top->next;
		bottom = bottom->prev;
		minimum_rot++;
	}
	if (top && top->index == index)
		return (minimum_rot);
	if (bottom && bottom->index == index)
		return (-minimum_rot);
	return (0);
}

int	find_lower_bound(t_stack *stack, int index)
{
	t_node		*top;
	t_node		*bottom;

	top = stack->top;
	bottom = stack->bottom;
	while (top && bottom)
	{
		if (top->next && top->index < index && top->next->index > index)
			return (top->next->index);
		if (bottom->prev && bottom->prev->index < index
			&& bottom->index > index)
			return (bottom->index);
		top = top->next;
		bottom = bottom->prev;
	}
	return (-1);
}
