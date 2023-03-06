/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:37:42 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/05 19:28:28 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstbeforelast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next->next)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

int	ft_issorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->number > stack_a->next->number)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
