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
	if (!lst)
		return (1);
	if (!ft_lstsize(lst))
		return (1);
	return (0);
}

static int	is_sorted_incorder(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
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

	if (!lst)
		return (0);
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
	//printf("\t\t [%d]", is_sorted_incorder(lst));
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

static int	max(long long pos[6])
{
	long long	max;
	int		i;

	i = -1;
	max = pos[i];
	while (++i < 6)
		if (pos[i] < (long long)INT_MAX + 1 && pos[i] > max)
			max = pos[i];
	return (max);
}

static int	min(long long pos[6])
{
	long long	min;
	int		i;

	i = -1;
	min = pos[i];
	while (++i < 6)
		if (pos[i] < (long long)INT_MAX + 1 && pos[i] < min)
			min = pos[i];
	return (min);
}

static void	get_pos(t_stack *stack, long long *pos)
{
	pos[A_1] = (long long)INT_MAX + 1;
	pos[B_1] = (long long)INT_MAX + 1;
	pos[A_2] = (long long)INT_MAX + 1;
	pos[B_2] = (long long)INT_MAX + 1;
	pos[A_N] = (long long)INT_MAX + 1;
	pos[B_N] = (long long)INT_MAX + 1;
	if (stack->a)
		pos[A_1] = *(int *)stack->a->content;
	if (stack->b)
		pos[B_1] = *(int *)stack->b->content;
	if (ft_lstsize(stack->a) > 1)
		pos[A_2] = *(int *)stack->a->next->content;
	if (ft_lstsize(stack->b) > 1)
		pos[B_2] = *(int *)stack->b->next->content;
	if (stack->a)
		pos[A_N] = *(int *)ft_lstlast(stack->a)->content;
	if (stack->b)
		pos[B_N] = *(int *)ft_lstlast(stack->b)->content;
}

/*static void	ft_insert(t_stack *stack, int elem)
{
	int	top;

	if (!is_empty(stack->a))
	{
		top = *(int *)stack->a->content;
		if (elem > top)
		{
			pb(stack);
			ft_insert(stack->a, elem);
			//pa(stack);
		}
		else
		{
			pb(stack);

			pa(stack);
		}
	}
	else
		pa(stack);
}

static void	ft_sort(t_stack *stack)
{
	int	top;

	if (!is_empty(stack->a))
	{
		pb(stack);
		top = *(int *)stack->b->content;
		ft_sort(stack);
		ft_insert(stack, top);
	}
}

int			main(int argc, char **argv)
{
	t_stack		stack;
	long long	*pos;
	int			cpt;
	int			tmp;

	cpt = 0;
	if (argc > 1)
	{
		pos = (long long *)malloc(sizeof(long long) * 6);
		if (!init_stack(&stack, argc))
			return (0);
		if ((ft_tab_to_lst(argv, &stack)))
		{
			ft_putstr_fd("INIT\n", STDOUT);
			print_lsts(&stack);
			ft_sort(&stack);
		}
		ft_putstr_fd("FINAL\n", STDOUT);
		print_lsts(&stack);
		clear_lsts(&stack);
	}
	return (0);
}*/

int			main(int argc, char **argv)
{
	t_stack		stack;
	long long	*pos;
	int			cpt;
	int			tmp;

	cpt = 0;
	if (argc > 1)
	{
		pos = (long long *)malloc(sizeof(long long) * 6);
		if (!init_stack(&stack, argc))
			return (0);
		if ((ft_tab_to_lst(argv, &stack)))
		{
			ft_putstr_fd("INIT\n", STDOUT);
			print_lsts(&stack);
			while ((!is_sorted_incorder(stack.a) || !is_empty(stack.b)) && cpt++ < argc * argc)
			{
				get_pos(&stack, pos);
				if (ft_lstsize(stack.a) > 1 && pos[A_1] > pos[A_2] &&
					ft_lstsize(stack.b) > 1 && pos[B_1] < pos[B_2])
					ss(&stack);
				if (ft_lstsize(stack.a) > 1 && pos[A_1] > pos[A_2])
					sa(&stack);
				else if (ft_lstsize(stack.b) > 1 && pos[B_1] < pos[B_2])
					sb(&stack);
				else if (is_empty(stack.b))
					pb(&stack);
				else if (ft_lstsize(stack.b) == 1)
				{
					pb(&stack);
					if (*(int *)stack.b->content < *(int *)stack.b->next->content)
						sb(&stack);
				}
				else if (!is_empty(stack.a))
				{
					if (*(int *)stack.a->content > *(int *)stack.b->content)
						pb(&stack);
					else if (*(int *)stack.a->content < *(int *)ft_lstlast(stack.b)->content)
					{
						pb(&stack);
						rb(&stack);
					}
					else
					{
						while (*(int *)stack.a->content < *(int *)stack.b->content)
							rb(&stack);
						if (!is_empty(stack.a))
							pb(&stack);
						while (!is_sorted_decorder(stack.b))
							rrb(&stack);
					}
				}
				if (is_empty(stack.a) ||
					(is_sorted_incorder(stack.a) && is_sorted_decorder(stack.b) && *(int *)stack.a->content > *(int *)stack.b->content))
				{
					while (!is_empty(stack.b))
						pa(&stack);
					break ;
				}
				/*
				//if (is_empty(stack.b) && is_sorted_incorder(stack.a))
				//	break ;	
				//int i = 0;
				while (i < 6)
					printf("%lld ", pos[i++]);
				printf("\n");
				if (pos[A_1] == max(pos) && pos[B_1] == min(pos) &&
					ft_lstsize(stack.a) > 1 && ft_lstsize(stack.b) > 1)
					rr(&stack);
				else if (pos[A_1] == max(pos) && ft_lstsize(stack.a) > 1)
					ra(&stack);
				else if (pos[B_1] == min(pos) && ft_lstsize(stack.b) > 1)
					rb(&stack);
				else if (pos[A_N] == min(pos) && pos[B_N] == max(pos) &&
					ft_lstsize(stack.a) > 1 && ft_lstsize(stack.b) > 1)
					rrr(&stack);
				else if (pos[A_N] == min(pos) && ft_lstsize(stack.a) > 1)
					rra(&stack);
				else if (pos[B_N] == max(pos) && ft_lstsize(stack.b) > 1)
					rrb(&stack);
				else if (pos[A_1] < (long long)INT_MAX + 1 && pos[A_2] < (long long)INT_MAX + 1 &&
					pos[B_1] < (long long)INT_MAX + 1 && pos[B_2] < (long long)INT_MAX + 1 &&
					pos[A_1] > pos[A_2] && pos[B_1] < pos[B_2])
					ss(&stack);
				else if (pos[A_1] < (long long)INT_MAX + 1 && pos[A_2] < (long long)INT_MAX + 1 &&
					pos[A_1] > pos[A_2])
					sa(&stack);
				else if (pos[B_1] < (long long)INT_MAX + 1 && pos[B_2] < (long long)INT_MAX + 1 &&
					pos[B_1] < pos[B_2])
					sb(&stack);
				//else if (pos[A_1] > pos[B_1] && !is_sorted_incorder(stack.a))
				//	pb(&stack);
				else if (is_sorted_incorder(stack.a) && is_sorted_decorder(stack.b))
					pa(&stack);
				else
				{
					pb(&stack);
					//ft_putstr_fd("break\n", STDERR);
					//break ;
				}
				//print_lsts(&stack);
				*/
			}
		}
		ft_putstr_fd("FINAL\n", STDOUT);
		print_lsts(&stack);
		clear_lsts(&stack);
	}
	return (0);
}
