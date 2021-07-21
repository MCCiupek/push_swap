/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:37:42 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/16 10:37:50 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list *lst)
{
	int	nb;
	int	idx;
	int	nb_true;
	int	markup;
	int	head;

	printf("nb\t\tpos\t\tmarkup\t\tnb_true\t\thead\n");
	while (lst)
	{
		if (lst->content)
		{
			nb = ((t_elem *)lst->content)->nb;
			idx = ((t_elem *)lst->content)->idx;
			nb_true = ((t_elem *)lst->content)->nb_true;
			markup = ((t_elem *)lst->content)->markup;
			head = ((t_elem *)lst->content)->is_head;
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", nb, idx, markup, nb_true, head);
		}
		else
			printf("(null) ");
		lst = lst->next;
	}
	//printf("\t\t [%d]", is_sorted_incorder(lst));
	printf("\n\n");
}

void	print_lsts(t_stack *stack)
{
	print_lst(stack->a);
	print_lst(stack->b);
}
