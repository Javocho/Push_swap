#include "push_swap.h"

// static int	get_min(const t_stack *stk, int begin)
// {
// 	t_node	*node;
// 	int		min_index;
// 	int		min;
// 	int		i;

// 	node = stk->top;
// 	i = 0;
// 	while (i++ < begin)
// 		node = node->next;
// 	min = node->data;
// 	min_index = 0;
// 	i = 0;
// 	while (node->next)
// 	{
// 		node = node->next;
// 		if (node->data < min)
// 		{
// 			min = node->data;
// 			min_index = i;
// 		}
// 		i++;
// 	}
// 	printf("%d\n", min_index);
// 	return (min_index);
// } //función ver num más grandes = posición final??

void	final_index(const t_stack *stk)
{
	t_node	*node;
	t_node	*act;
	int		tmp_index;

	act = stk->top;
	while (act)
	{
		tmp_index = 0;
		node = stk->top;
		while (node)
		{
			if (node != act && act->data > node->data)
				tmp_index++;
			node = node->next;
		}
		act->final_index = tmp_index;
		act = act->next;
	}
}

void	sort_three(t_stack *stk)
{
	t_node	*node;

	final_index(stk);
	node = stk->top;
	if (node->final_index == 0 && node->next->final_index == 2)
	{
		reverse_rotate(stk);
		swap_stack(stk);
	}
	else if (node->final_index == 1)
	{
		if (node->data < node->next->next->data)
			swap_stack(stk);
		else
			reverse_rotate(stk);
	}
	else if (node->final_index == 2)
	{
		if (node->next->data < node->next->next->data)
			rotate(stk);
		else
		{
			rotate(stk);
			swap_stack(stk);
		}
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	t_node	*node;

	final_index(a);
	node = a->top;
	while (node->final_index != 0)
		node = node->next;
	while(node != a->top)
		rotate(a);
	push(a, b);
	sort_three(a);
	push(b, a);
}

// Case		actions
// 1 2 3		=> no action Y
// 1 3 2		-> rra -> 2 1 3 -> sa  -> 1 2 3 => 2 actions Y

// 2 1 3		-> sa  -> 1 2 3 => 1 action Y
// 3 1 2		-> ra  -> 1 2 3 => 1 action N

// 2 3 1		-> rra -> 1 2 3 => 1 action Y
// 3 2 1		-> ra  -> 2 1 3 -> sa  -> 1 2 3 => 2 actions Y
