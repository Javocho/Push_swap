/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:34:46 by fcosta-f          #+#    #+#             */
/*   Updated: 2023/08/09 20:45:29 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
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
	return (1);
}

void	insert_stack(int argc, char **argv, t_stack **stk)
{
	int		i;
	t_stack	*seg;

	i = 1;
	while (i < argc)
	{
		seg = ft_lstnew(NULL);
		if (!seg)
			return ;
		seg->content = atoi(argv[i]);
		ft_lstadd_front(stk, seg);
		(*stk) = (*stk)->top;
		i++;
	}
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
