/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 04:06:15 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/21 14:24:18 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_num(char c)
{
	return (c == '-' || (c >= '0' && c <= '9'));
}

long long	ft_atoll(char *str)
{
	long long	neg;
	long long	res;

	neg = 1;
	res = 0;
	if (!str || !*str)
		return (0);
	while (*str && ft_strchr("\t \n", *str))
		str++;
	if (*str && *str == '-')
		neg = -1;
	if (*str && ft_strchr("+-", *str))
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	return (res * neg);
}

int	repeat_checker(int argc, char **argv)
{
	int			i;
	int			j;
	long long	l;

	i = 1;
	while (i < argc)
	{
		l = ft_atoll(argv[i]);
		j = i + 1;
		while (j < argc && l != ft_atoll(argv[j]))
			j++;
		if (j < argc || (l < -2147483648 || l > 2147483647))
		{
			write(1, "error", 5);
			return (0);
		}
		i++;
	}
	return (1);
}

void	final_index(t_stack *stk)
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

int	already_sorted(const t_stack *stk)
{
	t_node	*node;

	node = stk->top;
	while (node->next)
	{
		if (node->data < node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}
