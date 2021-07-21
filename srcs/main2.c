/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:42:48 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/16 14:42:51 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_lsts(t_stack *stack)
{
	ft_lstclear(&stack->a, free);
	ft_lstclear(&stack->b, free);
}

static int	init_stack(t_stack *stack, int size)
{
	stack->size = size - 1;
	stack->a = NULL;
	stack->b = NULL;
	return (1);
}

static void	get_position(t_list **lst)
{
	t_list	*tmp;
	t_list	**new_lst;
	t_elem	*elem;
	int		size;
	int		i;
	int		cpt;

	i = 0;
	size = ft_lstsize(*lst);
	while (i < size)
	{
		tmp = *lst;
		cpt = 0;
		new_lst = NULL;
		while (tmp)
		{
			elem = (t_elem *)tmp->content;
			new_lst = ft_lstidxminloc(lst, elem, cpt, i);
			if (new_lst)
			{
				lst = new_lst;
				cpt++;
				break ;
			}
			cpt++;
			tmp = tmp->next;
		}
		i++;
	}
}

static int dec_to_inc(t_stack *stack)
{
	while (!is_empty(stack->a))
		pb(stack);
	while (!is_empty(stack->b))
		pa(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	init_stack(&stack, argc);
	if (ft_tab_to_lst(argv, &stack))
	{
		if (is_sorted_decorder(stack.a))
			return (dec_to_inc(&stack));
		get_position(&stack.a);
		get_markups(&stack.a);
		//print_lsts(&stack);
		ft_sort(&stack);
		//print_lsts(&stack);
		clear_lsts(&stack);
	}
	return (0);
}
