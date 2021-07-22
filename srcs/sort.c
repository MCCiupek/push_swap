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

	order = ft_rotate_order(stack->a);
	while (((t_elem *)stack->a->content)->idx != ft_min_idx(stack->a))
	{
		if (order == 1)
			ra(stack);
		else if (!order)
			rra(stack);
	}
}

static void	a_to_b(t_stack *stack)
{
	int	swap;

	swap = 0;
	while (count_false(stack->a))
	{
		if (swap_is_needed(stack->a) && !swap)
		{
			swap = 1;
			sa(stack);
			update_markups(stack->a);
		}
		else if (!((t_elem *)stack->a->content)->markup)
		{
			swap = 0;
			pb(stack);
		}
		else
		{
			swap = 0;
			ra(stack);
		}
	}
	reorder_a(stack);
}

static void	b_to_a(t_stack *stack)
{
	int	order;

	while (!is_empty(stack->b))
	{
		while (ft_rotate_a(stack))
			ra(stack);
		if (stack->b->next && ((t_elem *)stack->b->content)->idx > ((t_elem *)stack->b->next->content)->idx)
			sb(stack);
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

void	ft_sort5(t_stack *stack)
{
//	int	top_a;
//	int	top_b;
//
	pb(stack);
	pb(stack);
	ft_sort3(stack);
	if (((t_elem *)stack->b->content)->idx > ((t_elem *)stack->b->next->content)->idx)
		sb(stack);
/*	while (!is_empty(stack->b))
	{
		top_a = ((t_elem *)stack->a->content)->idx;
		top_b = ((t_elem *)stack->b->content)->idx;
		if (top_b < top_a || (top_b == 5 && top_a == 0))
			pa(stack);
		else
			ra(stack);
	}*/
	b_to_a(stack);
	reorder_a(stack);
}

void	ft_sort(t_stack *stack)
{
	if (ft_lstsize(stack->a) == 3)
		return (ft_sort3(stack));
	if (ft_lstsize(stack->a) == 5)
		return (ft_sort5(stack));
	a_to_b(stack);
	b_to_a(stack);
	reorder_a(stack);
}
