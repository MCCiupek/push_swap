/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:02:46 by mciupek           #+#    #+#             */
/*   Updated: 2021/05/24 15:02:47 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(t_list *lst)
{
	int	*tmp;

	if (ft_lstsize(lst) < 2)
		return (1);
	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
	return (0);
}

int 		sa(t_stack *stack)
{
	ft_putstr_fd("sa\n", 1);
	return (ft_swap(stack->a));
}

int 		sb(t_stack *stack)
{
	ft_putstr_fd("sb\n", 1);
	return (ft_swap(stack->b));
}

int 		ss(t_stack *stack)
{
	ft_putstr_fd("ss\n", 1);
	return (ft_swap(stack->a) + ft_swap(stack->b));
}

