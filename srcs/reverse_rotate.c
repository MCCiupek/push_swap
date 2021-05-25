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

int	ft_reverse_rotate(t_list *lst)
{
	return (0);
}

int rra(t_list *a)
{
	ft_putstr_fd("rra", 1);
	return (ft_reverse_rotate(a));
}

int rrb(t_list *b)
{
	ft_putstr_fd("rrb", 1);
	return (ft_reverse_rotate(b));
}

int rrr(t_list *a, t_list *b)
{
	ft_putstr_fd("rrr", 1);
	return (ft_reverse_rotate(a) + ft_reverse_rotate(b));
}
