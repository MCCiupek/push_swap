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

static int	ft_reverse_rotate(t_list **lst)
{
	t_list	*tmp;

	if (is_empty(*lst))
		return (1);
	tmp = ft_lstnew(ft_lstlast(*lst)->content);
	ft_lstadd_front(lst, tmp);
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	return (0);
}

int	rra(t_stack *stack)
{
	ft_putstr_fd("rra\n", 1);
	return (ft_reverse_rotate(&stack->a));
}

int	rrb(t_stack *stack)
{
	ft_putstr_fd("rrb\n", 1);
	return (ft_reverse_rotate(&stack->b));
}

int	rrr(t_stack *stack)
{
	ft_putstr_fd("rrr\n", 1);
	return (ft_reverse_rotate(&stack->a) + ft_reverse_rotate(&stack->b));
}
