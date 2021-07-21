/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:07:19 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/19 16:07:20 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_indices(t_list *elem)
{
	int		idx;
	int		cpt;
	t_list	*tmp;

	cpt = 0;
	idx = ((t_elem *)elem->content)->idx;
	((t_elem *)elem->content)->markup = 1;
	tmp = elem->next;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->idx > idx)
		{
			cpt++;
			idx = ((t_elem *)tmp->content)->idx;
			((t_elem *)tmp->content)->markup = 1;
		}
		else
			((t_elem *)tmp->content)->markup = 0;
		tmp = tmp->next;
	}
	return (cpt);
}

int	get_markup(t_list *elem, t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp && tmp != elem)
	{
		((t_elem *)tmp->content)->markup = 0;
		tmp = tmp->next;
	}
	return (set_indices(elem));
}

static int	set_as_head(t_list *tmp, t_list **head)
{
	int	max;

	((t_elem *)tmp->content)->is_head = 1;
	((t_elem *)(*head)->content)->is_head = 0;
	max = ((t_elem *)tmp->content)->nb_true;
	*head = tmp->content;
	return (max);
}

static void	get_head(t_list *lst)
{
	int		max;
	t_list	*head;
	t_list	*tmp;

	tmp = lst;
	max = ((t_elem *)tmp->content)->nb_true;
	head = tmp;
	((t_elem *)head->content)->is_head = 1;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->nb_true > max)
			max = set_as_head(tmp, &head);
		else if (((t_elem *)tmp->content)->nb_true == max
			&& ((t_elem *)tmp->content)->nb < ((t_elem *)head->content)->nb)
			max = set_as_head(tmp, &head);
		tmp = tmp->next;
	}
}

void	get_markups(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		((t_elem *)tmp->content)->nb_true = get_markup(tmp, *lst);
		tmp = tmp->next;
	}
	tmp = *lst;
	get_head(*lst);
	while (tmp)
	{
		if (((t_elem *)tmp->content)->is_head)
			get_markup(tmp, *lst);
		tmp = tmp->next;
	}
}
