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

int	ft_rotate(t_list *lst)
{
	return (0);
}

int ra(t_list *a)
{
	ft_putstr_fd("ra", 1);
	return (ft_rotate(a));
}

int rb(t_list *b)
{
	ft_putstr_fd("rb", 1);
	return (ft_rotate(b));
}

int rr(t_list *a, t_list *b)
{
	ft_putstr_fd("rr", 1);
	return (ft_rotate(a) + ft_rotate(b));
}
