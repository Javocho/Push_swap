/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:46:33 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/15 10:11:21 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk)
{
	t_node	*tmp;
	t_node	*node;

	if (stk->size < 2)
		return ;
	tmp = stk->top;
	stk->top = stk->top->next;
	node = stk->top;
	while(node->next)
		node = node->next;
	node->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack *stk)
{
	t_node	*node;
	t_node	*tmp;

	if (stk->size < 2)
		return ;
	node = stk->top;
	while (node->next->next)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	tmp->next = stk->top;
	stk->top = tmp;
}

void	push(t_stack *stk_out, t_stack *stk_in)
{
	t_node	*node;

	if (stk_out->size < 1)
		return ;
	node = stk_out->top;
	stk_out->top = stk_out->top->next;
	stk_out->size--;
	node->next = stk_in->top;
	stk_in->top = node;
	stk_in->size++;
}

void	swap_stack(t_stack *stk)
{
	t_node	*tmp;

	if (stk->size < 2)
		return ;
	tmp = stk->top->next;
	stk->top->next = tmp->next;
	tmp->next = stk->top;
	stk->top = tmp;
}

//CARGARME ÍNDICES Y CALCULAR ÍNDICE FINAL AL PRINCIPIO