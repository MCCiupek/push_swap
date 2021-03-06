/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:21:49 by mciupek           #+#    #+#             */
/*   Updated: 2020/11/23 18:39:08 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlink_prev(t_list *lst)
{
	lst->prev = NULL;
	lst = lst->next;
	while (lst->next)
	{
		lst->next->prev = lst;
		lst = lst->next;
	}
}
