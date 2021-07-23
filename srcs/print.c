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

	printf("nb\t\tpos\t\tmarkup\t\tnb_true\t\thead\tbin\n");
	while (lst)
	{
		if (lst->content)
		{
			nb = ((t_elem *)lst->content)->nb;
			idx = ((t_elem *)lst->content)->idx;
			nb_true = ((t_elem *)lst->content)->nb_true;
			markup = ((t_elem *)lst->content)->markup;
			head = ((t_elem *)lst->content)->is_head;
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t", nb, idx, markup, nb_true, head);
			int i = 0;
			while (i < 32)
				printf("%d", ((t_elem *)lst->content)->bin[i++]);
			printf("\n");
		}
		else
			printf("(null) ");
		lst = lst->next;
	}
	printf("\n\n");
}

void	print_lsts(t_stack *stack)
{
	print_lst(stack->a);
	print_lst(stack->b);
}
