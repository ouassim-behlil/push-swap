/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehlil <obehlil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:35:01 by obehlil           #+#    #+#             */
/*   Updated: 2026/01/08 13:35:04 by obehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

void	rotate(t_stack *stack)
{
	t_node		*node;

	if (!stack || stack->size < 2 || !stack->top)
		return ;
	node = pop(stack);
	if (!node)
		return ;
	node->prev = stack->bottom;
	node->next = NULL;
	stack->bottom->next = node;
	stack->bottom = node;
	stack->size++;
}

void	reverse_rotate(t_stack *stack)
{
	t_node		*node;

	if (!stack || stack->size < 2 || !stack->bottom)
		return ;
	node = stack->bottom;
	if (!node->prev)
		return ;
	stack->bottom = node->prev;
	node->prev = NULL;
	stack->bottom->next = NULL;
	node->next = stack->top;
	stack->top->prev = node;
	stack->top = node;
}
