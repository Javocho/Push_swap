/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:17:10 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/15 18:34:32 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int rotate_cost(t_stack a, const t_node *top)
// {
//     int cost;

//     cost = 0;
//     while (a.top != top)
//     {
//         ++cost;
//         rotate(&a);
//     }
//     return (cost);
// }

// int revrotate_cost(t_stack a, const t_node *top)
// {
//     int cost;

//     cost = 0;
//     while (a.top != top)
//     {
//         ++cost;
//         reverse_rotate(&a);
//     }
//     return (cost);
// }

// void    insertion(t_stack *a, t_stack *b)
// {
//     int i;
//     int size_a;
//     t_node  *node;

//     i = 0;
//     node = a->top;
//     size_a = a->size;
//     final_index(a);
//     while (a->size >= 1)
//     {
//         if (node->final_index == i)
//         {
//             while (node != a->top)
//             {
//                 if (rotate_cost(*a, a->top) < revrotate_cost(*a, a->top))
//                 {    
//                     rotate(a);
//                     write(1, "ra\n", 3);
//                 }
//                 else
//                 {
//                     reverse_rotate(a);
//                     write(1, "rra\n", 4);
//                 }
//             }
//             push(a, b);
//             write(1, "pb\n", 3);
//             node = a->top;
//             i++;
//         }
//         else
//             node = node->next;
//     }
//     while (b->size > 0)
//     {
//         push(b, a);
//         write(1, "pa\n", 3);
//     }
// }

t_node *go_last(t_stack *stk)
{
    t_node *node;

    node = stk->top;
    while(node->next)
        node = node->next;
    return (node);
}

void    quick_sort(t_stack *a, t_stack *b)
{
    t_node *begin;
    t_node *end;

    end = go_last(a);
    begin = a->top;
}