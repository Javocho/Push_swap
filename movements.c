/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:46:33 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/12 13:30:07 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stk)
{
	t_node	*tmp;

	tmp = stk->top;
	//stk->node = stk->top;
	stk->top = stk->top->next;
	stk->node = stk->top->next;
	while (stk->node->next != NULL)
	{
		stk->node = stk->node->next;
	}
	stk->node->next = tmp;
	tmp->next = NULL;
	// while (stk->node != NULL)
	// {
	// 	printf("%d\n", stk->node->content);
	// 	stk->node = stk->node->next;
	// }
}

void	reverse_rotate(t_stack *stk)
{
	t_node	*node;
	t_node	*tmp;

	node = stk->top;
	while (node->next->next != NULL)
	{
		node->next = node;
	}
	tmp = node->next;
	node->next = node;
	stk->top = tmp;
	tmp->next = ;
}
