/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/19 22:14:39 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_num(char c)
{
	return (c == '-' || (c >= '0' && c <= '9'));
}

static int	repeat_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc && n != ft_atoi(argv[j]))
			j++;
		if (j < argc || (n < -2147483648 || n > 2147483647)) //solo devuelve enteros atoi?? entonces no detecta eso no?
		{
			write(1, "error", 5);
			return (0);
		}
		i++;
	}
	return (1);
}

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

static void	init_stack_values(int argc, char **argv, t_stack *stk)
{
	t_node	*new_node;
	int		i;

	i = 1;
	if (!stk)
		return ;
	stk->size = argc - 1;
	new_node = malloc(sizeof(t_node) * 1);
	if (!new_node)
		return ;
	new_node->data = ft_atoi(argv[i++]);
	stk->node = new_node;
	stk->top = stk->node;
	stk->node->next = NULL;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_node) * 1);
		if (!new_node)
		{
			free_stack(stk);
			return ;
		}
		new_node->data = ft_atoi(argv[i]);
		stk->node->next = new_node;
		stk->node = stk->node->next;
		stk->node->next = NULL;
		i++;
	}
}

static void	init_stack(t_stack *stk)
{
	stk->size = 0;
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (-1);
	if (!ft_checker(argc, argv))
		return (-1);
	init_stack_values(argc, argv, &a);
	init_stack(&b);
	final_sorting(&a, &b);
	a.node = a.top;
	print_node(a);
	free_stack(&a);
	free_stack(&b);
}
