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

typedef struct s_elem
{
	int	nb;
	int	idx;
	int	markup;
	int	nb_true;
	int	is_head;
}				t_elem;

typedef struct s_stack
{
	t_list		*a;
	t_list		*b;
	size_t		size;
}				t_stack;

typedef enum e_pos
{
	A_1,
	B_1,
	A_2,
	B_2,
	A_N,
	B_N
}				t_pos;

/* SORT */

void			ft_sort(t_stack *stack);
void			ft_sort3(t_stack *stack);

/* UTILS */

t_list			**ft_lstchangeval(t_list **lst, int index, int val);
int				is_empty(t_list *lst);
int				is_sorted_incorder(t_list *lst);
int				is_sorted_decorder(t_list *lst);
int				ft_islstmin(t_list *lst);
t_list			**ft_lstidxminloc(t_list **lst,
					t_elem *elem, int index, int val);
int				ft_rotate_a(t_stack *stack);
int				ft_rotate_order(t_list *lst);
int				ft_min_idx(t_list *lst);
int				ft_max_idx(t_list *lst);

/* CHECK_ARGS */

int				ft_is_rep(char **tab);
int				ft_is_not_int(char **tab);
int				ft_tab_to_lst(char **tab, t_stack *stack);

/* PRINT */

void			print_lst(t_list *lst);
void			print_lsts(t_stack *stack);

/* MARKUPS */

t_list			*ft_lstswaped(t_list *lst);
int				swap_is_needed(t_list *lst);
void			update_markups(t_list *lst);
int				count_false(t_list *lst);
int				get_markup(t_list *elem, t_list *head);
void			get_markups(t_list **lst);

/* OPERATIONS */

int				sa(t_stack *stack);
int				sb(t_stack *stack);
int				ss(t_stack *stack);
int				pa(t_stack *stack);
int				pb(t_stack *stack);
int				ra(t_stack *stack);
int				rb(t_stack *stack);
int				rr(t_stack *stack);
int				rra(t_stack *stack);
int				rrb(t_stack *stack);
int				rrr(t_stack *stack);

#endif
