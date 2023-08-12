/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:33:54 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/12 13:02:34 by fcosta-f         ###   ########.fr       */
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
	int				content;
	int				index;
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

#endif