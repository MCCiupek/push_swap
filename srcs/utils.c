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

t_list	**ft_lstidxminloc(t_list **lst, t_elem *elem, int index, int val)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (elem->idx > -1)
			return (NULL);
		if (elem->nb > ((t_elem *)tmp->content)->nb
			&& ((t_elem *)tmp->content)->idx == -1)
			return (NULL);
		tmp = tmp->next;
	}
	return (ft_lstchangeval(lst, index, val));
}

int	ft_rotate_a(t_stack *stack)
{
	t_list	*a;
	t_list	*b;

	a = (t_list *)stack->a;
	b = (t_list *)stack->b;
	if (ft_max_idx(stack->a) < ft_min_idx(stack->b)
		&& ((t_elem *)a->content)->idx)
		return (1);
	if (ft_max_idx(stack->a) < ft_min_idx(stack->b)
		&& !((t_elem *)a->content)->idx)
		return (0);
	if (((t_elem *)b->content)->idx < ft_min_idx(stack->a)
		&& ((t_elem *)a->content)->idx != ft_min_idx(stack->a))
		return (1);
	if (((t_elem *)b->content)->idx < ft_min_idx(stack->a)
		&& ((t_elem *)a->content)->idx == ft_min_idx(stack->a))
		return (0);
	if (((t_elem *)a->content)->idx < ft_min_idx(stack->b))
		return (1);
	return (0);
}

int	ft_rotate_order_max(t_list *lst)
{
	int		i;
	int		i_max;
	int		max;
	int		size;
	t_list	*tmp;

	i = 0;
	i_max = 0;
	max = ((t_elem *)lst->content)->idx;
	size = ft_lstsize(lst);
	tmp = lst->next;
	while (tmp)
	{
		i++;
		if (((t_elem *)tmp->content)->idx > max)
		{
			i_max = i;
			max = ((t_elem *)tmp->content)->idx;
		}
		tmp = tmp->next;
	}
	if (!i_max)
		return (-1);
	return (i_max < size / 2);
}

int	ft_rotate_order_min(t_list *lst)
{
	int		i;
	int		i_min;
	int		min;
	int		size;
	t_list	*tmp;

	i = 0;
	i_min = 0;
	min = ((t_elem *)lst->content)->idx;
	size = ft_lstsize(lst);
	tmp = lst->next;
	while (tmp)
	{
		i++;
		if (((t_elem *)tmp->content)->idx < min)
		{
			i_min = i;
			min = ((t_elem *)tmp->content)->idx;
		}
		tmp = tmp->next;
	}
	if (!i_min)
		return (-1);
	return (i_min < size / 2);
}

int	ft_min_idx(t_list *lst)
{
	int		min;
	int		size;
	t_list	*tmp;

	min = ((t_elem *)lst->content)->idx;
	size = ft_lstsize(lst);
	tmp = lst->next;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->idx < min)
			min = ((t_elem *)tmp->content)->idx;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_max_idx(t_list *lst)
{
	int		max;
	int		size;
	t_list	*tmp;

	max = ((t_elem *)lst->content)->idx;
	size = ft_lstsize(lst);
	tmp = lst->next;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->idx > max)
			max = ((t_elem *)tmp->content)->idx;
		tmp = tmp->next;
	}
	return (max);
}
