/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:50:04 by mciupek           #+#    #+#             */
/*   Updated: 2021/05/12 19:50:05 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_empty(t_list *lst)
{
	if (!ft_lstsize(lst))
		return (1);
	return (0);
}

static int	is_sorted_incorder(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		//printf("%d - %d\n", *(int *)tmp->content, *(int *)tmp->next->content);
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	is_sorted_decorder(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_is_rep(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
			if (ft_atol(tab[i]) == ft_atol(tab[j++]))
				return (1);
		i++;
	}
	return (0);
}

static int	ft_is_not_int(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atol(tab[i]) > INT_MAX || ft_atol(tab[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_tab_to_lst(char **tab, t_stack *stack)
{
	int	i;
	int	*nb;

	i = 1;
	if (ft_is_not_int(&tab[1]) || ft_is_rep(&tab[1]))
	{
		ft_putstr_fd("Error\n", STDERR);
		return (0);
	}
	while (tab[i])
	{
		nb = (int *)malloc(sizeof(int));
		*nb = ft_atoi(tab[i++]);
		ft_lstadd_back(&stack->a, ft_lstnew(nb));
	}
	return (1);
}

static void	print_lst(t_list *lst)
{
	int	*nb;

	printf("lst : ");
	while (lst)
	{
		if (lst->content)
		{
			nb = (int *)lst->content;
			printf("%d ", *nb);
		}
		else
			printf("(null) ");
		lst = lst->next;
	}
	printf("\n");
}

static void	print_lsts(t_stack *stack)
{
	print_lst(stack->a);
	print_lst(stack->b);
}

static void	clear_lsts(t_stack *stack)
{
	ft_lstclear(&stack->a, NULL);
	ft_lstclear(&stack->b, NULL);
}

static int	init_stack(t_stack *stack, int size)
{
	stack->size = size - 1;
	stack->a = NULL;
	stack->b = NULL;
	return (1);
}

static int	max(long pos[6])
{
	long	max;
	int		i;

	i = -1;
	max = pos[i];
	while (++i < 6)
		if (pos[i] < (long)INT_MAX + 1 && pos[i] > max)
			max = pos[i];
	return (max);
}

static int	min(long pos[6])
{
	long	min;
	int		i;

	i = -1;
	min = pos[i];
	while (++i < 6)
		if (pos[i] < (long)INT_MAX + 1 && pos[i] < min)
			min = pos[i];
	return (min);
}

static void	get_pos(t_stack *stack, long *pos)
{
	pos[A_1] = (long)INT_MAX + 1;
	pos[B_1] = (long)INT_MAX + 1;
	pos[A_2] = (long)INT_MAX + 1;
	pos[B_2] = (long)INT_MAX + 1;
	pos[A_N] = (long)INT_MAX + 1;
	pos[B_N] = (long)INT_MAX + 1;
	if (stack->a)
		pos[A_1] = *(long *)stack->a->content;
	if (stack->b)
		pos[B_1] = *(long *)stack->b->content;
	if (ft_lstsize(stack->a) > 1)
		pos[A_2] = *(long *)stack->a->next->content;
	if (ft_lstsize(stack->b) > 1)
		pos[B_2] = *(long *)stack->b->next->content;
	if (stack->a)
		pos[A_N] = *(long *)ft_lstlast(stack->a)->content;
	if (stack->b)
		pos[B_N] = *(long *)ft_lstlast(stack->b)->content;
}

int			main(int argc, char **argv)
{
	t_stack	stack;
	long	*pos;//[6];

	if (argc > 1)
	{
		pos = (long *)malloc(sizeof(long) * 6);
		if (!init_stack(&stack, argc))
			return (0);
		if ((ft_tab_to_lst(argv, &stack)))
		{
			ft_putstr_fd("INIT\n", STDOUT);
			print_lsts(&stack);
			while (!is_sorted_incorder(stack.a) || !is_empty(stack.b))
			{
				get_pos(&stack, pos);
				/* ROTATE */
				if (pos[A_1] == max(pos) && pos[B_1] == min(pos))
					rr(&stack);
				else if (pos[A_1] == max(pos))
					ra(&stack);
				else if (pos[B_1] == min(pos))
					rb(&stack);
				/* REVERSE ROTATE */
				else if (pos[A_N] == min(pos) && pos[B_N] == max(pos))
					rrr(&stack);
				else if (pos[A_N] == min(pos))
					rra(&stack);
				else if (pos[B_N] == max(pos))
					rrb(&stack);
				/* SWAP */
				else if (pos[A_1] < (long)INT_MAX + 1 && pos[A_2] < (long)INT_MAX + 1 &&
					pos[B_1] < (long)INT_MAX + 1 && pos[B_2] < (long)INT_MAX + 1 &&
					pos[A_1] > pos[A_2] && pos[B_1] < pos[B_2])
					ss(&stack);
				else if (pos[A_1] < (long)INT_MAX + 1 && pos[A_2] < (long)INT_MAX + 1 &&
					pos[A_1] > pos[A_2])
					sa(&stack);
				else if (pos[B_1] < (long)INT_MAX + 1 && pos[B_2] < (long)INT_MAX + 1 &&
					pos[B_1] < pos[B_2])
					sb(&stack);
				/* PUSH */
				else if (pos[A_1] < pos[B_1])
					pb(&stack);
				else if (pos[A_1] > pos[B_1])
					pa(&stack);
				else
				{
					ft_putstr_fd("break\n", STDERR);
					print_lsts(&stack);
					break ;
				}
			}
		}
		ft_putstr_fd("FINAL\n", STDOUT);
		print_lsts(&stack);
		clear_lsts(&stack);
	}
	return (0);
}
