/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:54:55 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/21 16:54:57 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reorder_a(t_stack *stack)
{
	int	order;

	order = ft_rotate_order_min(stack->a);
	while (((t_elem *)stack->a->content)->idx != ft_min_idx(stack->a))
	{
		if (order == 1)
			ra(stack);
		else if (!order)
			rra(stack);
	}
}

static void	b_to_a(t_stack *stack)
{
	int	order;

	while (!is_empty(stack->b))
	{
		if (((t_elem *)stack->b->content)->idx
			> ((t_elem *)ft_lstlast(stack->a))->idx)
		{
			pa(stack);
			ra(stack);
			continue ;
		}
		while (ft_rotate_a(stack))
			ra(stack);
		while (((t_elem *)stack->b->content)->idx != ft_min_idx(stack->b))
		{
			order = ft_rotate_order_min(stack->b);
			if (order == 1)
				rb(stack);
			else if (!order)
				rrb(stack);
		}
		pa(stack);
	}
}

void	ft_sort5(t_stack *stack)
{
	pb(stack);
	if (((t_elem *)stack->a->content)->idx == 3)
		ra(stack);
	pb(stack);
	ft_sort3(stack);
	b_to_a(stack);
	reorder_a(stack);
}

void	ft_sort(t_stack *stack)
{
	if (ft_lstsize(stack->a) == 3)
		return (ft_sort3(stack));
	if (ft_lstsize(stack->a) == 5)
		return (ft_sort5(stack));
	return ;
}
