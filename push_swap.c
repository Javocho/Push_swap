/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/10 01:19:54 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int repeat_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int n;

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

	i = 0;
	j = 0;
	while (i < argc)
	{
		if (!is_num(argv[i][j]))
		{
			write(1, "error", 5);
			return (0);
		}
		if (argv[i][j] == '\0')
			i++;
		j++;
	}
	if (!repeat_checker(argc, argv))
		return (0);
	return (1);
}

void	insert_stack(int argc, char **argv, t_stack **stk)
{
	
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	if (argc < 2)
		return (-1);
	if (!ft_checker(argc, argv))
		return (-1);
	a = ft_lstnew(NULL);
	insert_stack(argc, argv, &a);
	while(a->next != NULL)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	while (a)
    {
        t_stack *temp = a->next;
        free(a);
        a = temp;
    }
	a = NULL;
	//free(b);
}
