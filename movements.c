/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:46:33 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/08 21:18:02 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stk)
{
	t_stack *last;

	last = *stk;
	while (last->next)
		last = last->next;
	last->next = *stk;
	*stk = (*stk)->next;
	(*stk)->top = *stk;
	last->next->next = NULL;    
}
