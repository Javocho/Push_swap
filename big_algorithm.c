/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:17:10 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/17 22:04:24 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int best_rotate(t_stack *stk, t_node *act)
{
	t_node 	*node;
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

void    insertion_to_chunks(t_stack *a, t_stack *b, int chunks)
{
    int i;
    int maxindex;
	int asize;
	int moveds;
    t_node  *node;

    i = 1;
    node = a->top;
    final_index(a);
	asize = a->size;
    while (i <= chunks)
    {
		//printf("moving chunk %d\n", i);
		moveds = 0;
		while (node->next)
		{
			maxindex = (asize / chunks) * i;
			//printf("max index id %d, node index is %d\n", maxindex, node->final_index);
			if (node->final_index < maxindex)
			{
				while (node != a->top)
				{
					rotate(a);
					write(1, "ra\n", 3);
				}
				push(a, b);
				write(1, "pb\n", 3);
				moveds++;
				if (b->top->final_index > (a->size / chunks) * (i - 1) + (a->size / chunks) / 2)
					rotate(b);
				node = a->top;
				if(moveds == asize)
					break;
			}
			else{
				//printf("we rotate\n");
				node = node->next;
			}
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

void	final_sorting(t_stack *a, t_stack *b)
{
	int		i;
	t_node	*node;
	int		best_mov;

	insertion_to_chunks(a, b, 2);
	i = b->size - 1;
	while (b->size >= 1)
	{
		node = b->top;
		while (node->final_index != i)
			node = node->next;
		best_mov = best_rotate(b, node);
		while (node != b->top)
		{
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
		i--;
	}
}

t_node *go_last(t_stack *stk)
{
    t_node *node;

    node = stk->top;
    while(node->next)
        node = node->next;
    return (node);
}

// void    quick_sort(t_stack *a, t_stack *b)
// {
//     t_node *begin;
//     t_node *end;

//     end = go_last(a);
//     begin = a->top;
// }