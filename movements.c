/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:46:33 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/12 19:37:43 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk)
{
	t_node	*tmp;

	tmp = stk->top;
	stk->top = stk->top->next;
	stk->node = stk->top->next;
	while (stk->node->next != NULL)
	{
		stk->node = stk->node->next;
	}
	stk->node->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack *stk)
{
	t_node	*node;
	t_node	*tmp;

	tmp = stk->top;
	stk->top = stk->top->next;
	node = stk->top->next;
	while (node->next != NULL)
	{
		node = node->next;
	}
	stk->node->next = tmp;
	tmp->next = NULL;
}

void	push(t_stack *stk_out, t_stack *stk_in)
{
	t_node	*node;

	node = stk_out->top;
	stk_out->top = stk_out->top->next;
	stk_out->size--;
	stk_in->top = node;
	stk_in->node = stk_in->top;
	stk_in->size++;
	stk_in->top->next = NULL;
}

void	swap_stack(t_stack *stk)
{
	t_node	*tmp;

	tmp = stk->top->next;
	stk->top->next = tmp->next;
	tmp->next = stk->top;
	stk->top = tmp;
}
