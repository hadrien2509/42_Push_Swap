/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:48:13 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/05 19:13:06 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_tab_to_lst(int *tab, t_stack **stack_a, int i, int split)
{
	int			j;
	t_stack		*new;
	int			len;

	j = 0;
	while (j < split)
	{
		new = ft_lstnew(tab[j]);
		if (!new)
		{
			ft_lstclear(stack_a);
			return (-1);
		}
		ft_lstadd_back(stack_a, new);
		j++;
	}
	free(tab);
	return (0);
}

int	ft_parse_argument(char **av, int i, t_stack **stack_a)
{
	int			*tab;
	int			split;

	split = ft_split(av[i], ' ', &tab);
	if (!tab)
		return (-1);
	if (split == 0)
	{
		free(tab);
		return (-1);
	}
	if (ft_put_tab_to_lst(tab, stack_a, i, split) == -1)
		return (-1);
	return (0);
}

int	ft_check_lst(t_stack *stack, int size)
{
	int			i;
	int			j;
	t_stack		*save;

	j = 0;
	while (stack->next)
	{
		i = j;
		save = stack;
		while (i < size - 1)
		{
			stack = stack->next;
			if (stack->number == save->number)
				return (-1);
			i++;
		}
		stack = save;
		stack = stack->next;
		j++;
	}
	return (0);
}

int	ft_lstsize(t_stack *stack)
{
	int		count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	ft_parse(int ac, char **av, t_stack **stack_a)
{
	int			i;
	int			size;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (ft_parse_argument(av, i, stack_a) == -1)
			return (-1);
		i++;
	}
	size = ft_lstsize(*stack_a);
	if (size == 0)
		return (0);
	if (ft_check_lst(*stack_a, size) == -1)
		return (-1);
	return (size);
}
