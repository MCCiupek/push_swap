/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markups_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:58:43 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/21 17:58:44 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_lstcpy(void *ptr)
{
	void	*new;

	new = (void *)malloc(sizeof(ptr));
	new = ft_memcpy(new, ptr, sizeof(ptr));
	return (new);
}

t_list	*ft_lstswaped(t_list *lst)
{
	t_list	*swaped_list;
	t_list	*tmp;

	swaped_list = ft_lstmap(lst, ft_lstcpy, free);
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
	ft_lstclear(&swaped_list, free);
	if (nb_false_bf_sa > nb_false_af_sa)
		return (1);
	return (0);
}

void	update_markups(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!((t_elem *)tmp->content)->is_head)
			tmp = tmp->next;
		else
			break ;
	}
	get_markup(tmp, lst);
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
