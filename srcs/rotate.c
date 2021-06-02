/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:53:46 by mciupek           #+#    #+#             */
/*   Updated: 2021/05/24 14:53:50 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rotate(t_list **lst)
{
	t_list  *tmp;

	if (is_empty(*lst))
		return (1);
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	return (0);
}

int 		ra(t_stack *stack)
{
	ft_putstr_fd("ra\n", 1);
	return (ft_rotate(&stack->a));
}

int 		rb(t_stack *stack)
{
	ft_putstr_fd("rb\n", 1);
	return (ft_rotate(&stack->b));
}

int 		rr(t_stack *stack)
{
	ft_putstr_fd("rr\n", 1);
	return (ft_rotate(&stack->a) + ft_rotate(&stack->b));
}
