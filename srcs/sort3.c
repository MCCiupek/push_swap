/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:08:47 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/22 18:08:49 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_select_case(t_stack *stack)
{
	int	i[3];

	i[0] = ((t_elem *)stack->a->content)->idx;
	i[1] = ((t_elem *)stack->a->next->content)->idx;
	i[2] = ((t_elem *)stack->a->next->next->content)->idx;
	if (i[1] == ft_min_idx(stack->a) && i[2] == ft_max_idx(stack->a))
		return (1);
	if (i[0] == ft_max_idx(stack->a) && i[2] == ft_min_idx(stack->a))
		return (2);
	if (i[0] == ft_max_idx(stack->a) && i[1] == ft_min_idx(stack->a))
		return (3);
	if (i[0] == ft_min_idx(stack->a) && i[1] == ft_max_idx(stack->a))
		return (4);
	if (i[1] == ft_max_idx(stack->a) && i[2] == ft_min_idx(stack->a))
		return (5);
	return (0);
}

void	ft_sort3(t_stack *stack)
{
	int	n_case;

	n_case = ft_select_case(stack);
	//printf("case: %d\n", n_case);
	if (n_case == 1)
		sa(stack);
	if (n_case == 2)
	{
		sa(stack);
		rra(stack);
	}
	if (n_case == 3)
		ra(stack);
	if (n_case == 4)
	{
		sa(stack);
		ra(stack);
	}
	if (n_case == 5)
		rra(stack);
}
