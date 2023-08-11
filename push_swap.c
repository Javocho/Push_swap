/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/11 13:45:30 by fcosta-f         ###   ########.fr       */
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

	i = 0;
	j = 0;
	while (i < argc)
	{
		n = ft_atoi2(argv[i]);
		while (j < i && n != ft_atoi2(argv[j]))
			j++;
		if (i < j)
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

void	insert_stack(int argc, char **argv, t_stack **stk, t_info *info)
{
	t_stack	*new_node;
	int		i;

	i = 1;
	*stk = NULL;
	info->size_a = argc - 1;
	while (i < argc)
	{
		new_node = malloc(sizeof(t_stack *) * 1);
		if (!new_node)
			return ;
		new_node->content = ft_atoi2(argv[i]);
		new_node->index = i - 1;
		// if ((*stk) == NULL)
		// {
		// 	(*info).top = new_node;
		// }
		
		(*stk) = new_node;
		(*stk)->next = NULL;
		(*stk) = (*stk)->next;
		i++;
	}
}

void	free_stack(t_stack **stk, t_info info)
{
	t_stack *node;
	t_stack *tmp;
	int		i;

	i = 0;
	node = *stk;
	while (i < info.size_a)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;
	t_info	info;

	if (argc < 2)
		return (-1);
	if (!ft_checker(argc, argv))
		return (-1);
	insert_stack(argc, argv, &a, &info);
	while(a->next != NULL)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	free_stack(&a, info);
	a = NULL;
}
