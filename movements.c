/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:46:33 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/21 17:58:20 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk, char c)
{
	t_node	*tmp;
	t_node	*node;

	if (stk->size < 2)
		return ;
	tmp = stk->top;
	stk->top = stk->top->next;
	node = stk->top;
	while (node->next)
		node = node->next;
	node->next = tmp;
	tmp->next = NULL;
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *stk, char c)
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
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push(t_stack *stk_out, t_stack *stk_in, char c)
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
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	swap_stack(t_stack *stk, char c)
{
	t_node	*tmp;

	if (stk->size < 2)
		return ;
	tmp = stk->top->next;
	stk->top->next = tmp->next;
	tmp->next = stk->top;
	stk->top = tmp;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
