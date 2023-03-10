/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:38:03 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/05 18:50:23 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strslen(const char *str, char c)
{
	int	i;
	int	len;
	int	counted;

	i = 0;
	len = 0;
	counted = 0;
	while (str[i])
	{
		if (str[i] != c && !counted)
		{
			len++;
			counted = 1;
		}
		else if (str[i] == c)
			counted = 0;
		i++;
	}
	return (len);
}

static char	*ft_range(const char *str, int min, int max)
{
	int		i;
	char	*range;

	range = malloc(sizeof(char) * (max - min + 1));
	if (!range)
		return (0);
	i = 0;
	while (str[min + i] && (min + i) < max)
	{
		range[i] = str[min + i];
		i++;
	}
	range[i] = '\0';
	return (range);
}

static int	set_tab(const char *str, char c, int *tab)
{
	int		i;
	int		len;
	int		split;
	char	*str_split;

	i = 0;
	split = 0;
	while (str[i])
	{
		len = 0;
		while (str[i + len] && str[i + len] != c)
			len++;
		if (len != 0)
		{
			str_split = ft_range(str, i, i + len);
			if (ft_check_str(str_split, &tab[split]) == -1)
				return (0);
			split++;
			i = i + len;
		}
		else
			i++;
	}
	return (split);
}

int	ft_split(char const *s, char c, int **tab)
{
	int		split;

	if (!s)
		return (0);
	*tab = malloc(sizeof(int) * (ft_strslen(s, c) + 1));
	if (!tab)
		return (0);
	split = set_tab(s, c, *tab);
	return (split);
}
