/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:54:16 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/06 12:33:49 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_triosort(t_stack **stack_a)
{
	int		l;
	int		r;

	l = (*stack_a)->next->unumber - (*stack_a)->unumber;
	r = (*stack_a)->next->next->unumber - (*stack_a)->next->unumber;
	if (l == 1 && r == 1)
		return ;
	if (l == 1)
		ft_rrotate(stack_a);
	if (r == 1)
		ft_rotate(stack_a);
	if (l == -1 && r == 2)
		ft_swap(stack_a);
	if (l == 2 && r == -1)
	{
		ft_swap(stack_a);
		ft_rotate(stack_a);
	}
	if (l == -1 && r == -1)
	{
		ft_rotate(stack_a);
		ft_swap(stack_a);
	}
}

int	ft_find_min(t_stack *stack_a, int minimum)
{
	int		i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->unumber == minimum)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}

void	ft_rotate_min(t_stack **stack_a, int size, int minimum)
{
	int		index;

	index = ft_find_min(*stack_a, minimum);
	if (index <= (size / 2))
	{
		while (index > 0)
		{
			ft_rotate(stack_a);
			index--;
		}
		return ;
	}
	while (index < size)
	{
		ft_rrotate(stack_a);
		index++;
	}
	return ;
}

void	ft_smallsort(t_stack **stack_a, int size)
{
	t_stack	*stack_b;
	int		pushed;
	int		minimum;

	minimum = 0;
	pushed = 0;
	stack_b = 0;
	while (size > 3)
	{
		ft_rotate_min(stack_a, size, minimum);
		pushed = ft_pb(stack_a, &stack_b, pushed);
		size--;
		minimum++;
		if (ft_issorted(*stack_a))
			break ;
	}
	if (size == 3)
		ft_triosort(stack_a);
	while (pushed > 0)
		pushed = ft_pa(&stack_b, stack_a, pushed);
}

void	ft_sort(t_stack **stack_a, int size)
{
	int		minimum;
	int		bits;

	bits = ft_bitlen(size - 1);
	if (ft_issorted(*stack_a))
		return ;
	if (size == 2)
	{
		ft_swap(stack_a);
		return ;
	}
	ft_unumber(stack_a);
	if (size == 3)
	{
		ft_triosort(stack_a);
		return ;
	}
	if (size < 50)
		ft_smallsort(stack_a, size);
	else
		ft_radix(stack_a, size, bits);
	return ;
}
