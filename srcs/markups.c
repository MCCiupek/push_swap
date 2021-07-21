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

t_list	*ft_lstswaped(t_list *lst)
{
	t_list	*swaped_list;
	t_list	*tmp;

	swaped_list = lst;
	tmp = swaped_list->content;
	swaped_list->content = swaped_list->next->content;
	swaped_list->next->content = tmp;
	update_markups(swaped_list);
	return (swaped_list);
}

int	swap_is_needed(t_list *lst)
{
	t_list	*swaped_list;
	int		nb_false_bf_sa;
	int		nb_false_af_sa;

	swaped_list = ft_lstswaped(lst);
	nb_false_bf_sa = count_false(lst);
	nb_false_af_sa = count_false(swaped_list);
	if (nb_false_bf_sa > nb_false_af_sa)
		return (1);
	return (0);
}

void	update_markups(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
		if (!((t_elem *)tmp->content)->is_head)
			tmp = tmp->next;
		else
			break ;
	get_markup(tmp);	
}

int	count_false(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (((t_elem *)tmp->content)->markup == 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	get_markup(t_list *elem)
{
	int		cpt;
	int		idx;
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
		{
			((t_elem *)tmp->content)->is_head = 1;
			((t_elem *)head->content)->is_head = 0;
			max = ((t_elem *)tmp->content)->nb_true;
			head = tmp->content;
		}
		else if (((t_elem *)tmp->content)->nb_true == max &&
			((t_elem *)tmp->content)->nb < ((t_elem *)head->content)->nb)
		{
			((t_elem *)tmp->content)->is_head = 1;
			((t_elem *)head->content)->is_head = 0;
			max = ((t_elem *)tmp->content)->nb_true;
			head = tmp->content;
		}
		tmp = tmp->next;
	}
}

void	get_markups(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		((t_elem *)tmp->content)->nb_true = get_markup(tmp);
		tmp = tmp->next;
	}
	tmp = *lst;
	get_head(*lst);
	while (tmp)
	{
		if (((t_elem *)tmp->content)->is_head)
			get_markup(tmp);
		tmp = tmp->next;
	}
}
