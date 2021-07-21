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

static void	sorted_insert(t_stack *stack)
{
	if (is_empty(stack->a) || ((t_elem *)stack->a->content)->nb < ((t_elem *)stack->b->content)->nb)
	{
        pa(stack);
        return ;
    }
	pb(stack);
	sb(stack);
	pa(stack);
    sorted_insert(stack);
    pb(stack);
}

void sort_stack(t_stack *stack)
{
	if (!is_empty(stack->a))
	{
		pb(stack);
		sort_stack(stack);
		sorted_insert(stack);
    }
}

/*
WHILE stack A has elements with "false" value in "Keep in Stack A" field
      IF sa (swap a) is needed
            perform sa (swap a) command
            update markup
      ELSE IF head element of stack A has "false" value in "Keep in Stack A" field
            perform pb (push b) command
      ELSE
            perform ra (rotate a) command
*/

static void	ft_sort(t_stack *stack)
{
	while (count_false(stack->a))
	{
		if (swap_is_needed(stack->a))
		{
			sa(stack);
			update_markups(stack->a);
		}
		else if (!((t_elem *)stack->a->content)->markup)
			pb(stack);
		else
			ra(stack);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	init_stack(&stack, argc);
	if (ft_tab_to_lst(argv, &stack))
	{
		get_position(&stack.a);
		get_markups(&stack.a);
		print_lsts(&stack);
		sort_stack(&stack);
		print_lsts(&stack);
		clear_lsts(&stack);
	}
	return (0);
}
