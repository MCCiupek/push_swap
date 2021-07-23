/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:13:59 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/23 16:14:01 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dec2bin(int val, int bin[32])
{
	int	i;

	i = 32;
	while (i--)
	{
		bin[i] = val % 2;
		val = val / 2;
	}
}

static int	all_bits_eq(t_list *lst, int i, int eq)
{
	t_list	*tmp;
	t_elem	*elem;

	tmp = lst;
	while (tmp)
	{
		elem = (t_elem *)tmp->content;
		if (elem->bin[i] != eq)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_radix(t_stack *stack)
{
    int		i;
	int		j;
	int		size;
    t_elem	*top_a;

	i = 32;
	while (--i)
	{
		if (all_bits_eq(stack->a, i, 0))
			continue ;
		j = 0;
		size = ft_lstsize(stack->a);
		while (j++ < size)
		{
			top_a = (t_elem *)stack->a->content;
			//printf("%d/%d | bin[%d]: %d\n", top_a->idx, ft_lstsize(stack->a), i, top_a->bin[i]);
			if (!top_a->bin[i])
				pb(stack);
			else
				ra(stack);
		}
		while (!is_empty(stack->b))
			pa(stack);
		if (is_sorted_incorder(stack->a))
			break ;
		//print_lsts(stack);
	}
}