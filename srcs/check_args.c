/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:34:58 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/16 10:35:00 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_rep(char **tab)
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

int	ft_is_not_int(char **tab)
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

int	ft_non_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (!ft_isdigit(tab[i][j]) && !(ft_strchr("+-", tab[i][j])
			&& ft_isdigit(tab[i][j + 1])))
			return (1);
		while (tab[i][++j])
			if (!ft_isdigit(tab[i][j]))
				return (1);
		i++;
	}
	return (0);
}

static void	init_a(char **tab, t_stack *stack)
{
	int		i;
	t_elem	*elem;

	i = 0;
	while (tab[i])
	{
		elem = (t_elem *)malloc(sizeof(t_elem));
		elem->nb = ft_atoi(tab[i++]);
		elem->idx = -1;
		ft_lstadd_back(&stack->a, ft_lstnew(elem));
	}
}

int	ft_tab_to_lst(char **tab, t_stack *stack)
{
	if (!tab || !tab[0][0])
		return (0);
	if (ft_is_not_int(tab) || ft_is_rep(tab)
		|| ft_non_digit(tab))
	{
		ft_putstr_fd("Error\n", STDERR);
		return (0);
	}
	if (ft_arraysize(tab) < 2)
		return (0);
	init_a(tab, stack);
	if (is_sorted_incorder(stack->a))
	{
		ft_lstclear(&stack->a, free);
		return (0);
	}
	return (1);
}
