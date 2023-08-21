/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:52:03 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/21 17:53:54 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stk)
{
	t_node	*node;

	node = stk->top;
	if (node->final_index == 0 && node->next->final_index == 2)
	{
		reverse_rotate(stk, 'a');
		swap_stack(stk, 'a');
	}
	else if (node->final_index == 1 && node->data < node->next->next->data)
		swap_stack(stk, 'a');
	else if (node->final_index == 1)
		reverse_rotate(stk, 'a');
	else if (node->final_index == 2)
	{
		if (node->next->data < node->next->next->data)
			rotate(stk, 'a');
		else
		{
			rotate(stk, 'a');
			swap_stack(stk, 'a');
		}
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->top;
	while (node->final_index != 0)
		node = node->next;
	while (node != a->top)
		rotate(a, 'a');
	push(a, b, 'b');
	sort_three(a);
	push(b, a, 'a');
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = a->top;
	while (node->final_index != 0)
		node = node->next;
	while (node != a->top)
		rotate(a, 'a');
	push(a, b, 'b');
	node = a->top;
	while (node->final_index != 1)
		node = node->next;
	while (node != a->top)
		rotate(a, 'a');
	push(a, b, 'b');
	final_index(a);
	sort_three(a);
	push(b, a, 'a');
	push(b, a, 'a');
}

// Case		actions
// 1 2 3		=> no action Y
// 1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 => 2 actions Y

// 2 1 3		-> sa  -> 1 2 3 => 1 action Y
// 3 1 2		-> ra  -> 1 2 3 => 1 action N

// 2 3 1		-> rra -> 1 2 3 => 1 action Y
// 3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 => 2 actions Y
