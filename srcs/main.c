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

/*int	is_empty(int **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		if (tab[i++])
			return (1);
	return (0);
}

static int	is_sorted(int **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size - 1)
		if (tab[i - 1] > tab[i])
			return (0);
	return (1);
}*/

int	is_empty(t_list *lst)
{
	if (!ft_lstsize(lst))
		return (1);
	return (0);
}

static int	is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	int		ft_is_rep(char **tab)
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

static	int		ft_is_not_int(char **tab)
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

/*static int	ft_get_int_tab(char **tab, t_stack *stack)
{
	size_t	i;

	i = 0;
	if (ft_is_not_int(&tab[1]) || ft_is_rep(&tab[1]))
	{
		ft_putstr_fd("Error\n", STDERR);
		return (0);
	}
	while (i++ < stack->size)
	{
		stack->a[i - 1] = (int *)malloc(sizeof(int));
		*stack->a[i - 1] = ft_atoi(tab[i]);
	}
	return (1);
}*/

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
		ft_lstadd_front(&stack->a, ft_lstnew(nb));
	}
	return (1);
}

/*void	print_tab(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	printf("tab : ");
	while (i < size)
		printf("%d ", tab[i++]);
	printf("\n");
}*/

void	print_lst(t_list *lst)
{
	int	*nb;

	printf("lst : ");
	while (lst)
	{
		nb = (int *)lst->content;
		printf("%d ", *nb);
		lst = lst->next;
	}
	printf("\n");
}

/*void	print_tab_b(int **tab, size_t size)
{
	size_t	i;

	i = 0;
	printf("tab : ");
	while (i++ < size)
		if (tab[i - 1])
			printf("%d ", *tab[i - 1]);
		else
			printf("(null) ");
	printf("\n");
}*/

int init_stack(t_stack *stack, int size)
{
	stack->size = size - 1;
	stack->a = NULL;
	stack->b = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 1)
	{
		if (!init_stack(&stack, argc))
			return (0);
		if ((ft_tab_to_lst(argv, &stack)))
		{
			print_lst(stack.a);
			print_lst(stack.b);
			if (is_sorted(stack.a))
				ft_putstr_fd("a is sorted\n", STDOUT);
			if (is_empty(stack.b))
				ft_putstr_fd("b is empty\n", STDOUT);
			sa(&stack);
			print_lst(stack.a);
		}
	}
	return (0);
}
