/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_stack_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:34:06 by obehlil           #+#    #+#             */
/*   Updated: 2026/01/08 13:34:08 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

bool	is_empty(t_stack *stack)
{
	if (!stack)
		return (true);
	return (stack->size == 0);
}

void	push(t_stack *stack, t_node *node)
{
	t_node		*current_top;

	if (!stack || !node)
		return ;
	node->prev = NULL;
	node->next = NULL;
	if (is_empty(stack))
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		current_top = stack->top;
		current_top->prev = node;
		node->next = current_top;
		stack->top = node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node		*node;

	if (!stack || is_empty(stack))
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*peek(t_stack *stack)
{
	if (!stack || is_empty(stack))
		return (NULL);
	return (stack->top);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
	}
	free(stack);
}
