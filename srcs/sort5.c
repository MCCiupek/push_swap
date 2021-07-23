/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:29:15 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/22 18:29:17 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cpt_ops_min(t_stack *stack)
{
	t_list	*a;
	t_list	*b;
	int		order;
	int		cpt;

	a = ft_lstmap(stack->a, ft_lstcpy, free);
	b = ft_lstmap(stack->b, ft_lstcpy, free);
	cpt = 0;
	while (!is_empty(b))
	{
		if (((t_elem *)b->content)->idx > ((t_elem *)ft_lstlast(a))->idx)
		{
			cpt += 2;
			ft_push(&b, &a);
			ft_rotate(&a);
			continue ;
		}
		while (ft_rotate_a(stack))
		{
			cpt++;
			ft_rotate(&a);
		}
		while (((t_elem *)b->content)->idx != ft_min_idx(b))
		{
			order = ft_rotate_order_min(b);
			if (order == 1)
				ft_rotate(&b);
			else if (!order)
				ft_reverse_rotate(&b);
			cpt++;
		}
		ft_push(&b, &a);
		cpt++;
	}
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	return (cpt);
}

int	ft_cpt_ops_max(t_stack *stack)
{
	t_list	*a;
	t_list	*b;
	int		order;
	int		cpt;

	a = ft_lstmap(stack->a, ft_lstcpy, free);
	b = ft_lstmap(stack->b, ft_lstcpy, free);
	cpt = 0;
	while (!is_empty(b))
	{
		if (((t_elem *)b->content)->idx > ((t_elem *)ft_lstlast(a))->idx)
		{
			cpt += 2;
			ft_push(&b, &a);
			ft_rotate(&a);
			continue ;
		}
		while (ft_rotate_a(stack))
		{
			cpt++;
			ft_rotate(&a);
		}
		while (((t_elem *)b->content)->idx != ft_max_idx(b))
		{
			order = ft_rotate_order_max(b);
			if (order == 1)
				ft_rotate(&b);
			else if (!order)
				ft_reverse_rotate(&b);
			cpt++;
		}
		ft_push(&b, &a);
		ft_rotate(&a);
		cpt += 2;
	}
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	return (cpt);
}

int	ft_select_item(t_stack *stack)
{
	int	nb_obs_min;
	int	nb_obs_max;

	nb_obs_min = ft_cpt_ops_min(stack);
	nb_obs_max = ft_cpt_ops_man(stack);
}

void	ft_sort5(t_stack *stack)
{
	pb(stack);
	pb(stack);
	ft_sort3(stack);
}
