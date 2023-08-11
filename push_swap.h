/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:33:54 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/11 13:41:40 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	// struct s_stack *top;
	int				index;
	int				sorted;
}	t_stack;

typedef struct s_info
{
	int	size_a;
	int	size_b;
	// struct s_stack *top;
}	t_info;

// typedef struct s_stack
// {
// 	t_node	*first;
// 	t_node	*last;
// 	int		size;
// }	t_stack;

#endif