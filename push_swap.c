/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/21 12:17:11 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (!ft_is_num(argv[i][j]))
			{
				write(1, "error", 5);
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (!repeat_checker(argc, argv))
		return (0);
	return (1);
}

static void	init_stack(int argc, char **argv, t_stack *stk_a, t_stack *stk_b)
{
	t_node	*new_node;
	int		i;

	i = 1;
	stk_a->size = argc - 1;
	new_node = malloc(sizeof(t_node) * 1);
	if (!new_node)
		return ;
	new_node->data = ft_atoi(argv[i++]);
	stk_a->node = new_node;
	stk_a->top = stk_a->node;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_node) * 1);
		if (!new_node)
		{
			free_stack(stk_a);
			return ;
		}
		new_node->data = ft_atoi(argv[i++]);
		stk_a->node->next = new_node;
		stk_a->node = stk_a->node->next;
	}
	stk_a->node->next = NULL;
	stk_b->size = 0;
}

void	free_stack(t_stack *stk)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	i = 0;
	node = stk->top;
	while (i++ < stk->size)
	{
		tmp = node->next;
		free(node);
		node = NULL;
		node = tmp;
	}
}

void	select_function(int argc, t_stack *a, t_stack *b)
{
	argc--;
	if (argc == 3)
		sort_three(a);
	else if (argc == 4)
		sort_four(a, b);
	else if (argc == 5)
		sort_five(a, b);
	else if (argc < 500)
		final_sorting(a, b, 4);
	else
		final_sorting(a, b, 8);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (-1);
	if (!ft_checker(argc, argv))
		return (-1);
	init_stack(argc, argv, &a, &b);
	if (already_sorted(&a) == 1)
		return (0);
	select_function(argc, &a, &b);
	a.node = a.top;
	//print_node(a);
	free_stack(&a);
	free_stack(&b);
}
