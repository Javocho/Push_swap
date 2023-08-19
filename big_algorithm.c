/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:17:10 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/19 22:01:13 by fcosta-f         ###   ########.fr       */
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

static void    insertion_to_chunks(t_stack *a, t_stack *b, int chunks)
{
	int		i;
	int		maxindex;
	int		asize;
	t_node	*node;

	i = 1;
	node = a->top;
	final_index(a);
	asize = a->size;
	while (i <= chunks)
	{
		while (node->next)
		{
			maxindex = (asize / chunks) * i;
			if (node->final_index < maxindex)
			{
				while (node != a->top)
				{
					rotate(a);
					write(1, "ra\n", 3);
				}
				push(a, b);
				write(1, "pb\n", 3);
				if (b->top->final_index > (a->size / chunks) * (i - 1) + (a->size / chunks) / 2)
					rotate(b);
				node = a->top;
			}
			else
				node = node->next;
		}
		node = a->top;
		i++;
	}
	while (a->size)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
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

void	final_sorting(t_stack *a, t_stack *b)
{
	int		i;
	t_node	*node;
	int		best_mov;

	insertion_to_chunks(a, b, 4);
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
				push(b, a);
				write(1, "pa\n", 3);
			}
			if (best_mov == 1)
			{
				rotate(b);
				write(1, "rb\n", 3);
			}
			else
			{
				reverse_rotate(b);
				write(1, "rrb\n", 4);
			}
		}
		push(b, a);
		write(1, "pa\n", 3);
		if (a->size >= 2 && a->top->next->final_index < a->top->final_index)
		{
			swap_stack(a);
			write(1, "sa\n", 3);
		}
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
