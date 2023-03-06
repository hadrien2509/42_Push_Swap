/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:45:02 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/02 19:08:23 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack_1)
{
	t_stack	*stack;

	stack = (*stack_1);
	(*stack_1) = (*stack_1)->next;
	stack->next = 0;
	ft_lstadd_back(stack_1, stack);
	ft_printf("ra\n");
}

void	ft_rrotate(t_stack **stack_1)
{
	t_stack	*temp_l;
	t_stack	*temp_bl;

	temp_l = ft_lstlast(*stack_1);
	temp_bl = ft_lstbeforelast(*stack_1);
	ft_lstadd_front(stack_1, temp_l);
	temp_bl->next = 0;
	ft_printf("rra\n");
}

int	ft_pa(t_stack **stack_1, t_stack **stack_2, int pushed)
{
	t_stack	*stack;

	stack = *stack_1;
	(*stack_1) = (*stack_1)->next;
	stack->next = *stack_2;
	*stack_2 = stack;
	pushed--;
	ft_printf("pa\n");
	return (pushed);
}

int	ft_pb(t_stack **stack_1, t_stack **stack_2, int pushed)
{
	t_stack	*stack;

	stack = *stack_1;
	(*stack_1) = (*stack_1)->next;
	stack->next = *stack_2;
	*stack_2 = stack;
	pushed++;
	ft_printf("pb\n");
	return (pushed);
}

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	head = (*stack)->next;
	temp = (*stack)->next->next;
	(*stack)->next->next = (*stack);
	(*stack)->next = temp;
	(*stack) = head;
	ft_printf("sa\n");
}
