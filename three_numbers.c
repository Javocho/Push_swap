#include "push_swap.h"

static int	get_min(const t_stack *stk, int begin)
{
	t_node	*node;
	int		min_index;
	int		min;
	int		i;

	node = stk->top;
	i = 0;
	while (i++ < begin)
		node = node->next;
	min = node->data;
	min_index = node->index;
	while (node->next)
	{
		node = node->next;
		if (node->data < min)
		{
			min = node->data;
			min_index = node->index;
		}
	}
	return (min_index);
}

void	sort_three(t_stack *stk)
{
	t_node	*node;
	int		min0;
	int		min1;

	min0 = get_min(stk, 0);
	min1 = get_min(stk, 1);
	node = stk->top;
	if (min0 == 0 && min1 == 2)
	{
		reverse_rotate(stk);
		swap_stack(stk);
	}
	else if (min0 == 1)
	{
		if (node->data < node->next->next->data)
			swap_stack(stk);
		else
			rotate(stk);
	}
	else if (min0 == 2)
	{
		if (node->data < node->next->data)
			reverse_rotate(stk);
		else
		{
			rotate(stk);
			swap_stack(stk);
		}
	}


}

// Case		actions
// 1 2 3		=> no action Y
// 1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 => 2 actions N

// 2 1 3		-> sa  -> 1 2 3 => 1 action Y
// 3 1 2		-> ra  -> 1 2 3 => 1 action Y

// 2 3 1		-> rra -> 1 2 3 => 1 action 
// 3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 => 2 actions
