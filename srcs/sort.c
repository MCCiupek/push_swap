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

static void	a_to_b(t_stack *stack)
{
	int	cpt;

	cpt = 0;
	while (cpt < 10 && count_false(stack->a))
	{
		cpt++;
		if (swap_is_needed(stack->a))
		{
			sa(stack);
			update_markups(stack->a);
		}
		else if (!((t_elem *)stack->a->content)->markup)
			pb(stack);
		else
			ra(stack);
	}
}

static void	b_to_a(t_stack *stack)
{
	int	order;

	while (!is_empty(stack->b))
	{
		while (ft_rotate_a(stack))
			ra(stack);
		while (((t_elem *)stack->b->content)->idx != ft_min_idx(stack->b))
		{
			order = ft_rotate_order(stack->b);
			if (order == 1)
				rb(stack);
			else if (!order)
				rrb(stack);
		}
		pa(stack);
	}
}

static void reorder_a(t_stack *stack)
{
	while (((t_elem *)stack->a->content)->idx)
		ra(stack);
}

void	ft_sort(t_stack *stack)
{
	a_to_b(stack);
	b_to_a(stack);
	reorder_a(stack);
}
