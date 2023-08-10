/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/10 20:08:04 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_num(char c)
{
	return (c >= '0' && c <= '9');
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
		n = ft_atoi(argv[i]);
		while (j < i && n != ft_atoi(argv[j]))
			j++;
		if (i < j)
		{
			write(1, "error", 5);
			return (0);
		}
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

void	insert_stack(int argc, char **argv, t_stack **stk)
{
	t_node	*node;
	int		i;

	i = 2;
	node = malloc(sizeof(t_node *) * 1);
	node->content = ft_atoi(argv[1]);
	node->index = 0;
	(*stk)->size = argc - 1;
	(*stk)->first = node;
	while (argc < i)
	{
		node->next = malloc(sizeof(t_node *) * 1);
		node = node->next;
		node->index = i - 1;
		(*stk)->last = node;
	}
}

void	free_stack(t_stack **stk)
{
	t_node node;

	node = (*stk)->first;
	while (node != (*skt)->)
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	if (argc < 2)
		return (-1);
	if (!ft_checker(argc, argv))
		return (-1);
	insert_stack(argc, argv, &a);
	// while(a->next != NULL)
	// {
	// 	printf("%d\n", a->content);
	// 	a = a->next;
	// }
	//free_stack(&a);
	a = NULL;
}
