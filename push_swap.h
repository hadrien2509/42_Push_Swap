/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeissle <hgeissle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:16:12 by hgeissle          #+#    #+#             */
/*   Updated: 2023/03/06 12:56:11 by hgeissle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	unsigned int	unumber;
	struct s_stack	*next;
}					t_stack;

t_stack		*ft_lstbeforelast(t_stack *lst);
int			ft_put_tab_to_lst(int *tab, t_stack **stack_a, int i, int split);
int			ft_parse_argument(char **av, int i, t_stack **stack_a);
int			ft_parse(int ac, char **av, t_stack **stack_a);
int			ft_check_str(char *str, int *nbr);
int			ft_check_atoi(unsigned long long nb, int sign, int *nbr, int valid);
int			ft_atoi(const char *str, int *nbr);
int			ft_split(char const *s, char c, int **tab);
void		ft_sort(t_stack **stack_a, int size);
int			ft_pb(t_stack **stack_1, t_stack **stack_2, int pushed);
int			ft_pa(t_stack **stack_1, t_stack **stack_2, int pushed);
void		ft_rotate(t_stack **stack_1);
void		ft_swap(t_stack **stack);
void		ft_rrotate(t_stack **stack_1);
int			ft_putlst(t_stack *stack);
int			ft_issorted(t_stack *stack_a);

/* ************************************************************************** */
/*                                LIBFT_FCTS                                  */
/* ************************************************************************** */

t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstclear(t_stack **lst);

/* ************************************************************************** */
/*                                RADIX                                       */
/* ************************************************************************** */

int			ft_bitlen(int maximum);
void		ft_radix(t_stack **stack_a, int size, int len);
int			ft_unumber(t_stack **stack_a);

#endif
