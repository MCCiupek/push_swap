/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:02:23 by mciupek           #+#    #+#             */
/*   Updated: 2021/05/24 15:02:25 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (is_empty(*src))
		return (1);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dest, tmp);
	return (0);
}

int	pa(t_stack *stack)
{
	ft_putstr_fd("pa\n", 1);
	return (ft_push(&stack->b, &stack->a));
}

int	pb(t_stack *stack)
{
	ft_putstr_fd("pb\n", 1);
	return (ft_push(&stack->a, &stack->b));
}
