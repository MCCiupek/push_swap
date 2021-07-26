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
			new_lst = ft_lstidxminloc(lst, (t_elem *)tmp->content, cpt++, i);
			if (new_lst)
			{
				lst = new_lst;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**tab;

	init_stack(&stack, argc);
	if (argc == 1 || !argv[1][0])
		return (0);
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
		tab = ft_copy_array(&argv[1]);
	if (ft_tab_to_lst(tab, &stack))
	{
		get_position(&stack.a);
		if (ft_lstsize(stack.a) == 3 || ft_lstsize(stack.a) == 5)
			ft_sort(&stack);
		else
			ft_radix(&stack);
		clear_lsts(&stack);
	}
	ft_free_array(tab);
	return (0);
}
