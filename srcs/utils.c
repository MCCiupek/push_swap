/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:28:13 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/16 10:28:17 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_empty(t_list *lst)
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

int	max(long long pos[6])
{
	long long	max;
	int		i;

	i = -1;
	max = pos[i];
	while (++i < 6)
		if (pos[i] < (long long)INT_MAX + 1 && pos[i] > max)
			max = pos[i];
	return (max);
}

int	min(long long pos[6])
{
	long long	min;
	int		i;

	i = -1;
	min = pos[i];
	while (++i < 6)
		if (pos[i] < (long long)INT_MAX + 1 && pos[i] < min)
			min = pos[i];
	return (min);
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
	return (lst);
}

t_list	**ft_lstidxminloc(t_list **lst, t_elem *elem, int index, int val)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (elem->idx > -1)
			return (NULL);
		if (elem->nb > ((t_elem *)tmp->content)->nb && ((t_elem *)tmp->content)->idx == -1)
			return (NULL);
		tmp = tmp->next;
	}
	return (ft_lstchangeval(lst, index, val));
}


