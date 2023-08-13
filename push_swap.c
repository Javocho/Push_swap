/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/13 13:34:06 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi2(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	repeat_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi2(argv[i]);
		j = i + 1;
		while (j < argc && n != ft_atoi2(argv[j]))
			j++;
		if (j < argc)
		{
			write(1, "error", 5);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_checker(int argc, char **argv)
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
		i++;
	}
	if (!repeat_checker(argc, argv))
		return (0);
	return (1);
}

void	init_stack_values(int argc, char **argv, t_stack *stk)
{
	t_node	*new_node;
	int		i;

	i = 1;
	if (!stk)
		return ;
	stk->size = argc - 1;
	new_node = malloc(sizeof(t_node *) * 1);
	if (!new_node)
		return ;
	new_node->index = i - 1;
	new_node->data = ft_atoi2(argv[i++]);
	stk->node = new_node;
	stk->top = stk->node;
	stk->node->next = NULL;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_node *) * 1);
		if (!new_node)
			return ;
		new_node->data = ft_atoi2(argv[i]);
		new_node->index = i - 1;
		stk->node->next = new_node;
		stk->node = stk->node->next;
		stk->node->next = NULL;
		i++;
	}
}

void	init_stack(t_stack *stk)
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
	sort_three(&a);
	a.node = a.top;
	while (a.node != NULL)
	{
		printf("%d %d\n", a.node->data, a.node->index);
		a.node = a.node->next;
	}
	// while (b.node != NULL)
	// {
	// 	printf("%d %d\n", b.node->data, b.node->index);
	// 	b.node = b.node->next;
	// }
	free_stack(&a);
	free_stack(&b);
}
