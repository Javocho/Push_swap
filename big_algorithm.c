/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:17:10 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/21 12:10:41 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_rotate(t_stack *stk, t_node *act)
{
	t_node	*node;
	int		count_r;
	int		count_rr;

	count_r = 0;
	node = stk->top;
	while (node->next && node != act)
	{
		count_r++;
		node = node->next;
	}
	count_rr = 0;
	while (node->next)
	{
		count_rr++;
		node = node->next;
	}
	if (count_r > count_rr)
		return (0);
	else
		return (1);
}

static void	insertion_to_chunks(t_stack *a, t_stack *b, int chunks)
{
	int		i;
	int		maxindex;
	int		size_chunk;
	t_node	*node;

	i = 1;
	node = a->top;
	final_index(a);
	size_chunk = a->size / chunks;
	while (i <= chunks)
	{
		while (node->next)
		{
			maxindex = size_chunk * i;
			if (node->final_index < maxindex)
			{
				while (node != a->top)
					rotate(a, 'a');
				push(a, b, 'b');
				if (b->top->final_index > size_chunk * (i - 1) + size_chunk / 2)
					rotate(b, 'b');
				node = a->top;
			}
			else
				node = node->next;
		}
		node = a->top;
		i++;
	}
	while (a->size)
		push(a, b, 'b');
}


void	final_sorting(t_stack *a, t_stack *b, int nchunks)
{
	int		i;
	t_node	*node;
	int		best_mov;

	insertion_to_chunks(a, b, nchunks);
	i = b->size - 1;
	while (b->size >= 1)
	{
		node = b->top;
		while (node->next && node->final_index != i)
			node = node->next;
		best_mov = best_rotate(b, node);
		while (node != b->top)
		{
			if (b->size >= 2 && b->top->final_index == node->final_index - 1)
			{
				push(b, a, 'a');
				i--;
			}
			if (best_mov == 1)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
		push(b, a, 'a');
		if (a->size >= 2 && a->top->final_index < a->top->next->final_index)
			swap_stack(a, 'a');
		i--;
	}
}

t_node	*go_last(t_stack *stk)
{
	t_node	*node;

	node = stk->top;
	while (node->next)
		node = node->next;
	return (node);
}

void	print_node(t_stack stk)
{
	t_node	*node;

	node = stk.top;
	while (node)
	{
		printf("el contenido %d, el índice final %d, el puntero al nodo %p, el puntero siguiente %p\n", node->data, node->final_index, node, node->next);
		node = node->next;
	}
}