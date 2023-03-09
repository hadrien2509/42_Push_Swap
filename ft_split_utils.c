/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:23:28 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/09 16:05:44 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_atoi(unsigned long long nb, int sign, int *nbr, int valid)
{
	if (nb > 2147483647 && sign == 1)
		return (0);
	if (nb > 2147483648 && sign == -1)
		return (0);
	*nbr = sign * (int)nb;
	return (valid);
}

int	ft_atoi(const char *str, int *nbr)
{
	int					i;
	int					sign;
	unsigned long long	nb;
	int					valid;

	i = 0;
	sign = 1;
	nb = 0;
	valid = -1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && valid)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
		valid = 1;
		valid = ft_check_atoi(nb, sign, nbr, valid);
	}
	if (str[i] != '\0')
		return (-1);
	return (valid);
}

int	ft_check_str(char *str, int *nbr)
{
	int		atoi_check;

	if (!str)
		return (-1);
	atoi_check = ft_atoi(str, nbr);
	free(str);
	if (atoi_check != 1)
		return (-1);
	return (0);
}
