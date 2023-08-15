/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:33:54 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/15 10:15:23 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	int				data;
	int				final_index;
	int				sorted;
}	t_node;

typedef struct s_stack
{
	struct s_node	*node;
	struct s_node	*top;
	int				size;
}	t_stack;

void	rotate(t_stack *stk);
void	reverse_rotate(t_stack *stk);
void	push(t_stack *stk_out, t_stack *stk_in);
void	swap_stack(t_stack *stk);
void	final_index(const t_stack *stk);
void	sort_three(t_stack *stk);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);

#endif