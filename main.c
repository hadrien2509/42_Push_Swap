/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:46:42 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/06 16:52:47 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	int			size;

	stack_a = 0;
	size = ft_parse(ac, av, &stack_a);
	if (size == -1)
	{
		ft_printf("Error\n");
		ft_lstclear(&stack_a);
		return (1);
	}
	if (size == 0)
		return (0);
	ft_sort(&stack_a, size);
	ft_lstclear(&stack_a);
	return (0);
}
