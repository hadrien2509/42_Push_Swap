/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:02:59 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/02 12:57:36 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bitlen(int maximum)
{
	int		len;

	len = 1;
	while (maximum >> len)
		len++;
	return (len);
}

void	ft_radix(t_stack **stack_a, int size, int len)
{
	int			i;
	int			j;
	t_stack		*stack_b;
	int			pushed;

	j = 0;
	pushed = 0;
	while (j < len)
	{
		i = 0;
		stack_b = 0;
		while (i < size)
		{
			if (((*stack_a)->unumber >> j) % 2)
				ft_rotate(stack_a);
			else
				pushed = ft_pb(stack_a, &stack_b, pushed);
			i++;
		}
		while (pushed > 0)
			pushed = ft_pa(&stack_b, stack_a, pushed);
		j++;
	}
}

int	ft_unumber(t_stack **stack_a)
{
	unsigned int	add;
	t_stack			*head;
	t_stack			*temp;

	head = *stack_a;
	while (*stack_a)
	{
		temp = *stack_a;
		(*stack_a) = head;
		while (*stack_a)
		{
			if ((*stack_a)->number < temp->number)
				temp->unumber++;
			(*stack_a) = (*stack_a)->next;
		}
		(*stack_a) = temp;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head;
	return (0);
}
