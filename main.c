/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:34:35 by obehlil           #+#    #+#             */
/*   Updated: 2026/01/08 13:34:35 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static bool	is_already_sorted(t_stack *stack)
{
	t_node		*node;

	if (stack->size < 2)
		return (true);
	node = stack->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = create_fill_stack(argc, argv);
	if (!stack)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (is_already_sorted(stack))
		return (free_stack(stack), 0);
	if (stack->size == 0)
		return (free_stack(stack), 0);
	if (!stack_indexing(stack))
	{
		free_stack(stack);
		write(1, "Error\n", 6);
		return (1);
	}
	solve(stack);
	free_stack(stack);
	return (0);
}
