/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:46:41 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/21 17:46:42 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_list *lst)
{
	if (!lst)
		return (1);
	if (!ft_lstsize(lst))
		return (1);
	return (0);
}

int	is_sorted_incorder(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
	{
		if (((t_elem *)tmp->content)->nb > ((t_elem *)tmp->next->content)->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted_decorder(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
	{
		if (((t_elem *)tmp->content)->nb < ((t_elem *)tmp->next->content)->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_islstmin(t_list *lst)
{
	int		nb;
	t_list	*tmp;

	nb = ((t_elem *)lst->content)->nb;
	tmp = lst->next;
	while (tmp)
	{
		if (nb > ((t_elem *)lst->content)->nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_list	**ft_lstchangeval(t_list **lst, int index, int val)
{
	int		i;
	t_list	*tmp;

	tmp = *lst;
	i = -1;
	while (++i < index)
		tmp = tmp->next;
	((t_elem *)tmp->content)->idx = val;
	ft_dec2bin(val, ((t_elem *)tmp->content)->bin);
	return (lst);
}
