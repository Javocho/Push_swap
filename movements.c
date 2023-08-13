/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:46:33 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/13 13:49:38 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk)
{
	t_node	*tmp;

	tmp = stk->top;
	stk->top = stk->top->next;
	stk->top->index--;
	stk->node = stk->top->next;
	stk->node->index--;
	while (stk->node->next != NULL)
	{
		stk->node = stk->node->next;
		stk->node->index--;
	}
	tmp->index = stk->size - 1;
	stk->node->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_stack *stk)
{
	// t_node	*node;
	// t_node	*tmp;

	// stk->top->next = stk->top;
	// stk->top->index = 0;
	// node = stk->top;
	// while (node->next != NULL)
	// {
	// 	// printf("node: %p", node);
	// 	// printf("next %p\n", node->next);
	// 	node = node->next;
	// 	stk->node->index++;
	// }
	// tmp = node;
	// tmp->next = stk->top;
	// node = NULL;
	// stk->top = tmp;
	//FIXEAR ENLAZADO AL PRINCIPIO SE ENLAZA CONSIGO MISMO, TENGO QUE JUGAR CON PENÚLTIMO ÚLTIMO
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
	node = stk_out->top;
	while (node->next)
	{
		node->index--;
		node = node->next;
	}
	stk_in->top->index = 0;
	node = stk_in->top;
	while (node->next)
	{
		node = node->next;
		node->index++;
	}
}

void	swap_stack(t_stack *stk)
{
	t_node	*tmp;

	tmp = stk->top->next;
	stk->top->next = tmp->next;
	tmp->next = stk->top;
	stk->top = tmp;
	stk->top->index = 0;
	stk->top->next->index = 1;
}
