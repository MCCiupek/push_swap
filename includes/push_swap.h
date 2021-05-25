/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:50:13 by mciupek           #+#    #+#             */
/*   Updated: 2021/05/12 19:50:14 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <unistd.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct	s_stack
{
	t_list		*a;
	t_list		*b;
	size_t	size;
}				t_stack;

int 		sa(t_stack *stack);
int 		sb(t_stack *stack);
int 		ss(t_stack *stack);

#endif